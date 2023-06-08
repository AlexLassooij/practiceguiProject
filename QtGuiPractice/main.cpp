#include "QtGuiPractice.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	// create new application
    QApplication a(argc, argv);
	// instantiate new window
    QtGuiPractice w;
    w.show();
    return a.exec();
}
