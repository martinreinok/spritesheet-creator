#include "spritesheetcreator.h"
#include "ui_spritesheetcreator.h"
#include <QFileDialog>
#include <filesystem>
#include <QDropEvent>
#include <QFileInfo>
#include <QFileDialog>
#include <QMimeData>
#include <QVector>
#include <vector>
#include <string>
#include <algorithm>
#include <QMessageBox>
#include <cmath>
#include <QImage>
#include <string>
#include <sstream>
// #include <Qt>

SpritesheetCreator::SpritesheetCreator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpritesheetCreator)
{
    ui->setupUi(this);
    // Classes
    Tiles = new Tiling();
    ImageProcessing = new ImageProcessor();

    // Initialize elements
    ui->ImageTable->setColumnCount(2);
    ui->ImageTable->setColumnHidden(1, true);
    ui->ImageTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->ImageTable->horizontalHeader()->hide();
    ui->ImageTable->viewport()->installEventFilter(this);
    ui->TilingConstant->addItem("Columns");
    ui->TilingConstant->addItem("Rows");
    this->lastUsedDirectory = QDir::homePath();

    // Graphics
    graphics_scene = new QGraphicsScene();
    graphics_scene->setBackgroundBrush(QColor(220, 220, 220));
    ui->SpritesheetPreview->setScene(graphics_scene);
    ui->SpritesheetPreview->show();


    // Connections to buttons
    connect(ui->AddImagesButton, SIGNAL(clicked(bool)), this, SLOT(load_images()));
    connect(ui->TilingNumber, SIGNAL(textChanged(QString)), this, SLOT(rows_and_columns_logic()));
    connect(ui->TilingConstant, SIGNAL(currentTextChanged(QString)), this, SLOT(rows_and_columns_logic()));
    connect(ui->ImageTable, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(rows_and_columns_logic()));
    connect(ui->SaveSpritesheetButton, SIGNAL(clicked(bool)), this, SLOT(save_button()));
    // UpdatePreview
    connect(ui->TilingNumber, SIGNAL(textChanged(QString)), this, SLOT(show_spritesheet_preview()));
    connect(ui->TilingConstant, SIGNAL(currentTextChanged(QString)), this, SLOT(show_spritesheet_preview()));


    rows_and_columns_logic();
}

SpritesheetCreator::~SpritesheetCreator()
{
    delete Tiles;
    delete ui;
}

void SpritesheetCreator::load_images()
{
    QString accepted_files = "Image Files (*.PNG *.BMP *.JPG);;All Files (*)";
    QFileDialog select_files;
    select_files.setFileMode(QFileDialog::ExistingFiles);
    QStringList files = select_files.getOpenFileNames(this, "Image Sequence or Folder", "", accepted_files);
    qDebug() << files;
    add_images_to_table(files);
}

void SpritesheetCreator::error_messagebox(const QString& error_message) {
    QMessageBox error_box;
    error_box.setIcon(QMessageBox::Critical);
    error_box.setWindowTitle("Error");
    error_box.setText("An error has occurred:");
    error_box.setInformativeText(error_message);
    error_box.exec();
}

void SpritesheetCreator::add_images_to_table(QStringList list_of_files)
{
    int current_table_rows = ui->ImageTable->rowCount();
    for (int i = 0; i < list_of_files.size(); i++){
        ui->ImageTable->insertRow(current_table_rows + i);
        std::filesystem::path file_full_path = list_of_files[i].toStdString();
        std::string file_name = file_full_path.filename().string();
        QTableWidgetItem *qt_file_name = new QTableWidgetItem;
        QTableWidgetItem *qt_file_full_path = new QTableWidgetItem;
        qt_file_name->setText(QString::fromStdString(file_name));
        qt_file_full_path->setText(QString::fromStdString(file_full_path.string()));
        ui->ImageTable->setItem(current_table_rows + i, 0, qt_file_name);
        ui->ImageTable->setItem(current_table_rows + i, 1, qt_file_full_path);
    }
    this->show_spritesheet_preview(); // Also update preview
}

bool SpritesheetCreator::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == ui->ImageTable->viewport() && event->type() == QEvent::DragEnter){
        QDragEnterEvent* drag_event = static_cast<QDragEnterEvent*>(event);
        if (drag_event->mimeData()->hasUrls()){
            drag_event->acceptProposedAction();
            return true;
        }
    }

    if (obj == ui->ImageTable->viewport() && event->type() == QEvent::DragMove){
        QDragMoveEvent* drag_event = static_cast<QDragMoveEvent*>(event);
        if (drag_event->mimeData()->hasUrls()){
            drag_event->acceptProposedAction();
            return true;
        }
    }

    if (obj == ui->ImageTable->viewport() && event->type() == QEvent::Drop)
    {
        QDropEvent* drop_event = static_cast<QDropEvent*>(event);
        const QMimeData* mime_data = drop_event->mimeData();
        if (mime_data->hasUrls()){
            QList<QUrl> file_urls = mime_data->urls();
            QStringList file_paths_list;
            for (const QUrl& url : file_urls)
            {
                QString file_path = url.toLocalFile();
                file_paths_list.append(file_path);
            }
            std::sort(file_paths_list.begin(), file_paths_list.end(), [](const QString& a, const QString& b)
                      {
                          return QFileInfo(a).fileName() < QFileInfo(b).fileName();
                      });
            qDebug() << "Sorted\n" << file_paths_list;
            add_images_to_table(file_paths_list);
            return true;
        }
    }
    return obj->eventFilter(obj, event);
}

