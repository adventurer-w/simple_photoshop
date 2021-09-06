#ifndef DIALOG_LINEAR_GRAY_H
#define DIALOG_LINEAR_GRAY_H

#include <QDialog>

namespace Ui {
class Dialog_linear_gray;
}

class Dialog_linear_gray : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_linear_gray(QWidget *parent = nullptr);
    ~Dialog_linear_gray();

private:
    Ui::Dialog_linear_gray *ui;
};

#endif // DIALOG_LINEAR_GRAY_H
