#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include"myfactory.h"
#include"Mat.hpp"
#include "graphicsview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setActionStatus(bool);
    void updateRightImage(QPixmap &pixmap);
    void cleanImage();
    void createToolBar();
    void createAction();
    ~MainWindow();


private slots:

    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionExit_triggered();

    void on_actionHorizontal_triggered();
    void on_actionVertical_triggered();
    void on_actionRevocation_triggered();
    void on_actionRestore_triggered();
    void on_actionBig_triggered();
    void on_actionSmall_triggered();

    void on_actionRotate_triggered();
    void on_actionAdjust_brightness_triggered();
    void on_actionCold_triggered();
    void on_actionWorm_triggered();
    void on_actionSelf_triggered();

//      void on_actionBinar_change_triggered();
//      void on_actionLinear_change_triggered();
//    void on_actionSimple_triggered();
//    void on_actionGauss_triggered();
//    void on_actionAverage_triggered();
//    void on_actionMeida_Filter_triggered();
//    void on_actionLaplace_triggered();

//    void on_actionHistogram_triggered();
//    void on_actionGrayscale_triggered();

private:
    Ui::MainWindow *ui;

    QGraphicsScene  *leftScene;
    QGraphicsScene  *rightScene;
    QGraphicsPixmapItem* leftPixmapItem;
    QGraphicsPixmapItem* rightPixmapItem;

    QLabel    *size;
    QFileInfo *info;

    QString getUserName();
    QString getUserPath();
};
#endif // MAINWINDOW_
