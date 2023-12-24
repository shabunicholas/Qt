#include "TilleBar.h"
#include<QDebug>
#define BtnWid 64
#define BtnHig 64
#define Hidth 64
TitleBar::TitleBar(QWidget *parent)
	: QWidget(parent),m_press(false)
{
	initControl();
	setFixedHeight(Hidth);
	setWindowFlags(Qt::FramelessWindowHint);

	//setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_TranslucentBackground, true);
	loadSheetStyle("Title");
	initConnect();
}

TitleBar::~TitleBar()
{
}

void TitleBar::setBtnType(TypeBtn typeBtn)
{
	m_typeBtn = typeBtn;
	switch (typeBtn)
	{
	case MAX_MIN_CLOSE:
		m_resMax->setVisible(false);
		break;
	case MIN_CLOSE:
		m_max->setVisible(false);
		m_resMax->setVisible(false);
		break;
	case CLOSE:
		m_min->setVisible(false);
		m_max->setVisible(false);
		m_resMax->setVisible(false);
		break;
	default:
		break;
	}
}

void TitleBar::setTileIcon(const QString &path)
{
	QPixmap pix(path);
	m_icon->setFixedSize(pix.size());
	m_icon->setPixmap(pix);
}

void TitleBar::setTitleWidth(int width)
{
	setFixedWidth(width);
}

void TitleBar::setTitleContent(const QString & string)
{
	m_content->setText(string);
	m_tc = string;
}

void TitleBar::initConnect() 
{
	connect(m_max,&QPushButton::clicked, this, &TitleBar::onMaxBtn);
	connect(m_min, &QPushButton::clicked, this, &TitleBar::onMinBtn);
	connect(m_close, &QPushButton::clicked, this, &TitleBar::onCloseBtn);
	connect(m_resMax, &QPushButton::clicked,this, &TitleBar::onResMax);

}

void TitleBar::loadSheetStyle(const QString & path)
{
	QFile file(":/Resources/QSS/"+path+".css");

	file.open(QIODevice::ReadOnly);

	if (file.isOpen()) {
		QString style = styleSheet();
		style += QLatin1Literal(file.readAll());
		setStyleSheet(style);
	}
	file.close();
}

void TitleBar::initControl() {

	m_close =new QPushButton;
	m_max = new QPushButton;
	m_min = new QPushButton;
	m_resMax = new QPushButton;
	m_icon = new QLabel;
	m_content = new QLabel;


	m_close->setFixedSize(BtnWid, BtnHig);
	m_max->setFixedSize(BtnWid, BtnHig);
	m_min->setFixedSize(BtnWid, BtnHig);
	m_resMax->setFixedSize(BtnWid, BtnHig);
	m_content->setFixedHeight(BtnHig);
	m_close->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	m_close->setObjectName("ButtonClose");
	m_max->setObjectName("ButtonMax");
	m_min->setObjectName("ButtonMin");
	m_resMax->setObjectName("ButtonRestore");

	m_layout = new QHBoxLayout(this);
	m_layout->setMargin(0);
	m_layout->setSpacing(0);
	m_layout->addWidget(m_icon);
	m_layout->addWidget(m_content);
	m_layout->addWidget(m_min);
	m_layout->addWidget(m_max);
	m_layout->addWidget(m_resMax);
	m_layout->addWidget(m_close);
}

void TitleBar::savePoint(const QPoint &point, const QSize size)
{
	m_point = point;
	m_size = size;
}

void TitleBar::resPoint(QPoint & point, QSize size)
{
	point = m_point;
	size = m_size;
}


void TitleBar::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	QPainterPath painterPath;
	painterPath.setFillRule(Qt::WindingFill);
	painterPath.addRoundedRect(QRect(0,0,width(),height()),3,3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform,true);

	//painter.drawPath(painterPath);
	if (parentWidget()->width() != width()) {
		setFixedWidth(parentWidget()->width());
	}
	QWidget::paintEvent(e);
}

void TitleBar::mousePressEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton) {
		if (m_max->isVisible()) {
			m_press = true;
			m_startPos = e->globalPos();
		}
	}
	//QWidget::mousePressEvent(e);
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent * e)
{
	showMaximized();
}

void TitleBar::mouseReleaseEvent(QMouseEvent * e)
{
	m_press = false;
	//QWidget::mouseReleaseEvent(e);
}

void TitleBar::mouseMoveEvent(QMouseEvent * e)
{
	if (m_press) 
	{
		QPoint p = e->globalPos()-m_startPos;
		QPoint par = parentWidget()->pos();
		m_startPos = e->globalPos();
		parentWidget()->move(par.x()+p.x(),par.y()+p.y());
	}
	 //return QWidget::mouseMoveEvent(e);
}

void TitleBar::onMinBtn()
{
	emit MinBtn();
}

void TitleBar::onCloseBtn()
{
	emit CloseBtn();
}

void TitleBar::onResMax()
{
	/*if (m_typeBtn == MAX_MIN_CLOSE) 
	{*/
		m_max->setVisible(true);
		m_resMax->setVisible(false);
		emit ResMax();
	//}
}

void TitleBar::onMaxBtn() 
{
	/*if (m_typeBtn == MAX_MIN_CLOSE) 
	{*/
		m_max->setVisible(false);
		m_resMax->setVisible(true);
		emit MaxBtn();
	//}
}