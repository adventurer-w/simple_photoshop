#ifndef MYPAINTER_H
#define MYPAINTER_H
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QDebug>

class Mypainter : public QWidget
{
public:
    Mypainter(int h,int w);
    void painEvent();
private:
   int picHeight;
   int picWidth;
};

#endif // MYPAINTER_H
