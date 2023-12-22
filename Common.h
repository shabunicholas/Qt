#pragma once

#include <QObject>
#include<QProxyStyle>
#include<QSettings>

class My_Style : public QProxyStyle{
public:
	void drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option
		, QPainter *painter, const QWidget *widget = nullptr)const {
		if (element == QStyle::PE_FrameFocusRect) {
			return;
		}
		QProxyStyle::drawPrimitive(element, option,painter,widget);
	}
};

class Common  : public QObject
{
	Q_OBJECT

public:
	Common(QObject *parent);
	~Common();

	static QColor getInI();
	static void setInI(const QColor &color);

};
