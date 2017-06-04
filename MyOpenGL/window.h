// window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "opencv2/opencv.hpp"

#include "opencv2/highgui.hpp"
#include<QLabel>
using namespace cv;

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
private slots:
    void update();
    void on_checkBox_clicked();
    void trackingRect();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Window *ui;
    QTimer *timer = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    //Reconnaissance main
    int templateWidth = 60;
    int templateHeight = 60;
    Rect *templateRect;
    VideoCapture * cam;
    Mat templateImage;
    Mat matchImage;
    Mat resultImage;
    Mat image;
    bool go;
};

#endif // WINDOW_H
