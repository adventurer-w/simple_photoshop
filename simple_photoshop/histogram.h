#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QDebug>

class Histogram : public QLabel
{
public:
    Histogram(QWidget* parent = nullptr);
    Histogram(QWidget*, Histogram*);

    void computeHstgrm(QImage img);
    void paintEvent(QPaintEvent *e);
    void drawBwHstgrm(int xBase, int yBase, int height);
    void drawRedHstgrm(int xBase, int yBase, int height);
    void drawGreenHstgrm(int xBase, int yBase, int height);
    void drawBlueHstgrm(int xBase, int yBase, int height);
    int getBwHstgrm(int index);
    int getRedHstgrm(int index);
    int getGreenHstgrm(int index);
    int getBlueHstgrm(int index);

private:

    int bwHstgrm[259];      //0-255储存各个值的数量，256储是最大值，257储存黑色组成的总数，258白色总数


    int redHstgrm[258];     //0-255储存各个值的数量，256储是最大值，257储存总数
    int greenHstgrm[258];
    int blueHstgrm[258];
};

#endif // HISTOGRAM_H
