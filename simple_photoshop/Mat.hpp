#ifndef _MAT_HPP_
#define _MAT_HPP_

#include<stdlib.h>
#include<ctime>
#include<fstream>
#include<Windows.h>
#include<exception>
#include<vector>
#include<iostream>
#include <QMainWindow>
#include <QProcess>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QLabel>
#include <QDebug>
#include <QStandardPaths>
#include <QTranslator>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QImage>
#include <QPixmap>

template< typename T>
class Mat
{
public:
    Mat(); //无参数的构造函数，创建行列都为零的Mat对象
    Mat(int h, int w); //构造函数重载，创建h行，w列的Mat对象
    Mat(int h, int w, T val); //构造函数重载，矩阵元素的值都为val;
    Mat(const Mat &m); //拷贝构造函数;
    Mat(char * name);
    virtual ~Mat(); //析构函数;

// 下面2个读写文本文件的函数，需要考虑不同数据类型的存储
    void ReadText(char *fileName); //从文本文件中读入数据
    void WriteText(char *filename); //将数据保存为文本文件
    void Zeros(int h, int w); // 根据参数产生h行w列的全零矩阵
    void Ones(int h, int w); // 根据参数产生h行w列的全1矩阵
    void Random(int h, int w); //产生h行w列的随机矩阵，矩阵的元素为[0,255]之间的随机实数（double类型）
    void Identity(int n); // 根据参数产生n行n列的单位矩阵

    int Height();//得到矩阵高度
    int Width();//得到矩阵宽度
    Mat<T>  MajorDiagonal();// 求主对角线上的元素，输出一个N行1列的矩阵，N为主对角线上元素的个数
    Mat<T>  MinorDiagonal();// 求副对角线上的元素，输出一个N行1列的矩阵，N为副对角线上元素的个数
    Mat<T> Row(int n);// 返回矩阵的第n行上的元素，组出一个1行N列的矩阵输出，N为第n行上元素的个数
    Mat<T> Column(int n);// 返回矩阵的第n列上的元素，组出一个N行1列的矩阵输出，N为第n列上元素的个数

    T* At(int row, int col);          //获取某点的值
    void Set(int row, int col, T value); //设置元素(row,col)为某值;
    void Set(T *value); //设置所有元素为同一值;

    Mat<double> Normalize(); // 该函数把矩阵的数据线性缩放至[0,1]区间;

    Mat<T> Flip(int code); //翻转; 根据code的值：0:左右翻转，1:上下翻转;
    Mat<T> Resize(int h, int w); //缩放
    Mat<T> Crop(int x1, int y1, int x2, int y2);//裁剪点(x1,y1)到点(x2,y2)
    Mat<T> Rotate(int degree);//旋转，90度的整数倍
    T Variance(int op);//求图像的方差
    Mat<T> Transpose(); // 转置

    Mat<T> Reshape(int h, int w); //在元素总数不变的情况下，将矩阵的行列变为参数给定的大小
    bool IsEmpty();// 判断是否为空矩阵
    bool IsSquare(int a,int b);// 判断矩阵高宽比是否为a:b;
    void CopyTo(Mat<T> &m); // 将矩阵复制给m，完成深拷贝
    Mat<T> Mult(double s,int op); // 矩阵的每个元素都乘以参数s(0R 1G 2B)
    Mat<T> Divi(double s,int op);
    Mat<T> Divi_all(double s);
    Mat<T> Mult_all(double s);
    Mat<T> Cat(Mat<T> &m, int code); // 将m与当前对象进行拼接，code代表拼接的方式

    Mat<T> Clone(); // 从当前对象拷贝创建一个新的矩阵，完成深拷贝
    T Mean(int op) ;
    T Median(int op) ;

    Mat<T>& operator=(const Mat<T> &m);  //重载赋值运算符，完成对象间的拷贝；
    bool operator==(const Mat<T> &m);  //判断两个Mat对象是否相等

    Mat<T>& operator++();  //前置自加；
    Mat<T>& operator--();  //前置自减；
    Mat<T> operator ++(int);  //后置自加；
    Mat<T> operator --(int);  //后置自减；
    Mat<T> operator-();  // 取反；注意要把矩阵的数据规整到[0,1]区间后，再用1减


