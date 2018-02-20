#include "mainwindow.h"
#include <QApplication>
#include "coord.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Coord::unitTest();
    w.show();

    return a.exec();
}
