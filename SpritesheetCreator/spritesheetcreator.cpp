#include "spritesheetcreator.h"
#include "ui_spritesheetcreator.h"
#include <QFileDialog>
#include <filesystem>
#include <QDropEvent>
#include <QFileInfo>
#include <QMimeData>

SpritesheetCreator::SpritesheetCreator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpritesheetCreator)
{
    ui->setupUi(this);
    // Initialize elements
    ui->ImageTable->setColumnCount(2);
    ui->ImageTable->setColumnHidden(1, true);
    ui->ImageTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->ImageTable->horizontalHeader()->hide();
    ui->ImageTable->viewport()->installEventFilter(this);

    // Connections to buttons
    connect(ui->AddImagesButton, SIGNAL(clicked(bool)), this, SLOT(load_images()));
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