    Mat<T> Add( const Mat<T>& m2); // 友元函数，将矩阵m1和m2相加，结果矩阵作为函数的返回值
    Mat<T> Sub(const Mat<T>& m2); // 友元函数，将矩阵m1和m2相减，结果矩阵作为函数的返回值
    Mat<T> Mult( const Mat<T>& m2);
   Mat<T> Divi( const Mat<T>& m2);

    Mat<T> gray2bw(T t); //以给定阈值t进行二值化，返回结果对象
    Mat<T> gray(); //黑白化


    friend void Swap(Mat<T> &a, Mat<T> &b){
        std::swap(a.Rdata, b.Rdata);
        std::swap(a.Gdata, b.Gdata);
        std::swap(a.Bdata, b.Bdata);
        std::swap(a.width, b.width);
        std::swap(a.height, b.height);
    }//使用友元函数交换两个Mat对象

    int height;
    int width;
    T **Rdata;
    T **Gdata;
    T **Bdata;
};
template< typename T>
Mat<T>::Mat():height(0),width(0),Rdata(nullptr),Gdata(nullptr),Bdata(nullptr){
}

template< typename T>
Mat<T>::Mat(int h,int w):height(h),width(w){
    Rdata = new T *[h];
    Gdata = new T *[h];
    Bdata = new T *[h];
    for(int i=0;i<h;++i){
        Rdata[i]= new T [w];
        Gdata[i]= new T [w];
        Bdata[i]= new T [w];
        for(int j=0;j<w;j++){
            Rdata[i][j]=Gdata[i][j]=Bdata[i][j]=0;
        }
    }
}

template< typename T>
Mat<T>::Mat(int h,int w,T val):height(h),width(w){
    Rdata = new T *[h];
    Gdata = new T *[h];
    Bdata = new T *[h];
    for(int i=0;i<h;++i){
        Rdata[i]= new double *[w];
        Gdata[i]= new double *[w];
        Bdata[i]= new double *[w];
        for(int j=0;j<w;j++){
            Rdata[i][j]=Gdata[i][j]=Bdata[i][j]=val;
        }
    }
}

template< typename T>
Mat<T>::Mat(const Mat& m):height(m.height),width(m.width){
    Rdata = new T *[m.height];
    Gdata = new T *[m.height];
    Bdata = new T *[m.height];
    for(int i=0;i<m.height;++i){
        Rdata[i]= new T [m.width];
        Gdata[i]= new T [m.width];
        Bdata[i]= new T [m.width];
        for(int j=0;j<m.width;j++){
            Rdata[i][j]=m.Rdata[i][j];
            Gdata[i][j]=m.Gdata[i][j];
            Bdata[i][j]=m.Bdata[i][j];
        }
    }
}

template<typename T>
Mat<T>::Mat(char *name){
    ReadText(name);
}

template<typename T>
Mat<T>::~Mat(){
    if(IsEmpty()){
        for (int i = 0; i < height; ++i) {
            delete[]Rdata[i];
            delete[]Gdata[i];
            delete[]Bdata[i];
        }
        delete[] Rdata;
        delete[] Gdata;
        delete[] Bdata;
    }
}

template<typename T>
bool Mat<T>::IsEmpty(){
    if(Rdata== nullptr&&Gdata== nullptr&&Bdata== nullptr){
        return true;
    }else{
        return false;
    }
}

template<typename T>
void Mat<T>::ReadText(char *fileName) {
    std::fstream bmp(fileName, std::ios::binary | std::ios::in);
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    bmp.read((char*)&bf, sizeof(BITMAPFILEHEADER));
    bmp.read((char*)&bi, sizeof(BITMAPINFOHEADER));
    if(!IsEmpty()){
        for (int i = 0; i < height; ++i) {
            delete[]Rdata[i];
            delete[]Gdata[i];
            delete[]Bdata[i];
        }
        delete[] Rdata;
        delete[] Gdata;
        delete[] Bdata;
    }
    width = bi.biWidth;
    height = bi.biHeight;

    Rdata = new T*[bi.biHeight];
    Gdata = new T*[bi.biHeight];
    Bdata = new T*[bi.biHeight];
    int width_r = ((bi.biWidth*3+3)/4)*4;
    int idx = width_r - width*3;
    std::cout<<idx<<std::endl;
    for(int i=0;i<bi.biHeight;++i){
        Rdata[i]= new T[bi.biWidth];
        Gdata[i]= new T[bi.biWidth];
        Bdata[i]= new T[bi.biWidth];
        for(int j=0;j < width;j++){
           unsigned char t[3];
           bmp.read((char*)t,3);
            Bdata[i][j]=t[0];
            Rdata[i][j]=t[1];
            Gdata[i][j]=t[2];
        }
        unsigned char temp[3];
        bmp.read((char*)temp, idx);
    }
    bmp.close();
}

