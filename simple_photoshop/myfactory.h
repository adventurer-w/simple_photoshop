#ifndef MYFACTORY_H
#define MYFACTORY_H

#include "Mat.hpp"

class Myfactory
{
public:
    Myfactory(Mat<double> m);
    Myfactory();
    QPixmap getPixmap();
    QPixmap getPixmap(Mat<double> m);

private:
    Mat<double> mymat;
};

#endif // MYFACTORY_H
