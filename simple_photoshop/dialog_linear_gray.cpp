#include "dialog_linear_gray.h"
#include "ui_dialog_linear_gray.h"

Dialog_linear_gray::Dialog_linear_gray(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_linear_gray)
{
    ui->setupUi(this);
}

Dialog_linear_gray::~Dialog_linear_gray()
{
    delete ui;
}