template<typename T>
void Mat<T>::WriteText(char *filename){
    if(IsEmpty()){
        return;
    }
    std::fstream bmp(filename, std::ios::binary | std::ios::out);
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;

    bi.biWidth = width;
    bi.biHeight = height;
    bi.biBitCount = 24;
    bi.biSize = 40;
    bi.biPlanes = 1;
    bi.biCompression = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biSizeImage = (((bi.biWidth * bi.biBitCount) + 31) / 32 * 4) * bi.biHeight;
    bf.bfType = 0X4D42;
    bf.bfSize = bi.biSizeImage + 14;
    bf.bfReserved1 = bf.bfReserved2 = 0;
    bf.bfOffBits = 14 + 40;

    bmp.write((char*)&bf, sizeof(BITMAPFILEHEADER));
    bmp.write((char*)&bi, sizeof(BITMAPINFOHEADER));

    auto width_r = ((bi.biWidth * 3 + 3) / 4) * 4;
    int idx = width_r - width*3;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            unsigned char temp = Bdata[i][j] < 255 ? Bdata[i][j]>0 ? Bdata[i][j] : 0 : 255;//过饱和
            bmp.write((char*)&temp, 1);
            temp = Rdata[i][j] < 255 ? Rdata[i][j]>0 ? Rdata[i][j] : 0 : 255;//过饱和
            bmp.write((char*)&temp, 1);
            temp = Gdata[i][j] < 255 ? Gdata[i][j]>0 ? Gdata[i][j] : 0 : 255;//过饱和
            bmp.write((char*)&temp, 1);
        }
        char temp = '\n';
        bmp.write((char*)&temp, idx);
    }
}

template< typename T>
void Mat<T>::Zeros(int h, int w) {
    height = h;
    width = w;
    if (!IsEmpty()) {
        for (int i = 0; i < height; ++i) {
            delete[]Rdata[i];
            delete[]Gdata[i];
            delete[]Bdata[i];
        }
        delete[]Rdata;
        delete[]Gdata;
        delete[]Bdata;
    }

    Rdata = new T* [h];
    Gdata = new T* [h];
    Bdata = new T* [h];
    for (int i = 0; i < h; ++i) {
        Rdata[i] = new T[w];
        Gdata[i] = new T[w];
        Bdata[i] = new T[w];
        for (int j = 0; j < w; ++j) {
            Rdata[i][j] = 0;
            Gdata[i][j] = 0;
            Bdata[i][j] = 0;
        }
    }
}

template< typename T>
void Mat<T>::Ones(int h, int w) {
    height = h;
    width = w;
    if (!IsEmpty()) {
        for (int i = 0; i < height; ++i) {
            delete[]Rdata[i];
            delete[]Gdata[i];
            delete[]Bdata[i];
        }
        delete[]Rdata;
        delete[]Gdata;
        delete[]Bdata;
    }

    Rdata = new T* [h];
    Gdata = new T* [h];
    Bdata = new T* [h];
    for (int i = 0; i < h; ++i) {
        Rdata[i] = new T[w];
        Gdata[i] = new T[w];
        Bdata[i] = new T[w];
        for (int j = 0; j < w; ++j) {
            Rdata[i][j] = 1;
            Gdata[i][j] = 1;
            Bdata[i][j] = 1;
        }
    }
}

template< typename T>
void Mat<T>::Random(int h, int w){
    height = h;
    width = w;
    if (!IsEmpty()) {
        for (int i = 0; i < height; ++i) {
            delete[]Rdata[i];
            delete[]Gdata[i];
            delete[]Bdata[i];
        }
        delete[]Rdata;
        delete[]Gdata;
        delete[]Bdata;
    }

    Rdata = new T* [h];
    Gdata = new T* [h];
    Bdata = new T* [h];
    for (int i = 0; i < h; ++i) {
        Rdata[i] = new T[w];
        Gdata[i] = new T[w];
        Bdata[i] = new T[w];
        for (int j = 0; j < w; ++j) {
            srand((unsigned int)(time(NULL)));

            Rdata[i][j] = rand() / double(RAND_MAX)*255;
            Gdata[i][j] = rand() / double(RAND_MAX)*255;
            Bdata[i][j] = rand() / double(RAND_MAX)*255;
        }
    }
}

