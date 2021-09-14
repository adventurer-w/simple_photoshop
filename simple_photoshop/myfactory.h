#ifndef MYFACTORY_H
#define MYFACTORY_H

#include "Mat.hpp"

class Myfactory
{
public:
    Myfactory(Mat<double> m);
    Myfactory();
    QPixmap getPixmap();
    QImage getImage(Mat<double> m);
    QPixmap getPixmap(Mat<double> m);
    Mat<double> getMat(QImage image);
private:
    Mat<double> mymat;
};

#endif // MYFACTORY_H
