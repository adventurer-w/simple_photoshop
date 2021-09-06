#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createAction();
    createToolBar();

//    setActionStatus(false);
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