template< typename T>
void Mat<T>::Identity(int n) {
    Zeros(n, n);
}

template< typename T>
int Mat<T>::Height(){
    return height;
}

template< typename T>
int Mat<T>::Width(){
    return width;
}

template< typename T>
Mat<T> Mat<T>::MajorDiagonal() {
    if (!IsSquare()) {
        std::cout<<"不是正方形";

    }

    Mat<T> res(1, width);
    for (int i = 0; i < height; ++i) {
        res.Rdata[0][i] = Rdata[i][i];
        res.Gdata[0][i] = Gdata[i][i];
        res.Bdata[0][i] = Bdata[i][i];
    }

    return res;
}

template< typename T>
Mat<T> Mat<T>::MinorDiagonal() {
    if (!IsSquare()) {
        std::cout<<"超出边界";
    }
    Mat<T> res(1, width);
    for (int i = 0; i < height; ++i) {
        res.Rdata[0][i] = Rdata[i][width - 1 - i];
        res.Gdata[0][i] = Gdata[i][width - 1 - i];
        res.Bdata[0][i] = Bdata[i][width - 1 - i];
    }
    return res;
}

template< typename T>
Mat<T> Mat<T>::Row(int n) {
    if (n >= height || n < 0) {
        std::cout<<"超出边界";
    }

    Mat<T> res(1, width);
    for (int i = 0; i < width; ++i) {
        res.Rdata[0][i] = Rdata[n][i];
        res.Gdata[0][i] = Gdata[n][i];
        res.Bdata[0][i] = Bdata[n][i];
    }
    return res;
}

template< typename T>
Mat<T> Mat<T>::Column(int n) {
    if (n >= height || n < 0) {
        std::cout<<"超出边界";
    }

    Mat<T> res(1, width);
    for (int i = 0; i < width; ++i) {
        res.Rdata[0][i] = Rdata[i][n];
        res.Gdata[0][i] = Gdata[i][n];
        res.Bdata[0][i] = Bdata[i][n];
    }
    return res;
}

template< typename T>
Mat<T> Mat<T>::Flip(int code){

    Mat<T> temp(*this);
    if (IsEmpty()) {
    }
    if (code) {
        for (int i = 0; i < height; ++i) {
            temp.Rdata[i] = Rdata[height - 1 - i];
            temp.Gdata[i] = Gdata[height - 1 - i];
            temp.Bdata[i] = Bdata[height - 1 - i];
        }
    }else {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                temp.Rdata[i][j] = Rdata[i][width - 1 - j];
                temp.Gdata[i][j] = Gdata[i][width - 1 - j];
                temp.Bdata[i][j] = Bdata[i][width - 1 - j];
            }
        }
    }
    return temp;
}

template< typename T>
Mat<T> Mat<T>::Resize(int h, int w){
    if (IsEmpty()) {

    }

    bool hBig = h > height;
    bool wBig = w > width;
    double hi = height / h;
    double wi = width / w;
    double p, q;
    p = q = 0;
    auto Rtemp = new T* [h];
    auto Gtemp = new T* [h];
    auto Btemp = new T* [h];
    for (int i = 0; i < h; ++i) {
        Rtemp[i] = new T[w];
        Gtemp[i] = new T[w];
        Btemp[i] = new T[w];
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            Rtemp[i][j] = Rdata[(int)p][(int)q];
            Gtemp[i][j] = Gdata[(int)p][(int)q];
            Btemp[i][j] = Bdata[(int)p][(int)q];
            q += wi;
        }
        q = 0;
        p += hi;
    }

    Mat<T> temp();
    temp.Rdata = Rtemp;
    temp.Gdata = Gtemp;
    temp.Bdata = Btemp;
    temp.width = w;
    temp.height = h;
    return temp;
}

