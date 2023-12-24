/********************************************************************************
** Form generated from reading UI file 'CCMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCMAINWINDOW_H
#define UI_CCMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CCMainWindowClass)
    {
        if (CCMainWindowClass->objectName().isEmpty())
            CCMainWindowClass->setObjectName(QString::fromUtf8("CCMainWindowClass"));
        CCMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(CCMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CCMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CCMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CCMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CCMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CCMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CCMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CCMainWindowClass->setStatusBar(statusBar);

        retranslateUi(CCMainWindowClass);

        QMetaObject::connectSlotsByName(CCMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CCMainWindowClass)
    {
        CCMainWindowClass->setWindowTitle(QCoreApplication::translate("CCMainWindowClass", "CCMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CCMainWindowClass: public Ui_CCMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCMAINWINDOW_H
