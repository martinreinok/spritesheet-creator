# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\QtDesign.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(274, 540)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("C:/Users/Cs/Downloads/spritesheet-creator.ico"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        MainWindow.setWindowIcon(icon)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setEnabled(True)
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName("horizontalLayout")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 274, 23))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        self.menuEdit = QtWidgets.QMenu(self.menubar)
        self.menuEdit.setObjectName("menuEdit")
        self.menuView = QtWidgets.QMenu(self.menubar)
        self.menuView.setObjectName("menuView")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.LoadFilesDock = QtWidgets.QDockWidget(MainWindow)
        self.LoadFilesDock.setContextMenuPolicy(QtCore.Qt.DefaultContextMenu)
        self.LoadFilesDock.setFloating(False)
        self.LoadFilesDock.setFeatures(QtWidgets.QDockWidget.AllDockWidgetFeatures)
        self.LoadFilesDock.setObjectName("LoadFilesDock")
        self.LoadFiles_2 = QtWidgets.QWidget()
        self.LoadFiles_2.setObjectName("LoadFiles_2")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.LoadFiles_2)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.AddImagesButton = QtWidgets.QPushButton(self.LoadFiles_2)
        self.AddImagesButton.setObjectName("AddImagesButton")
        self.verticalLayout.addWidget(self.AddImagesButton)
        self.label = QtWidgets.QLabel(self.LoadFiles_2)
        self.label.setMinimumSize(QtCore.QSize(0, 0))
        self.label.setMaximumSize(QtCore.QSize(16777215, 10))
        font = QtGui.QFont()
        font.setPointSize(6)
        self.label.setFont(font)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.ImageTable = QtWidgets.QTableWidget(self.LoadFiles_2)
        self.ImageTable.setContextMenuPolicy(QtCore.Qt.CustomContextMenu)
        self.ImageTable.setAcceptDrops(True)
        self.ImageTable.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.ImageTable.setAutoScrollMargin(2)
        self.ImageTable.setDragEnabled(False)
        self.ImageTable.setDragDropOverwriteMode(False)
        self.ImageTable.setDragDropMode(QtWidgets.QAbstractItemView.DropOnly)
        self.ImageTable.setAlternatingRowColors(True)
        self.ImageTable.setSelectionMode(QtWidgets.QAbstractItemView.SingleSelection)
        self.ImageTable.setSelectionBehavior(QtWidgets.QAbstractItemView.SelectRows)
        self.ImageTable.setObjectName("ImageTable")
        self.ImageTable.setColumnCount(0)
        self.ImageTable.setRowCount(0)
        self.verticalLayout.addWidget(self.ImageTable)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        self.LoadFilesDock.setWidget(self.LoadFiles_2)
        MainWindow.addDockWidget(QtCore.Qt.DockWidgetArea(1), self.LoadFilesDock)
        self.ImagePreviewDock = QtWidgets.QDockWidget(MainWindow)
        self.ImagePreviewDock.setObjectName("ImagePreviewDock")
        self.dockWidgetContents_4 = QtWidgets.QWidget()
        self.dockWidgetContents_4.setObjectName("dockWidgetContents_4")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.dockWidgetContents_4)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.SpritesheetPreview = QtWidgets.QGraphicsView(self.dockWidgetContents_4)
        self.SpritesheetPreview.setAcceptDrops(False)
        self.SpritesheetPreview.setAutoFillBackground(False)
        self.SpritesheetPreview.setObjectName("SpritesheetPreview")
        self.verticalLayout_3.addWidget(self.SpritesheetPreview)
        self.Tiling = QtWidgets.QGroupBox(self.dockWidgetContents_4)
        self.Tiling.setObjectName("Tiling")
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout(self.Tiling)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.TilingConstant = QtWidgets.QComboBox(self.Tiling)
        self.TilingConstant.setEditable(False)
        self.TilingConstant.setCurrentText("")
        self.TilingConstant.setObjectName("TilingConstant")
        self.verticalLayout_4.addWidget(self.TilingConstant)
        self.TilingNumber = QtWidgets.QSpinBox(self.Tiling)
        self.TilingNumber.setSuffix("")
        self.TilingNumber.setObjectName("TilingNumber")
        self.verticalLayout_4.addWidget(self.TilingNumber)
        self.horizontalLayout_4.addLayout(self.verticalLayout_4)
        self.line_2 = QtWidgets.QFrame(self.Tiling)
        self.line_2.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        self.horizontalLayout_4.addWidget(self.line_2)
        self.TilingOtherNumber = QtWidgets.QLineEdit(self.Tiling)
        self.TilingOtherNumber.setMaximumSize(QtCore.QSize(100, 16777215))
        self.TilingOtherNumber.setBaseSize(QtCore.QSize(0, 0))
        self.TilingOtherNumber.setInputMask("")
        self.TilingOtherNumber.setText("")
        self.TilingOtherNumber.setReadOnly(True)
        self.TilingOtherNumber.setClearButtonEnabled(False)
        self.TilingOtherNumber.setObjectName("TilingOtherNumber")
        self.horizontalLayout_4.addWidget(self.TilingOtherNumber)
        self.verticalLayout_3.addWidget(self.Tiling)
        self.line = QtWidgets.QFrame(self.dockWidgetContents_4)
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.verticalLayout_3.addWidget(self.line)
        self.PreviewCheckbox = QtWidgets.QGroupBox(self.dockWidgetContents_4)
        self.PreviewCheckbox.setCheckable(True)
        self.PreviewCheckbox.setObjectName("PreviewCheckbox")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.PreviewCheckbox)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.ShowPreviewCheckbox = QtWidgets.QCheckBox(self.PreviewCheckbox)
        self.ShowPreviewCheckbox.setChecked(True)
        self.ShowPreviewCheckbox.setObjectName("ShowPreviewCheckbox")
        self.horizontalLayout_2.addWidget(self.ShowPreviewCheckbox)
        self.AnimateCheckbox = QtWidgets.QCheckBox(self.PreviewCheckbox)
        self.AnimateCheckbox.setEnabled(False)
        self.AnimateCheckbox.setChecked(False)
        self.AnimateCheckbox.setObjectName("AnimateCheckbox")
        self.horizontalLayout_2.addWidget(self.AnimateCheckbox)
        self.FPSSelector = QtWidgets.QSpinBox(self.PreviewCheckbox)
        self.FPSSelector.setEnabled(False)
        self.FPSSelector.setWrapping(False)
        self.FPSSelector.setProperty("showGroupSeparator", False)
        self.FPSSelector.setMaximum(1000)
        self.FPSSelector.setProperty("value", 10)
        self.FPSSelector.setObjectName("FPSSelector")
        self.horizontalLayout_2.addWidget(self.FPSSelector)
        self.horizontalLayout_3.addLayout(self.horizontalLayout_2)
        self.verticalLayout_3.addWidget(self.PreviewCheckbox)
        self.line_3 = QtWidgets.QFrame(self.dockWidgetContents_4)
        self.line_3.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_3.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_3.setObjectName("line_3")
        self.verticalLayout_3.addWidget(self.line_3)
        self.SaveSpritesheetButton = QtWidgets.QPushButton(self.dockWidgetContents_4)
        self.SaveSpritesheetButton.setMinimumSize(QtCore.QSize(0, 30))
        self.SaveSpritesheetButton.setObjectName("SaveSpritesheetButton")
        self.verticalLayout_3.addWidget(self.SaveSpritesheetButton)
        self.ImagePreviewDock.setWidget(self.dockWidgetContents_4)
        MainWindow.addDockWidget(QtCore.Qt.DockWidgetArea(1), self.ImagePreviewDock)
        self.actionOpen = QtWidgets.QAction(MainWindow)
        self.actionOpen.setObjectName("actionOpen")
        self.actionDelete_Images = QtWidgets.QAction(MainWindow)
        self.actionDelete_Images.setObjectName("actionDelete_Images")
        self.actionClear_All = QtWidgets.QAction(MainWindow)
        self.actionClear_All.setObjectName("actionClear_All")
        self.actionDelete_Images_2 = QtWidgets.QAction(MainWindow)
        self.actionDelete_Images_2.setObjectName("actionDelete_Images_2")
        self.actionLoad_Files = QtWidgets.QAction(MainWindow)
        self.actionLoad_Files.setCheckable(True)
        self.actionLoad_Files.setChecked(True)
        self.actionLoad_Files.setObjectName("actionLoad_Files")
        self.actionSheet_Preview = QtWidgets.QAction(MainWindow)
        self.actionSheet_Preview.setCheckable(True)
        self.actionSheet_Preview.setChecked(True)
        self.actionSheet_Preview.setObjectName("actionSheet_Preview")
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionClear_All)
        self.menuEdit.addAction(self.actionDelete_Images_2)
        self.menuView.addAction(self.actionLoad_Files)
        self.menuView.addAction(self.actionSheet_Preview)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuEdit.menuAction())
        self.menubar.addAction(self.menuView.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Spritesheet Creator"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.menuEdit.setTitle(_translate("MainWindow", "Edit"))
        self.menuView.setTitle(_translate("MainWindow", "View"))
        self.LoadFilesDock.setWindowTitle(_translate("MainWindow", "Load Files"))
        self.AddImagesButton.setText(_translate("MainWindow", "Add Images"))
        self.label.setText(_translate("MainWindow", "(Or Drag and Drop)"))
        self.ImageTable.setSortingEnabled(False)
        self.ImagePreviewDock.setWindowTitle(_translate("MainWindow", "Sheet Preview"))
        self.Tiling.setTitle(_translate("MainWindow", "Tiling"))
        self.PreviewCheckbox.setTitle(_translate("MainWindow", "Preview"))
        self.ShowPreviewCheckbox.setText(_translate("MainWindow", "Show"))
        self.AnimateCheckbox.setText(_translate("MainWindow", "Animate"))
        self.FPSSelector.setSuffix(_translate("MainWindow", " FPS"))
        self.SaveSpritesheetButton.setText(_translate("MainWindow", "Save"))
        self.actionOpen.setText(_translate("MainWindow", "Add Images"))
        self.actionDelete_Images.setText(_translate("MainWindow", "Delete Images"))
        self.actionClear_All.setText(_translate("MainWindow", "Clear All"))
        self.actionDelete_Images_2.setText(_translate("MainWindow", "Delete Images"))
        self.actionLoad_Files.setText(_translate("MainWindow", "Load Files"))
        self.actionSheet_Preview.setText(_translate("MainWindow", "Sheet Preview"))