template< typename T>
Mat<T> Mat<T>::Crop(int x1, int y1, int x2, int y2){
    if (IsEmpty()) {
    }
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);
    if (x1 < 0 || y1 < 0 || x2 >= width || y2 >= height) {
        std::cout<<"越界";
    }

    int h = abs(y2 - y1);
    int w = abs(x2 - x1);
    auto Rtemp = new T* [h];
    auto Gtemp = new T* [h];
    auto Btemp = new T* [h];

    for (int i = 0; i < h; ++i) {
        Rtemp[i] = new T [w];
        Gtemp[i] = new T [w];
        Btemp[i] = new T [w];
        for (int j = 0; j < w; ++j) {
            Rtemp[i][j] = Rdata[x1 + i][y1 + j];
            Gtemp[i][j] = Gdata[x1 + i][y1 + j];
            Btemp[i][j] = Bdata[x1 + i][y1 + j];
        }
    }

    Mat<T> temp;

    temp.width = w;
    temp.height = h;
    temp.Rdata = Rtemp;
    temp.Gdata = Gtemp;
    temp.Bdata = Btemp;
    return temp;
}

template<typename T>
Mat<T> Mat<T>::Rotate(int degree){
    if (IsEmpty()) {
    }
    degree /= 90;
    degree %= 4;
    if (degree < 0) degree += 4;
    Mat<T> temp(*this);

    for (int i = 0; i < degree; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < height; ++k) {
                temp.Rdata[j][k] = temp.Rdata[k][j];
                temp.Gdata[j][k] = temp.Gdata[k][j];
                temp.Bdata[j][k] = temp.Bdata[k][j];
            }
        }
    }
    return temp;
}

template<typename T>
T Mat<T>::Variance(int op){
    T mean = Mean(op);
    T res = 0;
    if(op==0){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                res += (Rdata[i][j] - mean) * (Rdata[i][j] - mean);
            }
        }
    }else if(op==1){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                res += (Gdata[i][j] - mean) * (Gdata[i][j] - mean);
            }
        }
    }else{
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                res += (Bdata[i][j] - mean) * (Bdata[i][j] - mean);
            }
        }
    }

    res /= (T)width * height;
    return res;
}

template< typename T>
Mat<T> Mat<T>::Transpose() {
    if (IsEmpty()) {
    }
    Mat<T> tp(width,height);
    tp.Rdata = new T* [width];
    tp.Gdata = new T* [width];
    tp.Bdata = new T* [width];
    for (int i = 0; i < width; ++i) {
        tp.Rdata[i] = new T[height];
        tp.Gdata[i] = new T[height];
        tp.Bdata[i] = new T[height];
        for (int j = 0; j < height; ++j) {
            tp.Rdata[i][j] = Rdata[j][i];
            tp.Gdata[i][j] = Gdata[j][i];
            tp.Bdata[i][j] = Bdata[j][i];
        }
    }

    std::swap(width, height);
    return tp;
}

template< typename T>
T* Mat<T>::At(int row,int col){
    if (row < 0 || row >= height || col < 0 || col >= width) {
        std::cout<<"超出边界"<<std::endl;

    }
    T* temp=new T[3];
    temp[0]=Rdata[row][col];
    temp[1]=Gdata[row][col];
    temp[2]=Bdata[row][col];
    return temp;
}

template< typename T>
void Mat<T>::Set(int row, int col, T value){
if (row < 0 || row >= height || col < 0 || col >= width) {
        std::cout<<"超出边界";
        return;
    }
    Rdata[row][col]=value[0];
    Gdata[row][col]=value[1];
    Bdata[row][col]=value[2];
}

template< typename T>
void Mat<T>::Set(T *value){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Rdata[i][j] = value;
            Gdata[i][j] = value;
            Bdata[i][j] = value;
        }
    }
}

template< typename T>
Mat<double> Mat<T>::Normalize(){
    Mat<double> temp(height,width);
    double mx[3] = {0,0,0};
    double mn[3] = {0,0,0};

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            mx[0] = max(mx[0],Rdata[i][j]);
            mn[0] = min(mx[0],Rdata[i][j]);
            mx[1] = max(mx[1],Gdata[i][j]);
            mn[1] = min(mx[1],Gdata[i][j]);
            mx[2] = max(mx[2],Bdata[i][j]);
            mn[2] = min(mx[2],Bdata[i][j]);
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp.Rdata[i][j] = (Rdata[i][j] - mn[0]) / (mx[0] - mn[0]);
            temp.Gdata[i][j] = (Gdata[i][j] - mn[1]) / (mx[1] - mn[1]);
            temp.Bdata[i][j] = (Bdata[i][j] - mn[2]) / (mx[2] - mn[2]);
        }
    }
    return temp;
}

