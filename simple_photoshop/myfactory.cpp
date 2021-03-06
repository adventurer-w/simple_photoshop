#include "myfactory.h"

Myfactory::Myfactory(Mat<double> m):mymat(m){}

Myfactory::Myfactory(){}

QPixmap Myfactory::getPixmap(){
    int w=mymat.Width(),h=mymat.Height();
       QImage img(w,h,QImage::Format_RGB888);
       for(int x = 0; x<w; x++){
            for(int y = 0; y<h; y++){
               img.setPixel(x,y,qRgb((int)mymat.Rdata[y][x],(int)mymat.Gdata[y][x],(int)mymat.Bdata[y][x]));
            }
        }
       QPixmap tempPixmap = QPixmap::fromImage(img);
       return tempPixmap;
}

QPixmap Myfactory::getPixmap(Mat<double> m){
    int w=m.Width(),h=m.Height();
       QImage img(w,h,QImage::Format_RGB888);
       for(int x = 0; x<w; x++){
            for(int y = 0; y<h; y++){
               img.setPixel(x,y,qRgb((int)m.Gdata[h-y-1][x],(int)m.Rdata[h-y-1][x],(int)m.Bdata[h-y-1][x]));
            }
        }
       QPixmap tempPixmap = QPixmap::fromImage(img);
       return tempPixmap;
}
Mat<double> Myfactory::getMat(QImage image){
    Mat<double> tp(image.height(),image.width());

    for(int x = 0; x<image.height(); x++){
         for(int y = 0; y<image.width(); y++){
              QColor col=QColor(image.pixel(x,y));
                tp.Gdata[x][y]=col.red();
                tp.Rdata[x][y]=col.green();
                tp.Bdata[x][y]=col.blue();
         }
     }
     return tp;
}
QImage Myfactory::getImage(Mat<double> m){
    int w=m.Width(),h=m.Height();
       QImage img(w,h,QImage::Format_RGB888);
       for(int x = 0; x<w; x++){
            for(int y = 0; y<h; y++){
               img.setPixel(x,y,qRgb((int)m.Gdata[h-y-1][x],(int)m.Rdata[h-y-1][x],(int)m.Bdata[h-y-1][x]));
            }
        }
       return img;
}
