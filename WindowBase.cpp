#include "WindowBase.h"
#include<QStyle>
#include<QStyleOption>
#include"Common.h"
WindowBase::WindowBase(QWidget *parent)
	: QWidget(parent),m_press(false)
{
	m_titleBar = new TitleBar(this);
	m_backgroundColor = Common::getInI();
	
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	initConnect();

	connect(Notifi::getNotifi(), &Notifi::skinChange, this, &WindowBase::onSkinChange);


	resize(500, 500);
	setTitleContent("hello Linux!", ":/Resources/MainWindow/app/logo.ico", MAX_MIN_CLOSE);
}

WindowBase::~WindowBase()
{}

void WindowBase::setTitleContent(const QString & text, const QString & icon,TypeBtn type) const
{
	m_titleBar->setBtnType(type);
	m_titleBar->setTitleContent(text);
	m_titleBar->setTileIcon(icon);
}

QPixmap WindowBase::loadRoundHeader(QPixmap & mask, const QPixmap & src,QSize size)
{
	if (size == QSize(0, 0)) {
		size = mask.size();
	}
	else {
		mask=mask.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	}
	
	QImage res(size, QImage::Format_ARGB32_Premultiplied);
	QPainter painter(&res);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.fillRect(res.rect(),Qt::transparent);
	
	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	painter.drawPixmap(0, 0, mask);

	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	painter.drawPixmap(0, 0, src.scaled(size,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	painter.end();

	return QPixmap::fromImage(res);
}

void WindowBase::loadSheetStyle(const QString & path)
{
	QFile file(":/Resources/QSS/" + path + ".css");
	file.open(QIODevice::ReadOnly);

	if (file.isOpen()) {
		setStyleSheet("");
		QString style= QLatin1Literal(file.readAll());

		int r=m_backgroundColor.red();
		int g = m_backgroundColor.green();
		int b = m_backgroundColor.blue();

		style += QString("QWidget[skin==true]\
                        {background-color:rgb(%1,%2,%3)}")
			           .arg(r).arg(g).arg(b);
		setStyleSheet(style);
	}
}

void WindowBase::initConnect()
{
	connect(m_titleBar, &TitleBar::MaxBtn, this, &WindowBase::onMax);
	connect(m_titleBar, &TitleBar::MinBtn, this, &WindowBase::onMin);
	connect(m_titleBar, &TitleBar::CloseBtn, this, &WindowBase::onClose);
	connect(m_titleBar, &TitleBar::ResMax, this, &WindowBase::onRes);
}

void WindowBase::initBack()
{
	QPainter painter(this);
	QStyleOption op;
	style()->drawPrimitive(QStyle::PE_FrameFocusRect, &op, &painter, this);
}

void WindowBase::paintEvent(QPaintEvent * e)
{
	initBack();
	QWidget::paintEvent(e);
}

void WindowBase::mousePressEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton) {
		m_press = true;
		m_pointStart = e->globalPos() - pos();
	}
}

void WindowBase::mouseDoubleClickEvent(QMouseEvent * e)
{
	static int count = 0;
	if (!count) {
		showMaximized();
		count++;
	}else{
		showNormal();
		count--;
	}

}

void WindowBase::mouseReleaseEvent(QMouseEvent * e)
{
	m_press = false;
}

void WindowBase::mouseMoveEvent(QMouseEvent * e)
{
	if (m_press) {
		QPoint m = e->globalPos() - m_pointStart;
		move(m);
	}
}

void WindowBase::onMax() {
	showMaximized();
}

void WindowBase::onMin() {
	showMinimized();
}

void WindowBase::onClose() {
	close();
}

void WindowBase::onRes() {
	showNormal();
}

void WindowBase::onSkinChange(const QColor & color)
{
	m_backgroundColor = color;
	Common::setInI(color);
	loadSheetStyle(m_style);
}
