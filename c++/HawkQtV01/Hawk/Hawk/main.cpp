#include "hawk.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Hawk w;
	w.show();
	return a.exec();

	
}
