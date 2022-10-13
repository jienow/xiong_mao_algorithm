#include "qt_development01.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_development01 w;
    w.show();
    return a.exec();
}