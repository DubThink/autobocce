#ifndef IMAGE_H
#define IMAGE_H

#include <opencv/cv.hpp>
#include <opencv/highgui.h>


#include <QLabel>
#include <QMainWindow>
#include <QtCore>

using namespace cv;

class Image
{
public:
    Image();
    void setCameraNum(int i);
    void takePicture();
    QImage convertToQImage();
    void displayImage(QLabel &location);
    void processImage(Mat& other);
    void processImage();
    Mat& getSrc();
    Mat& getIm();
    static void invert(Mat& mat);
    static void sobel(Mat& in,Mat& out, int dx, int dy);
    static void sobelh(Mat& in,Mat& out);
    static void sobelv(Mat& in,Mat& out);
    static void absdv(Mat& in,Mat& out);
    static void threshold(Mat& in, Mat& out,int thresh);
    int wThresh=30;
    int bThresh=300;
    void takePicture(double focus,double exposure);
private:
    Mat src;
    Mat display;
    Mat im;
    VideoCapture cam;
    int ctr=0;
};

#endif // IMAGE_H