template< typename T>
Mat<T> Mat<T>::Reshape(int h,int w){
    if (h * w != height * width) {
        std::cout<<"不对 ";

    }
    T** Rtemp = new T* [h];
    T** Gtemp = new T* [h];
    T** Btemp = new T* [h];
    int p, q;
    p = q = 0;

    for (int i = 0; i < h; ++i) {
        Rtemp[i] = new T[w];
        Gtemp[i] = new T[w];
        Btemp[i] = new T[w];
        for (int j = 0; j < w; ++j) {
            if (q >= width) {
                q = 0;
                ++p;
            }
            Rtemp[i][j] = Rdata[p][q++];
            Gtemp[i][j] = Gdata[p][q++];
            Btemp[i][j] = Bdata[p][q++];
        }
    }

    Mat<T> tp;
    tp.Rdata = Rtemp;
    tp.Gdata = Gtemp;
    tp.Bdata = Btemp;
    tp.width = w;
    tp.height = h;
    return tp;
}

template<typename  T>
bool Mat<T>::IsSquare(int a,int b) {
    return (a/b)==(height/width);
}

template<typename T>
void Mat<T>::CopyTo(Mat<T>& m) {
    if (!m.IsEmpty()) {
        for (int i = 0; i < m.height; ++i) {
            delete[]Rdata[i];
            delete[]Gdata[i];
            delete[]Bdata[i];
        }
        delete[] Rdata;
        delete[] Gdata;
        delete[] Bdata;
    }
    m.Rdata = new T* [height];
    m.Gdata = new T* [height];
    m.Bdata = new T* [height];
    m.width = width;
    m.height = height;
    for (int i = 0; i < height; ++i) {
        m.Rdata[i] = new T[width];
        m.Gdata[i] = new T[width];
        m.Bdata[i] = new T[width];
        for (int j = 0; j < width; ++j) {
            m.Rdata[i][j] = Rdata[i][j];
            m.Gdata[i][j] = Gdata[i][j];
            m.Gdata[i][j] = Gdata[i][j];
        }
    }
}

template<typename T>
Mat<T> Mat<T>::Mult(double s, int op) {
    Mat<T> tp(*this);
    if(op==0){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Rdata[i][j] *= s;
            }
        }
    } else if(op==1){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Gdata[i][j] *= s;
            }
        }
    }else{
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Bdata[i][j] *= s;
            }
        }
    }
    return tp;
}

template<typename T>
Mat<T> Mat<T>::Mult_all(double s) {
    Mat<T> tp(*this);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Rdata[i][j] *= s;
                tp.Gdata[i][j] *=s;
                tp.Bdata[i][j] *=s;
            }
        }

    return tp;
}

template<typename T>
Mat<T> Mat<T>::Divi_all(double s) {
    Mat<T> tp(*this);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            tp.Rdata[i][j] /= s;
            tp.Gdata[i][j] /=s;
            tp.Bdata[i][j] /=s;
        }
    }

    return tp;
}

template<typename T>
Mat<T> Mat<T>::Divi(double s,int op)
{
    Mat<T> tp(*this);
    if(op==0){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Rdata[i][j] = s == 0 ? 0 : Rdata[i][j] / s;
            }
        }
    }else if(op==1){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Gdata[i][j] = s == 0 ? 0 : Gdata[i][j] / s;
            }
        }
    }else {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                tp.Bdata[i][j] = s == 0 ? 0 : Bdata[i][j] / s;
            }
        }
    }
    return tp;
}

