#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv/cv.hpp>
#include <opencv/highgui.h>

#include <QTimer>
#include "image.h"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void displayFrame();

    void on_bobButton_clicked();

private:
    Ui::MainWindow *ui;
    Image* cam1,*cam2;

};

#endif // MAINWINDOW_H
