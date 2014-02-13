#include "test.h"

#include "globals.h"

#include <iostream>

TEST::TEST() {
}

void TEST::testClubManager() {
    std::cout << "<<---- Testing of class ClubManager ---->>" << std::endl;
    std::cout << "Testing createClub()" << std::endl;
    std::cout << "createClub(''): " << clubmanager->createClub("") << " (0)" << std::endl;
    std::cout << "createClub('first'): " << clubmanager->createClub("first") << " (1)" << std::endl;
    std::cout << "createClub('first'): " << clubmanager->createClub("first") << " (0)" << std::endl;
    std::cout << "createClub('second'): " << clubmanager->createClub("second") << " (2)" << std::endl;
    std::cout << "createClub('third'): " << clubmanager->createClub("third") << " (3)" << std::endl;
    std::cout << "clubCount(): " << clubmanager->clubCount() << " (3)" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing deleteClub(unsigned int id)" << std::endl;
    std::cout << "deleteClub(42): " << clubmanager->deleteClub(42) << " (0)" << std::endl;
    std::cout << "deleteClub(3): " << clubmanager->deleteClub(3) << " (1)" << std::endl;
    std::cout << "clubCount(): " << clubmanager->clubCount() << " (2)" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing deleteClub(Club* const club)" << std::endl;
    Club* const firstClub = clubmanager->getClub(1);
    std::cout << "deleteClub(new Club('Test')): " << clubmanager->deleteClub(new Club("Test")) << " (0)" << std::endl;
    std::cout << "deleteClub(firstClub): " << clubmanager->deleteClub(firstClub) << " (1)" << std::endl;
    std::cout << "clubCount(): " << clubmanager->clubCount() << " (1)" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing getId(Club* const club)" << std::endl;
    std::cout << "getId(new Club('Test')): " << clubmanager->getId(new Club("Test")) << " (0)" << std::endl;
    Club* const secondClub = clubmanager->getClub(2);
    std::cout << "getId(secondClub): " << clubmanager->getId(secondClub) << " (2)" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing getClub(unsigned int id)" << std::endl;
    std::cout << "getClub(42): " << clubmanager->getClub(42) << " (0)" << std::endl;
    std::cout << "getClub(2): " << clubmanager->getClub(2)->getName() << " (second)" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing setNewName(Club* club, std::string newName)" << std::endl;
    std::cout << "createClub('fourth'): " << clubmanager->createClub("fourth") << " (3)" << std::endl;
    std::cout << "setNewName(nullptr, ''): " << clubmanager->setNewName(nullptr, "") << " (0)" << std::endl;
    std::cout << "setNewName(secondClub, ''): " << clubmanager->setNewName(secondClub, "") << " (0)" << std::endl;
    std::cout << "setNewName(secondClub, 'fourth'): " << clubmanager->setNewName(secondClub, "fourth") << " (0)" << std::endl;
    std::cout << "setNewName(secondClub, 'fifth'): " << clubmanager->setNewName(secondClub, "fifth") << " (1)" << std::endl;
    std::cout << std::endl;


    /*
    Club firstClub = *clubmanager->getClub(firstClubId);
    std::cout << "Name of firstClub: " << firstClub.getName() << std::endl;
    std::cout << "ID of firstClub: " << clubmanager->getId(&firstClub) << std::endl;

    std::cout << "Deletion of firstClub: " << clubmanager->deleteClub(&firstClub) << std::endl;
    std::cout << "ID of firstClub: " << clubmanager->getId(&firstClub) << std::endl;

    std::cout << "ID for 'first': " << clubmanager->createClub("first") << std::endl;
    */
}
