#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CCMainWindow.h"

class CCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CCMainWindow(QWidget *parent = nullptr);
    ~CCMainWindow();

private:
    Ui::CCMainWindowClass ui;
};
