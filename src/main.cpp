#include "include/calviz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calviz w;
    w.showMaximized();

    return a.exec();
}
