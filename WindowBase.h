#pragma once

#include "TilleBar.h"
#include"Notifi.h"
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
class WindowBase  : public QWidget
{
	Q_OBJECT

public:
	WindowBase(QWidget *parent=nullptr);
	~WindowBase();

	void setTitleContent(const QString &text, const QString &icon,TypeBtn type)const;
	//º”‘ÿÕ∑œÒ
	QPixmap loadRoundHeader(QPixmap &mask, const QPixmap &src,QSize size);
	void loadSheetStyle(const QString &path);
private:
	void initConnect();
	void initBack();
	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);

private slots:
	void onMax();
	void onMin();
	void onClose();
	void onRes();
	void onSkinChange(const QColor &color);
protected:
	TitleBar *m_titleBar;
	bool m_press;
	QColor m_backgroundColor;
	QString m_style;
	QPoint m_pointStart;

};
