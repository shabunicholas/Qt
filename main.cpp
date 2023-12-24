#include "CCMainWindow.h"
#include <QtWidgets/QApplication>
#include"TilleBar.h"
#include"WindowBase.h"
#include"UserLogin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*CCMainWindow w;
    w.show();*/
	/*WindowBase w;
	w.show();*/
	UserLogin us;
	us.show();
    return a.exec();
}
