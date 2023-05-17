#include "spritesheetcreator.h"
#include "ui_spritesheetcreator.h"
#include <QFileDialog>
#include <filesystem>

SpritesheetCreator::SpritesheetCreator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpritesheetCreator)
{
    ui->setupUi(this);
    // Initialize elements
    ui->ImageTable->viewport()->installEventFilter(this);

    // Connections to buttons
    connect(ui->AddImagesButton, &QPushButton::clicked, this, &SpritesheetCreator::load_images);
}

SpritesheetCreator::~SpritesheetCreator()
{
    delete ui;
}

void SpritesheetCreator::load_images()
{
    QString accepted_files = "Image Files (*.PNG *.BMP);;All Files (*)";
    QFileDialog select_files;
    select_files.setFileMode(QFileDialog::ExistingFiles);
    QStringList files = select_files.getOpenFileNames(this, "Image Sequence or Folder", "", accepted_files);
    qDebug() << files;
    add_images_to_table(files);
}

void SpritesheetCreator::add_images_to_table(QStringList list_of_files)
{
    ui->ImageTable->setColumnCount(2);
    ui->ImageTable->setColumnHidden(1, true);
    ui->ImageTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
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
}
