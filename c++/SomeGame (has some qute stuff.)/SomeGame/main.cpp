#include "somegame.h"
#include <QtWidgets/QApplication>
#include "controller.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller testCtrl;
	SomeGame w(testCtrl);
	w.show();
	Controller test;
	std::string testWord = "dicks";
	testWord = test.scramble(testWord);
	
	return a.exec();
}
