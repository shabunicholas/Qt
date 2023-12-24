#pragma once

#include <QWidget>
#include "ui_UserLogin.h"
#include"WindowBase.h"
class UserLogin : public WindowBase
{
	Q_OBJECT

public:
	UserLogin(QWidget *parent = nullptr);
	~UserLogin();

private:
	Ui::UserLoginClass ui;
};
