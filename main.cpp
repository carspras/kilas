#include "mainwindow.h"
#include <QApplication>

#include "testing/test.h"

#include <iostream>

int main(int argc, char *argv[])
{
    TEST::test();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
