#include "mainwindow.h"
#include "ui_mainwindow.h"


Mat<double> nowMat,prMat,nextMat;
Myfactory myfactory;
QString imagePath;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leftScene = new QGraphicsScene;
    rightScene = new QGraphicsScene;

    leftPixmapItem = new QGraphicsPixmapItem();
    rightPixmapItem = new QGraphicsPixmapItem();

    size = new QLabel;

    info = nullptr;

    leftScene->setBackgroundBrush(QColor::fromRgb(225,225,225));
    ui->leftGraphicsView->setScene(leftScene);
    rightScene->setBackgroundBrush(QColor::fromRgb(225,225,225));
    ui->rightGraphicsView->setScene(rightScene);

    ui->statusbar->addPermanentWidget(size);


    createAction();
    createToolBar();

    setActionStatus(false);
    setWindowTitle("Simple_ps");
}

void MainWindow::createToolBar(){

    ui->toolBar->addAction(ui->actionOpen);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionClose);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionRestore);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionSmall);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionBig);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionRotate);
    ui->toolBar->addSeparator();
}

void MainWindow::createAction()
{
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActionStatus(bool status)
{

    ui->actionClose->setEnabled(status);
    ui->actionSave->setEnabled(status);
    ui->actionSave_as->setEnabled(status);
    ui->actionExit->setEnabled(status);
    ui->actionHorizontal->setEnabled(status);
    ui->actionVertical->setEnabled(status);
    ui->actionRevocation->setEnabled(status);
    ui->actionRestore->setEnabled(status);
    ui->actionBig->setEnabled(status);
    ui->actionSmall->setEnabled(status);
    ui->actionRotate->setEnabled(status);
    ui->actionAdjust_brightness->setEnabled(status);
    ui->actionCold->setEnabled(status);
    ui->actionWorm->setEnabled(status);
    ui->actionSelf->setEnabled(status);
    ui->actionFrame->setEnabled(status);
    ui->actionSimple->setEnabled(status);
    ui->actionGauss->setEnabled(status);
    ui->actionAverage->setEnabled(status);
    ui->actionMeida_Filter->setEnabled(status);
    ui->actionLaplace->setEnabled(status);
    ui->actionHistogram->setEnabled(status);
    ui->actionGrayscale->setEnabled(status);
    ui->menuFind->setEnabled(status);
    ui->menuBlur->setEnabled(status);
    ui->menuEdit->setEnabled(status);
    ui->menuArtistic_Effect->setEnabled(status);

}

void MainWindow::cleanImage()
{
    leftScene->clear();
    ui->leftGraphicsView->resetTransform();

    rightScene->clear();
    ui->rightGraphicsView->resetTransform();


    if (size)
    {
        delete size;
        size = new QLabel;
        ui->statusbar->addPermanentWidget(size);
    }

    setActionStatus(false);
}

void MainWindow::on_actionOpen_triggered()
{
        // Automatically detects the current user's home directory
        // And then wait the user to select one image
        imagePath = QFileDialog::getOpenFileName(this, tr("选择图片"), "C:\\","(*.bmp)");

        char*  ch;
        ch=imagePath.toLatin1().data();

        nowMat.ReadText(ch);
        prMat = nowMat;
        QPixmap leftPixmap=myfactory.getPixmap(nowMat);

    if (!imagePath.isEmpty())
    {


        leftPixmapItem = leftScene->addPixmap(leftPixmap);
        leftScene->setSceneRect(QRectF(leftPixmap.rect()));

        rightPixmapItem = rightScene->addPixmap(leftPixmap);
        rightScene->setSceneRect(QRectF(leftPixmap.rect()));

        // settings
        setActionStatus(true);
        size->setText(QString::number(leftPixmapItem->pixmap().width())
                      + " x " + QString::number(leftPixmapItem->pixmap().height()));
    }

    setActionStatus(true);
}

void MainWindow::on_actionClose_triggered()
{
    cleanImage();
    setActionStatus(false);
}

void MainWindow::on_actionSave_triggered(){
     rightPixmapItem->pixmap().save(imagePath);
}

void MainWindow::on_actionSave_as_triggered()
{

    QString newPath = QFileDialog::getSaveFileName(this, tr("选择图片"), "C:\\","(*.bmp)");


    if (!newPath.isEmpty()) {

        QFile file(newPath);
        rightPixmapItem->pixmap().save(newPath);
    }
}
