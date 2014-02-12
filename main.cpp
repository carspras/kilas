#include "mainwindow.h"
#include <QApplication>

#include "globals.h"
#include "clubmanager.h"
#include "club.h"

#include <iostream>

int main(int argc, char *argv[])
{
    int firstid = clubmanager->createClub("first");
    int secondid = clubmanager->createClub("second");
    std::cout << "First ID: " << firstid << std::endl;
    std::cout << "Second ID: " << secondid << std::endl;

    Club firstClub = *clubmanager->getClub(firstid);
    std::cout << "Name of firstClub: " << firstClub.getName() << std::endl;
    std::cout << "ID of firstClub: " << clubmanager->getId(&firstClub) << std::endl;

    std::cout << "Deletion of firstClub: " << clubmanager->deleteClub(&firstClub) << std::endl;
    std::cout << "ID of firstClub: " << clubmanager->getId(&firstClub) << std::endl;

    std::cout << "ID for 'first': " << clubmanager->createClub("first") << std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
