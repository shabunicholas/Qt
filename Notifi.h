#pragma once

#include <QObject>

class Notifi  : public QObject
{
	Q_OBJECT

public:
	Notifi(QObject *parent=nullptr);
	~Notifi();
	static Notifi* getNotifi();



signals:
	void skinChange(const QColor &color);

//private slots:
//	void onSkinChange(const QColor &color);
private:
	static Notifi *notifi_;
};
