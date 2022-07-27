#include "attandenceclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AttandenceClient w;
    w.show();
    return a.exec();
}
