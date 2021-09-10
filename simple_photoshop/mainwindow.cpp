#include "mainwindow.h"
#include "ui_mainwindow.h"


Mat<double> nowMat,prMat,oriMat,tempMat;
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
    setWindowTitle("Simple_photoshop");
}

void MainWindow::createToolBar(){

    ui->toolBar->addAction(ui->actionOpen);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionRevocation);
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
    ui->actionBinar_change->setEnabled(status);
    ui->actionLinear_change->setEnabled(status);
    ui->actionMovie->setEnabled(status);
    ui->actionFlower->setEnabled(status);
    ui->actionClassic->setEnabled(status);
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
    ui->menuGray_change->setEnabled(status);
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

void MainWindow::updateRightImage(QPixmap &pixmap){


    rightPixmapItem->setPixmap(pixmap);
    rightScene->setSceneRect(QRectF(pixmap.rect()));

    size->setText(QString::number(rightPixmapItem->pixmap().width())
                  + " x " + QString::number(rightPixmapItem->pixmap().height()));
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
        oriMat = nowMat;
        QPixmap leftPixmap=myfactory.getPixmap(nowMat);

    if (!imagePath.isEmpty())
    {
        cleanImage();
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

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionVertical_triggered(){

    prMat = nowMat;
    nowMat = prMat.Flip(1);
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);


    rightPixmapItem = rightScene->addPixmap(rightPixmap);
    rightScene->setSceneRect(QRectF(rightPixmap.rect()));

    size->setText(QString::number(rightPixmapItem->pixmap().width())
                  + " x " + QString::number(rightPixmapItem->pixmap().height()));
}

void MainWindow::on_actionHorizontal_triggered(){
    prMat = nowMat;
    nowMat = prMat.Flip(0);
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);

    rightPixmapItem = rightScene->addPixmap(rightPixmap);
    rightScene->setSceneRect(QRectF(rightPixmap.rect()));

    size->setText(QString::number(rightPixmapItem->pixmap().width())
                  + " x " + QString::number(rightPixmapItem->pixmap().height()));
}

void MainWindow::on_actionRevocation_triggered(){
    QPixmap rightPixmap=myfactory.getPixmap(prMat);

    updateRightImage(rightPixmap);
    ui->rightGraphicsView->resetTransform();

    nowMat = prMat;
}

void MainWindow::on_actionRestore_triggered(){
    QPixmap rightPixmap=myfactory.getPixmap(oriMat);

    updateRightImage(rightPixmap);
    ui->rightGraphicsView->resetTransform();

    prMat = oriMat;
    nowMat = prMat;
}

void MainWindow::on_actionBig_triggered(){
    prMat = nowMat;
    int h =(int)prMat.height*1.2;
    int w = (int)prMat.height*1.2;
    nowMat = prMat.Resize(h,w);
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);

    updateRightImage(rightPixmap);
}

void MainWindow::on_actionSmall_triggered(){
    prMat = nowMat;
    int h =(int)prMat.height*0.8;
    int w = (int)prMat.height*0.8;
    nowMat = prMat.Resize(h,w);
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);

    updateRightImage(rightPixmap);
}

void MainWindow::on_actionRotate_triggered(){

    bool ok;
    int factor = QInputDialog::getInt(this, tr("旋转"), "请输入要旋转的角度",0,-360,360,10,&ok);
    if (ok)
    {
        if (factor != 0)
        {
            prMat = nowMat;
            nowMat = prMat.Rotate(factor);
            QPixmap rightPixmap=myfactory.getPixmap(nowMat);
            updateRightImage(rightPixmap);
        }
        else
        {
            return;
        }
    }

}
void MainWindow::on_actionAdjust_brightness_triggered()
{

    bool ok;
    int delta = QInputDialog::getInt(this,
                                     tr("改变亮度"),
                                     "输入调整的亮度百分比(+/-)",
                                     0,-100,100,10,&ok);
    if (ok)
    {
        if (delta != 0)
        {
            prMat = nowMat;
            nowMat = prMat.Mult_all(1.0+(1.0*delta/100));
            QPixmap rightPixmap=myfactory.getPixmap(nowMat);
            updateRightImage(rightPixmap);

        }
        else
        {
            return;
        }
    }
}
void MainWindow::on_actionCold_triggered()
{
    prMat = nowMat;
    nowMat = prMat.Mult(1.2,2);
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);
    updateRightImage(rightPixmap);
}

void MainWindow::on_actionWorm_triggered()
{
    prMat = nowMat;
    nowMat = prMat.Mult(1.2,0);
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);
    updateRightImage(rightPixmap);
}

void MainWindow::on_actionSelf_triggered(){

    QColor color = QColorDialog::getColor(Qt::red,this,
                                          tr("请选择滤镜颜色"));
    prMat = nowMat;
    nowMat = prMat.Mymix(color.green(),color.red(),color.blue());
    QPixmap rightPixmap=myfactory.getPixmap(nowMat);
    updateRightImage(rightPixmap);
}

