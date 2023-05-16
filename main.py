from PyQt5 import QtWidgets, QtCore, QtGui
from GUI import Ui_MainWindow
import sys
import math
import numpy as np
import cv2
import os


class ApplicationWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(ApplicationWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        # image

        # Table drag-drop
        self.table = self.ui.ImageTable
        self.table.viewport().installEventFilter(self)

        # TilesOrRows selector
        self.ui.TilingConstant.addItem("Columns")
        self.ui.TilingConstant.addItem("Rows")
        self.rows_and_columns_logic()

        # Graphics
        self.graphics_scene = QtWidgets.QGraphicsScene()
        self.graphics_scene.setBackgroundBrush(QtGui.QColor(220, 220, 220))

        self.graphics_view = self.ui.SpritesheetPreview
        self.graphics_view.setScene(self.graphics_scene)
        self.graphics_view.show()

    @staticmethod
    def error_messagebox(error_message):
        error_box = QtWidgets.QMessageBox()
        error_box.setIcon(QtWidgets.QMessageBox.Critical)
        error_box.setWindowTitle("Error")
        error_box.setText("An error has occurred:")
        error_box.setInformativeText(error_message)
        error_box.exec_()

    def load_images(self):
        accepted_files = "Image Files (*.PNG *.BMP);;All Files (*)"
        select_files = QtWidgets.QFileDialog()
        select_files.setFileMode(QtWidgets.QFileDialog.AnyFile)
        files, _ = select_files.getOpenFileNames(self, "Image Sequence or Folder", "", f"{accepted_files}")
        print(files)
        self.add_images_to_table(files)
        return files

    def add_images_to_table(self, image_files):
        """
        First Column is show to user
        Second column is full path to the image
        """
        self.table.setColumnCount(2)
        self.table.setColumnHidden(1, True)
        header = self.table.horizontalHeader()
        header.setSectionResizeMode(0, QtWidgets.QHeaderView.Stretch)
        start_index = self.table.rowCount()
        for index, file_path in enumerate(image_files):
            self.table.insertRow(start_index + index)
            file_name = os.path.basename(file_path)
            self.table.setItem(start_index + index, 0, QtWidgets.QTableWidgetItem(file_name))
            self.table.setItem(start_index + index, 1, QtWidgets.QTableWidgetItem(file_path))

    @QtCore.pyqtSlot(QtCore.QPoint)
    def on_customContextMenuRequested(self, pos):
        it = self.table.itemAt(pos)
        if it is None:
            return
        r = it.row()
        c = it.column()
        item_range = QtWidgets.QTableWidgetSelectionRange(r, c, r, c)
        self.table.setRangeSelected(item_range, True)
        menu = QtWidgets.QMenu()
        delete_item_action = menu.addAction("Delete item")
        action = menu.exec_(self.table.viewport().mapToGlobal(pos))
        if action == delete_item_action:
            self.table.removeRow(r)

    # Drag and Drop event
    def eventFilter(self, source, event):
        if (source is self.table.viewport() and
                (event.type() == QtCore.QEvent.Type.DragEnter or
                 event.type() == QtCore.QEvent.Type.DragMove or
                 event.type() == QtCore.QEvent.Type.Drop) and
                event.mimeData().hasUrls()):
            if event.type() == QtCore.QEvent.Type.Drop:
                for url in event.mimeData().urls():
                    if url.isLocalFile():
                        file_path = url.path()[1:]
                        print(file_path)
                        self.add_images_to_table([file_path])
            event.accept()
            return True
        return super().eventFilter(source, event)

    def create_spritesheet(self, preview=False):
        # Pull all images from the QtTable
        images = []
        for row in range(self.table.rowCount()):
            images.append(cv2.imread(self.table.item(row, 1).text(), cv2.IMREAD_UNCHANGED))

        if not images:
            if not preview:
                self.error_messagebox("Images are missing!")
            return

        # Make sure the image dimensions match
        if len(set([image.shape for image in images])) > 1:
            if not preview:
                self.error_messagebox("Images are not the same size!")
            return

        image_height, image_width, _ = images[0].shape

        # Calculate the number of rows and total width of the spritesheet
        if int(self.ui.TilingNumber.text()) == 0:
            if not preview:
                self.error_messagebox("Change the column or row size!")
            return

        rows, cols = self.calculate_sheet_size()

        # Create a blank spritesheet canvas with transparency
        spritesheet = np.zeros((image_height * rows, image_width * cols, 4), dtype=np.uint8)
        spritesheet[:, :, 3] = 0  # Set the alpha channel to fully opaque

        # Combine images into the spritesheet
        for i, image in enumerate(images):
            row = i // cols
            col = i % cols

            # Calculate the position to place the current image
            x = col * image_width
            y = row * image_height

            # Paste the image
            spritesheet[y:y + image_height, x:x + image_width, :3] = image[:, :, :3]  # Copy RGB channels
            spritesheet[y:y + image_height, x:x + image_width, 3] = image[:, :, 3]  # Copy alpha channel

        if not preview:
            # Save the spritesheet to disk
            save_dialog = QtWidgets.QFileDialog()
            save_dialog.setAcceptMode(QtWidgets.QFileDialog.AcceptSave)
            file_destination, _ = save_dialog.getSaveFileName(self, "Save File", "", "PNG (*.png)")

            if file_destination:
                print(file_destination)
                cv2.imwrite(file_destination, spritesheet)
            else:
                print("Cancelled")
        else:
            return spritesheet

    def calculate_sheet_size(self):
        """
        :return: rows, cols
        """
        images_amount = self.table.rowCount()
        # Minimum is 1 to avoid division by 0
        tiling_number = max(int(self.ui.TilingNumber.text()), 1)
        if self.ui.TilingConstant.currentText() == "Columns":
            cols = tiling_number
            rows = math.ceil(images_amount / cols)
        else:
            rows = tiling_number
            cols = math.ceil(images_amount / rows)
        return rows, cols

    def rows_and_columns_logic(self):
        current = self.ui.TilingConstant.currentText()
        rows, cols = self.calculate_sheet_size()
        print(rows, cols)
        if current == "Columns":
            self.ui.TilingOtherNumber.setText(f"{rows} Rows")
        else:
            self.ui.TilingOtherNumber.setText(f"{cols} Columns")

    def show_spritesheet_preview(self):
        # If there are images in the table and there is a size for the spritesheet, show the preview
        rows, cols = self.calculate_sheet_size()
        # Update scene and view
        self.graphics_view.viewport().update()
        self.graphics_scene.clear()
        if rows > 0 and cols > 0:
            # show preview
            if self.ui.ShowPreviewCheckbox.isEnabled() and self.ui.ShowPreviewCheckbox.isChecked():
                temporary_spritesheet = self.create_spritesheet(preview=True)
                if temporary_spritesheet is not None:
                    temporary_spritesheet = cv2.cvtColor(temporary_spritesheet, cv2.COLOR_BGR2RGB)
                    scene_image = QtGui.QImage(temporary_spritesheet.data, temporary_spritesheet.shape[1],
                                               temporary_spritesheet.shape[0], QtGui.QImage.Format.Format_RGB888)
                    pixmap = QtGui.QPixmap.fromImage(scene_image)
                    # Add the image to the QGraphicsScene
                    self.graphics_scene.addPixmap(pixmap)

                    self.graphics_scene.setSceneRect(QtCore.QRectF(pixmap.rect()))
                    self.graphics_view.setResizeAnchor(self.graphics_view.AnchorViewCenter)
                    self.graphics_view.setAlignment(QtCore.Qt.AlignmentFlag.AlignCenter)
                    self.graphics_view.fitInView(self.graphics_scene.sceneRect(),
                                                 QtCore.Qt.AspectRatioMode.KeepAspectRatio)


def main():
    app = QtWidgets.QApplication(sys.argv)
    GUI = ApplicationWindow()

    # Method Connections
    GUI.ui.AddImagesButton.clicked.connect(GUI.load_images)
    GUI.table.customContextMenuRequested.connect(GUI.on_customContextMenuRequested)
    GUI.ui.TilingNumber.textChanged.connect(GUI.rows_and_columns_logic)
    GUI.ui.TilingConstant.currentTextChanged.connect(GUI.rows_and_columns_logic)
    GUI.ui.SaveSpritesheetButton.clicked.connect(GUI.create_spritesheet)
    GUI.ui.TilingNumber.textChanged.connect(GUI.show_spritesheet_preview)
    GUI.ui.TilingConstant.currentTextChanged.connect(GUI.show_spritesheet_preview)

    # Show the GUI
    GUI.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
