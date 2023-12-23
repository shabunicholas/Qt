#include "Common.h"
#include<QFile>
#include<QCoreAppLication>
Common::Common(QObject *parent)
	: QObject(parent)
{}

Common::~Common()
{}

QColor Common::getInI()
{
	//QString file("tradeprintinfo.ini");
	const QString file = QString(QCoreApplication::applicationDirPath()+"/tradeprintinfo.ini");
	if (!QFile::exists(file)) {
		return QColor(102, 153, 248);
	}
	QSettings sett(file, QSettings::IniFormat);
	int red = sett.value("DefaultSkin/red").toInt();
	int green = sett.value("DefaultSkin/green").toInt();
	int blue = sett.value("DefaultSkin/blue").toInt();

	return QColor(red, green, blue);
}

void Common::setInI(const QColor &color)
{
	//QString file("tradeprintinfo.ini");
	const QString file = QString(QCoreApplication::applicationDirPath() + "/tradeprintinfo.ini");
	/*if (!QFile::exists(file)) {文件不存在会自己创建
		return;
	}*/
	QSettings sett(file, QSettings::IniFormat);

	sett.setValue("DefaultSkin/red",color.red());
	sett.setValue("DefaultSkin/green", color.green());
	sett.setValue("DefaultSkin/blue", color.blue());
}
