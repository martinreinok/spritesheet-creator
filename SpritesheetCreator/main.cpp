#include "spritesheetcreator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpritesheetCreator w;
    w.show();
    return a.exec();
}
