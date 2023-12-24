#pragma once

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>

enum TypeBtn
{
	MAX_MIN_CLOSE,
	MIN_CLOSE,
	CLOSE,
	ALL
};

class TitleBar  : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent=nullptr);
	~TitleBar();

	void setBtnType(TypeBtn typeBtn);
	void setTileIcon(const QString &path);
	void setTitleWidth(int width);
	void setTitleContent(const QString &string);

	void savePoint(const QPoint &point,const QSize size);
	void resPoint(QPoint &point,QSize size);
	TypeBtn getTypeBtn() {
		return m_typeBtn;
	}
private:
	void initControl();
	void initConnect();
	void loadSheetStyle(const QString &path);

	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
signals:
	void MaxBtn();
	void MinBtn();
	void CloseBtn();
	void ResMax();
private slots:
	void onMaxBtn();
	void onMinBtn();
	void onCloseBtn();
	void onResMax();

private:
	QPushButton *m_min;
	QPushButton *m_max;
	QPushButton *m_close;
	QPushButton *m_resMax;
	QLabel *m_icon;
	QLabel *m_content;

	//ÒÆ¶¯
	QPoint m_point;
	QSize m_size;
	QPoint m_startPos;

	bool m_press;
	QString m_tc;
	QHBoxLayout *m_layout;
	TypeBtn m_typeBtn;
};
