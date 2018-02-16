#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>
#include <iostream>
#include <ctime>
#include "constants.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cam1=new Image();
    //cam2=new Image();
    cam1->setCameraNum(CAMERA_NUM);
    //cam2->setCameraNum(2);
    QTimer *qTimer = new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(displayFrame()));
    qTimer->start(10);
    ui->imageout->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    //cam.release();
}

void MainWindow::displayFrame(){

    if (USE_CAMERA) {
        cam1->takePicture(ui->whiteBal_s->value()/100.0,ui->focus_s->value()/100.0);
        //cam2->takePicture();

    } else {
        cam1->readFromFile(DATA_DIRECTORY);
    }
    cam1->thresh1=ui->thresh1_s->value();
    cam1->thresh2=ui->thresh2_s->value();
    cam1->processImage();

    //cam2->processImage();
    cam1->displayImage(*ui->src_a);
    //cam2->displayImage(*ui->src_b);
    //cam1->processImage(cam2->getSrc());
    cam1->displayImage(*ui->imageout);

    // TODO sleep
}


void MainWindow::on_bobButton_clicked()
{
    std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(p);
    std::string fname="~/chromaScreen/snapshot_";
    fname.append(std::to_string((long)std::clock()));//std::ctime(&t));
    fname.append(".png");
    std::cout<<fname.c_str()<<std::endl;
    imwrite(fname.c_str(),cam1->getIm());
}