void SpritesheetCreator::calculate_sheet_size()
{
    double images_amount = ui->ImageTable->rowCount();
    double tiling_number = ui->TilingNumber->value();
    qDebug() << "Rows: " << Tiles->Rows;
    if (ui->TilingConstant->currentText() == "Columns"){
        Tiles->Columns = tiling_number;
        Tiles->Rows = std::max((int) std::ceil(images_amount/Tiles->Columns), 1);
    }
    else {
        Tiles->Rows = tiling_number;
        Tiles->Columns = std::max((int) std::ceil(images_amount/Tiles->Rows), 1);
    }
}

void SpritesheetCreator::rows_and_columns_logic()
{
    calculate_sheet_size();
    if (ui->TilingConstant->currentText() == "Columns"){
        QString newtext = QString::number(Tiles->Rows) + " Rows";
        ui->TilingOtherNumber->setText(newtext);
    }
    else {
        QString newtext = QString::number(Tiles->Columns) + " Columns";
        ui->TilingOtherNumber->setText(newtext);
    }
}

void SpritesheetCreator::save_button()
{
    QVector<cv::Mat> opencv_images = ImageProcessing->get_images_from_table(ui->ImageTable);
    qDebug() << opencv_images.length();
    bool images_are_same_size = ImageProcessing->validate_image_size(opencv_images);
    if (!images_are_same_size){
        error_messagebox("Images are not the same size!");
        return;
    }
    cv::Mat spritesheet = ImageProcessing->create_spritesheet(Tiles->Rows, Tiles->Columns, opencv_images);
    if (spritesheet.empty()) { return; }

    QFileDialog file_dialog;
    QString filename;
    std::ostringstream suggested_file_name_strstream;
    suggested_file_name_strstream << "spritesheet" << "_[name]_" << Tiles->Rows << "x" << Tiles->Columns << "_" << opencv_images.length() << "f" << "_" << opencv_images[0].size[0] << "x" << opencv_images[0].size[1];
    QString suggested_file_name = this->lastUsedDirectory.filePath(QString::fromStdString(suggested_file_name_strstream.str()));

    if (ImageProcessing->doImagesHaveAlphaChannel(opencv_images)) {
        filename = file_dialog.getSaveFileName(this, "Save file", suggested_file_name, "PNG (*.png)");
    }
    else {
        filename = file_dialog.getSaveFileName(this, "Save file", suggested_file_name, "JPG (*.jpg)");
    }

    if (filename.isEmpty()) { return; }

    // Update the last used directory to the selected path
    this->lastUsedDirectory = QFileInfo(filename).absolutePath();

    ImageProcessing->opencv_save_image(spritesheet, filename);
}

void SpritesheetCreator::show_spritesheet_preview() {
    // https://stackoverflow.com/questions/45724457/c-opencv-mat-to-qpixmap-errors
    ui->SpritesheetPreview->viewport()->update();
    graphics_scene->clear();

    if (ui->PreviewCheckbox->isChecked() && ui->ShowPreviewCheckbox->isChecked()) {
        QVector<cv::Mat> opencv_images = ImageProcessing->get_images_from_table(ui->ImageTable);
        bool images_are_same_size = ImageProcessing->validate_image_size(opencv_images);
        if (!images_are_same_size) { return; }

        cv::Mat spritesheet;
        try {
            spritesheet = ImageProcessing->create_spritesheet(Tiles->Rows, Tiles->Columns, opencv_images, 4);
        }
        catch (...) {
            qDebug() << "Preview failed";
        }
        if (spritesheet.empty()) { return; }

        cv::Mat converted_spritesheet;
        cv::cvtColor(spritesheet, converted_spritesheet, cv::COLOR_BGRA2RGB);

        const uchar *qImageBuffer = (const uchar*)converted_spritesheet.data;

        QImage img(qImageBuffer, converted_spritesheet.cols,
                   converted_spritesheet.rows,
                   converted_spritesheet.step, QImage::Format_RGB888);

        QPixmap pixmap;
        pixmap = QPixmap::fromImage(img);
        graphics_scene->setSceneRect(pixmap.rect());
        graphics_scene->addPixmap(pixmap);
        ui->SpritesheetPreview->setScene(graphics_scene);
        ui->SpritesheetPreview->setResizeAnchor(ui->SpritesheetPreview->AnchorViewCenter);
        ui->SpritesheetPreview->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ui->SpritesheetPreview->fitInView(graphics_scene->sceneRect(), Qt::AspectRatioMode::KeepAspectRatio);
        ui->SpritesheetPreview->show();
    }
}

void SpritesheetCreator::on_actionClear_All_triggered()
{
    ui->ImageTable->setRowCount(0);
}

void SpritesheetCreator::on_actionLoad_Files_changed()
{
    if(ui->actionLoad_Files->isChecked()){
        ui->LoadFilesDock->setVisible(true);
    }
    else {
        ui->LoadFilesDock->setVisible(false);
    }
}

void SpritesheetCreator::on_actionSpritesheet_Preview_changed()
{
    if(ui->actionSpritesheet_Preview->isChecked()){
        ui->PreviewDock->setVisible(true);
    }
    else {
        ui->PreviewDock->setVisible(false);
    }
}