template<typename T>
Mat<T> Mat<T>::Cat(Mat<T> &m, int code) {
    if (m.IsEmpty()) {
    }
    Mat<T> tp;
    if (code == 1) {//接到右边
        int newWidth = width + m.width;
        int newHeight = height > m.height ? height : m.height;
        auto Rtemp = new T* [newHeight];
        auto Gtemp = new T* [newHeight];
        auto Btemp = new T* [newHeight];

        for (int i = 0; i < newHeight; ++i) {

            Rtemp[i] = new T[newWidth];
            Gtemp[i] = new T[newWidth];
            Btemp[i] = new T[newWidth];

            for (int j = 0; j < newWidth; ++j) {
                if (i < height && j < width) {
                    Rtemp[i][j] = Rdata[i][j];
                    Gtemp[i][j] = Gdata[i][j];
                    Btemp[i][j] = Bdata[i][j];
                }
                else if (i < m.height && j >= width) {
                    Rtemp[i][j] = m.Rdata[i][j - width];
                    Gtemp[i][j] = m.Gdata[i][j - width];
                    Btemp[i][j] = m.Bdata[i][j - width];
                }
                else {
                    Rtemp[i][j] = 0;
                    Gtemp[i][j] = 0;
                    Btemp[i][j] = 0;
                }
            }
            tp.Rdata = Rtemp;
            tp.Gdata = Gtemp;
            tp.Bdata = Btemp;
            tp.width = newWidth;
            tp.height = newHeight;
        }
    }else if (code == 2) {//接到下边
        int newHeight = height + m.height;
        int newWidth = width > m.width ? width : m.width;
        auto Rtemp = new T* [newHeight];
        auto Gtemp = new T* [newHeight];
        auto Btemp = new T* [newHeight];

        for (int i = 0; i < newHeight; ++i) {
            Rtemp[i] = new T[newWidth];
            Gtemp[i] = new T[newWidth];
            Btemp[i] = new T[newWidth];
            for (int j = 0; j < newWidth; ++j) {
                if (i < height && j < width) {
                    Rtemp[i][j] = Rdata[i][j];
                    Btemp[i][j] = Bdata[i][j];
                    Gtemp[i][j] = Gdata[i][j];
                }
                else if (i >= height && j < m.width) {
                    Rtemp[i][j] = m.Rdata[i - height][j];
                    Gtemp[i][j] = m.Gdata[i - height][j];
                    Btemp[i][j] = m.Bdata[i - height][j];
                }
                else {
                    Rtemp[i][j] = 0;
                    Gtemp[i][j] = 0;
                    Btemp[i][j] = 0;
                }
            }
        }

        tp.Rdata = Rtemp;
        tp.Gdata = Gtemp;
        tp.Bdata = Btemp;
        tp.width = newWidth;
        tp.height = newHeight;
    }
    return tp;
}

template<typename T>
Mat<T> Mat<T>:: Clone(){
    Mat<T> tp(height,width);
    tp.Rdata = new T*[height];
    tp.Gdata = new T*[height];
    tp.Bdata = new T*[height];

    for(int i=0;i< height;i++){
        tp.Rdata[i] = new T[width];
        tp.Gdata[i] = new T[width];
        tp.Bdata[i] = new T[width];

        for(int j = 0; j < width ;++j){
            tp.Rdata[i][j] = Rdata[i][j];
            tp.Gdata[i][j] = Gdata[i][j];
            tp.Bdata[i][j] = Bdata[i][j];
        }
    }
    return tp;
}

template<typename T>
T Mat<T>::Mean(int op)
{
    if (IsEmpty()) {
        return 0;
    }
    T res = 0;
    if(op==0){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                res += Rdata[i][j];
            }
        }
    }else if(op==1){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                res += Gdata[i][j];
            }
        }
    }else{
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                res += Bdata[i][j];
            }
        }
    }

    res /= (T)width * height;
    return res;
}

template<typename T>
T Mat<T>::Median(int op){
    if (IsEmpty()) {
        return 0;
    }
    std::vector<T> temp;
    if(op==0){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                temp.push_back(Rdata[i][j]);
            }
        }
    }else if(op==1){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                temp.push_back(Gdata[i][j]);
            }
        }
    }else{
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                temp.push_back(Bdata[i][j]);
            }
        }
    }
    sort(temp.begin(),temp.end());
    if (temp.size() % 2) {
        return temp[temp.size() / 2];
    }
    else {
        double res = 0;
        res += temp[temp.size() / 2];
        res += temp[temp.size() / 2 - 1];
        return res / 2;
    }
}

template<typename T>
Mat<T>& Mat<T>::operator=(const Mat<T> &m){
    Mat<T> temp(m);
    Swap(*this, temp);
    return *this;
}

