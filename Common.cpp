#include "Common.h"
#include<QFile>
Common::Common(QObject *parent)
	: QObject(parent)
{}

Common::~Common()
{}

QColor Common::getInI()
{
	QString file("tradeprintinfo.ini");

	QSettings sett(file, QSettings::IniFormat);
	int red = sett.value("DefaultSkin/red").toInt();
	int green = sett.value("DefaultSkin/green").toInt();
	int blue = sett.value("DefaultSkin/blue").toInt();

	return QColor(red, green, blue);
}

void Common::setInI(const QColor &color)
{
	QString file("tradeprintinfo.ini");
	QSettings sett(file, QSettings::IniFormat);

	sett.setValue("DefaultSkin/red",color.red());
	sett.setValue("DefaultSkin/green", color.green());
	sett.setValue("DefaultSkin/blue", color.blue());
}
