#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>
#include <iostream>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cam1=new Image();
    //cam2=new Image();
    cam1->setCameraNum(1);
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


    cam1->takePicture(ui->bSlider->value()/100.0,ui->wSlider->value()/100.0);
    //cam2->takePicture();
    cam1->processImage();

    //cam2->processImage();
    cam1->displayImage(*ui->src_a);
    //cam2->displayImage(*ui->src_b);
    //cam1->processImage(cam2->getSrc());
    cam1->displayImage(*ui->imageout);
    ;
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