template<typename T>
bool Mat<T>::operator==(const Mat<T>& m)
{
    if (width != m.width || height != m.height) {
        return false;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (m.Rdata[i][j] != Rdata[i][j]) {
                return false;
            }
            if (m.Gdata[i][j] != Gdata[i][j]) {
                return false;
            }
            if (m.Bdata[i][j] != Bdata[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template<typename  T>
Mat<T>& Mat<T>::operator++()
{
    Mat a(height, width, 1);
    *this = Add(*this, a);
    return *this;
}

template<typename  T>
Mat<T>& Mat<T>::operator--()
{
    Mat a(height, width, -1);
    *this = Add(*this, a);
    return *this;
}

template<typename  T>
Mat<T> Mat<T>::operator++(int)
{
    Mat<T> a(height, width, 1);
    Mat<T> temp = *this;
    *this = Add(*this, a);
    return temp;
}

template<typename  T>
Mat<T> Mat<T>::operator--(int)
{
    Mat<T> a(height, width, -1);
    Mat<T> temp = *this;
    *this = Add(*this, a);
    return temp;
}

template<typename  T>
Mat<T> Mat<T>::operator-(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            Rdata[i][j] = 255-Rdata[i][j];
            Gdata[i][j] = 255-Gdata[i][j];
            Bdata[i][j] = 255-Bdata[i][j];
        }
    }
    return *this;
}

template<typename  T>
Mat<T> Mat<T>::Add(const Mat<T>& m2) {

    Mat<T> temp(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if((Rdata[i][j] + m2.Rdata[i][j])>255){
                temp.Rdata[i][j]=255;
            }else{
                temp.Rdata[i][j]=Rdata[i][j] + m2.Rdata[i][j];
            }

            if((Gdata[i][j] + m2.Gdata[i][j])>255){
                temp.Gdata[i][j]=255;
            }else{
                temp.Gdata[i][j]=Gdata[i][j] + m2.Gdata[i][j];
            }

            if((Bdata[i][j] + m2.Bdata[i][j])>255){
                temp.Bdata[i][j]=255;
            }else{
                temp.Bdata[i][j]=Bdata[i][j] + m2.Bdata[i][j];
            }

        }
    }

    return temp;
}

template<typename  T>
Mat<T> Mat<T>::Sub( const Mat<T>& m2) {
    Mat<T> temp(height,width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if((Rdata[i][j] - m2.Rdata[i][j])<0){
                temp.Rdata[i][j]=0;
            }else{
                temp.Rdata[i][j]=Rdata[i][j] - m2.Rdata[i][j];
            }

            if((Gdata[i][j] - m2.Gdata[i][j])<0){
                temp.Gdata[i][j]=0;
            }else{
                temp.Gdata[i][j]=Gdata[i][j] - m2.Gdata[i][j];
            }

            if((Bdata[i][j] - m2.Bdata[i][j])<0){
                temp.Bdata[i][j]=0;
            }else{
                temp.Bdata[i][j]=Bdata[i][j] -m2.Bdata[i][j];
            }
        }
    }

    return temp;
}

template<typename  T>
Mat<T> Mat<T>::Mult( const Mat<T>& m2) {

    Mat<T> temp(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j <width; ++j) {
            if((Rdata[i][j] * m2.Rdata[i][j])>255){
                temp.Rdata[i][j]=255;
            }else{
                temp.Rdata[i][j]=Rdata[i][j] * m2.Rdata[i][j];
            }

            if((Gdata[i][j] * m2.Gdata[i][j])>255){
                temp.Gdata[i][j]=255;
            }else{
                temp.Gdata[i][j]=Gdata[i][j] * m2.Gdata[i][j];
            }

            if((Bdata[i][j] * m2.Bdata[i][j])>255){
                temp.Bdata[i][j]=255;
            }else{
                temp.Bdata[i][j]=Bdata[i][j] * m2.Bdata[i][j];
            }
        }
    }

    return temp;
}

template<typename  T>
Mat<T> Mat<T>::Divi(const Mat<T>& m2) {
    Mat<T> temp(height, width);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp.Rdata[i][j] = Rdata[i][j] / m2.Rdata[i][j];
            temp.Gdata[i][j] = Gdata[i][j] / m2.Gdata[i][j];
            temp.Bdata[i][j] = Bdata[i][j] / m2.Bdata[i][j];
        }
    }

    return temp;
}


template<typename  T>
Mat<T> Mat<T>::gray2bw(T t) {
    Mat<T> temp(*this);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            T x = (Rdata[i][j]+Gdata[i][j]+Bdata[i][j])/3;
            temp.Rdata[i][j]=temp.Gdata[i][j]=temp.Bdata[i][j]=( ( x > t ) * 255 );
        }
    }
    return temp;
}

template<typename T>
Mat<T> Mat<T>::gray() {
    Mat<T> temp(*this);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            T x = (Rdata[i][j]+Gdata[i][j]+Bdata[i][j])/3;
            temp.Rdata[i][j]=temp.Gdata[i][j]=temp.Bdata[i][j]=x;
        }
    }
    return temp;
}
#endif
