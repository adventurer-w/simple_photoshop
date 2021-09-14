/********************************************************************************
** Form generated from reading UI file 'selectrectwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTRECTWIDGET_H
#define UI_SELECTRECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectRectWidget
{
public:

    void setupUi(QWidget *SelectRectWidget)
    {
        if (SelectRectWidget->objectName().isEmpty())
            SelectRectWidget->setObjectName(QString::fromUtf8("SelectRectWidget"));
        SelectRectWidget->resize(400, 300);

        retranslateUi(SelectRectWidget);

        QMetaObject::connectSlotsByName(SelectRectWidget);
    } // setupUi

    void retranslateUi(QWidget *SelectRectWidget)
    {
        SelectRectWidget->setWindowTitle(QCoreApplication::translate("SelectRectWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectRectWidget: public Ui_SelectRectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTRECTWIDGET_H
