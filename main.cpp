#include "quize.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Quize w;
    w.show();
    return a.exec();
}
