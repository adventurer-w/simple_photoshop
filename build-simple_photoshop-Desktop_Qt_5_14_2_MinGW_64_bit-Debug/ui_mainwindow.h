/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionRestore;
    QAction *actionBig;
    QAction *actionRotate;
    QAction *actionRevocation;
    QAction *actionHorizontal;
    QAction *actionVertical;
    QAction *actionLinear_transformation;
    QAction *actionBinaryzation;
    QAction *actionPower_transformation;
    QAction *actionFrame;
    QAction *actionCold;
    QAction *actionWorm;
    QAction *actionSimple;
    QAction *actionGauss;
    QAction *actionMeida_Filter;
    QAction *actionLaplace;
    QAction *actionAverage;
    QAction *actionAdjust_brightness;
    QAction *actionHistogram;
    QAction *actionGrayscale;
    QAction *actionSmall;
    QAction *actionSelf;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *rightGraphicsView;
    QGraphicsView *leftGraphicsView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menu_4;
    QMenu *menuGrey_Transfrom;
    QMenu *menuArtistic_Effect;
    QMenu *menu_6;
    QMenu *menuBlur;
    QMenu *menuFind;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1196, 711);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/wenjianjia1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/shangwutubiao-.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionRestore = new QAction(MainWindow);
        actionRestore->setObjectName(QString::fromUtf8("actionRestore"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/jurassic_restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestore->setIcon(icon3);
        actionBig = new QAction(MainWindow);
        actionBig->setObjectName(QString::fromUtf8("actionBig"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/fangdasuoxiao_X.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBig->setIcon(icon4);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/rotate-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon5);
        actionRevocation = new QAction(MainWindow);
        actionRevocation->setObjectName(QString::fromUtf8("actionRevocation"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/jurassic_laststep.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRevocation->setIcon(icon6);
        actionHorizontal = new QAction(MainWindow);
        actionHorizontal->setObjectName(QString::fromUtf8("actionHorizontal"));
        actionVertical = new QAction(MainWindow);
        actionVertical->setObjectName(QString::fromUtf8("actionVertical"));
        actionLinear_transformation = new QAction(MainWindow);
        actionLinear_transformation->setObjectName(QString::fromUtf8("actionLinear_transformation"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/tongjitu01.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLinear_transformation->setIcon(icon7);
        actionBinaryzation = new QAction(MainWindow);
        actionBinaryzation->setObjectName(QString::fromUtf8("actionBinaryzation"));
        actionPower_transformation = new QAction(MainWindow);
        actionPower_transformation->setObjectName(QString::fromUtf8("actionPower_transformation"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/tongjitubiao-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPower_transformation->setIcon(icon8);
        actionFrame = new QAction(MainWindow);
        actionFrame->setObjectName(QString::fromUtf8("actionFrame"));
        actionCold = new QAction(MainWindow);
        actionCold->setObjectName(QString::fromUtf8("actionCold"));
        actionWorm = new QAction(MainWindow);
        actionWorm->setObjectName(QString::fromUtf8("actionWorm"));
        actionSimple = new QAction(MainWindow);
        actionSimple->setObjectName(QString::fromUtf8("actionSimple"));
        actionGauss = new QAction(MainWindow);
        actionGauss->setObjectName(QString::fromUtf8("actionGauss"));
        actionMeida_Filter = new QAction(MainWindow);
        actionMeida_Filter->setObjectName(QString::fromUtf8("actionMeida_Filter"));
        actionLaplace = new QAction(MainWindow);
        actionLaplace->setObjectName(QString::fromUtf8("actionLaplace"));
        actionAverage = new QAction(MainWindow);
        actionAverage->setObjectName(QString::fromUtf8("actionAverage"));
        actionAdjust_brightness = new QAction(MainWindow);
        actionAdjust_brightness->setObjectName(QString::fromUtf8("actionAdjust_brightness"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/taiyang1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdjust_brightness->setIcon(icon9);
        actionHistogram = new QAction(MainWindow);
        actionHistogram->setObjectName(QString::fromUtf8("actionHistogram"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/tongjitu1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistogram->setIcon(icon10);
        actionGrayscale = new QAction(MainWindow);
        actionGrayscale->setObjectName(QString::fromUtf8("actionGrayscale"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/tongjitu.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGrayscale->setIcon(icon11);
        actionSmall = new QAction(MainWindow);
        actionSmall->setObjectName(QString::fromUtf8("actionSmall"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/image/fangdasuoxiao_Y.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSmall->setIcon(icon12);
        actionSelf = new QAction(MainWindow);
        actionSelf->setObjectName(QString::fromUtf8("actionSelf"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/image/\347\224\273\347\224\273.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelf->setIcon(icon13);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rightGraphicsView = new QGraphicsView(centralwidget);
        rightGraphicsView->setObjectName(QString::fromUtf8("rightGraphicsView"));

        horizontalLayout_2->addWidget(rightGraphicsView);

        leftGraphicsView = new QGraphicsView(centralwidget);
        leftGraphicsView->setObjectName(QString::fromUtf8("leftGraphicsView"));
        leftGraphicsView->setEnabled(true);

        horizontalLayout_2->addWidget(leftGraphicsView);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1196, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setGeometry(QRect(168, 116, 145, 189));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu_4 = new QMenu(menuEdit);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menuGrey_Transfrom = new QMenu(menubar);
        menuGrey_Transfrom->setObjectName(QString::fromUtf8("menuGrey_Transfrom"));
        menuArtistic_Effect = new QMenu(menubar);
        menuArtistic_Effect->setObjectName(QString::fromUtf8("menuArtistic_Effect"));
        menu_6 = new QMenu(menuArtistic_Effect);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        menu_6->setGeometry(QRect(648, 119, 145, 128));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/image/mofabang1.png"), QSize(), QIcon::Normal, QIcon::Off);
        menu_6->setIcon(icon14);
        menuBlur = new QMenu(menubar);
        menuBlur->setObjectName(QString::fromUtf8("menuBlur"));
        menuFind = new QMenu(menubar);
        menuFind->setObjectName(QString::fromUtf8("menuFind"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuGrey_Transfrom->menuAction());
        menubar->addAction(menuArtistic_Effect->menuAction());
        menubar->addAction(menuBlur->menuAction());
        menubar->addAction(menuFind->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionRevocation);
        menuEdit->addAction(actionRestore);
        menuEdit->addSeparator();
        menuEdit->addAction(actionBig);
        menuEdit->addAction(actionSmall);
        menuEdit->addAction(actionRotate);
        menuEdit->addAction(menu_4->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionAdjust_brightness);
        menu_4->addAction(actionHorizontal);
        menu_4->addAction(actionVertical);
        menuGrey_Transfrom->addAction(actionLinear_transformation);
        menuGrey_Transfrom->addAction(actionPower_transformation);
        menuGrey_Transfrom->addAction(actionBinaryzation);
        menuArtistic_Effect->addAction(menu_6->menuAction());
        menuArtistic_Effect->addAction(actionFrame);
        menu_6->addAction(actionCold);
        menu_6->addAction(actionWorm);
        menu_6->addAction(actionSelf);
        menuBlur->addAction(actionSimple);
        menuBlur->addAction(actionGauss);
        menuBlur->addSeparator();
        menuBlur->addAction(actionAverage);
        menuBlur->addAction(actionMeida_Filter);
        menuBlur->addSeparator();
        menuBlur->addAction(actionLaplace);
        menuFind->addAction(actionHistogram);
        menuFind->addAction(actionGrayscale);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\345\233\276\347\211\207", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionRestore->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
        actionBig->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
        actionRotate->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        actionRevocation->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
        actionHorizontal->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263", nullptr));
        actionVertical->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264", nullptr));
        actionLinear_transformation->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\200\247\345\217\230\346\215\242", nullptr));
        actionBinaryzation->setText(QCoreApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226", nullptr));
        actionPower_transformation->setText(QCoreApplication::translate("MainWindow", "\345\271\202\346\254\241\345\217\230\346\215\242", nullptr));
        actionFrame->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\275\261\347\233\270\346\241\206", nullptr));
        actionCold->setText(QCoreApplication::translate("MainWindow", "\345\206\267\350\211\262", nullptr));
        actionWorm->setText(QCoreApplication::translate("MainWindow", "\346\232\226\350\211\262", nullptr));
        actionSimple->setText(QCoreApplication::translate("MainWindow", "\347\256\200\345\215\225\346\250\241\347\263\212", nullptr));
        actionGauss->setText(QCoreApplication::translate("MainWindow", "\351\253\230\346\226\257\346\250\241\347\263\212", nullptr));
        actionMeida_Filter->setText(QCoreApplication::translate("MainWindow", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        actionLaplace->setText(QCoreApplication::translate("MainWindow", "\346\213\211\346\231\256\346\213\211\346\226\257\351\224\220\345\214\226", nullptr));
        actionAverage->setText(QCoreApplication::translate("MainWindow", "\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
        actionAdjust_brightness->setText(QCoreApplication::translate("MainWindow", "\344\272\256\345\272\246", nullptr));
        actionHistogram->setText(QCoreApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        actionGrayscale->setText(QCoreApplication::translate("MainWindow", "\347\201\260\345\272\246\345\233\276\345\203\217", nullptr));
        actionSmall->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
        actionSelf->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\347\277\273\350\275\254", nullptr));
        menuGrey_Transfrom->setTitle(QCoreApplication::translate("MainWindow", "\347\201\260\350\211\262\345\217\230\346\215\242", nullptr));
        menuArtistic_Effect->setTitle(QCoreApplication::translate("MainWindow", "\350\211\272\346\234\257\346\225\210\346\236\234", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262\346\273\244\351\225\234", nullptr));
        menuBlur->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\347\263\212\344\270\216\351\224\220\345\214\226", nullptr));
        menuFind->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
