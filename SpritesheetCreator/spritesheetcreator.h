#ifndef SPRITESHEETCREATOR_H
#define SPRITESHEETCREATOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SpritesheetCreator; }
QT_END_NAMESPACE

class Tiling {
public:
    int Rows = 0;
    int Columns = 0;
};

class SpritesheetCreator : public QMainWindow
{
    Q_OBJECT

public:
    SpritesheetCreator(QWidget *parent = nullptr);
    ~SpritesheetCreator();

private slots:
    void load_images();
    void add_images_to_table(QStringList list_of_files);
    bool eventFilter(QObject* obj, QEvent* event);
    void calculate_sheet_size();
    void rows_and_columns_logic();

    // Actions in the bar
    void on_actionClear_All_triggered();
    void on_actionLoad_Files_changed();
    void on_actionSpritesheet_Preview_changed();

private:
    Ui::SpritesheetCreator *ui;
    Tiling* Tiles;
};
#endif // SPRITESHEETCREATOR_H
