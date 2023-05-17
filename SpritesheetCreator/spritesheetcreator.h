#ifndef SPRITESHEETCREATOR_H
#define SPRITESHEETCREATOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SpritesheetCreator; }
QT_END_NAMESPACE

class SpritesheetCreator : public QMainWindow
{
    Q_OBJECT

public:
    SpritesheetCreator(QWidget *parent = nullptr);
    ~SpritesheetCreator();

private slots:
    void load_images();
    void add_images_to_table(QStringList list_of_files);

private:
    Ui::SpritesheetCreator *ui;
    QTableWidget *table;
};
#endif // SPRITESHEETCREATOR_H
