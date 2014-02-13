#include "test.h"

#include "globals.h"

#include <iostream>

TEST::TEST() {
}

using namespace std;

void TEST::test() {
    TEST::testClubManager();
    TEST::testAthleteManager();
}

void TEST::testClubManager() {
    cout << "<<---- Testing of class ClubManager ---->>" << endl;
    cout << "Testing createClub()" << endl;
    cout << "createClub(''): " << clubmanager->createClub("") << " (0)" << endl;
    cout << "createClub('Recklinghäuser LC'): " << clubmanager->createClub("Recklinghäuser LC") << " (1)" << endl;
    cout << "createClub('Recklinghäuser LC'): " << clubmanager->createClub("Recklinghäuser LC") << " (0)" << endl;
    cout << "createClub('LA SV Herten'): " << clubmanager->createClub("LA SV Herten") << " (2)" << endl;
    cout << "createClub('LG Dorsten'): " << clubmanager->createClub("LG Dorsten") << " (3)" << endl;
    cout << "clubCount(): " << clubmanager->clubCount() << " (3)" << endl;
    cout << endl;

    cout << "Testing deleteClub(unsigned int id)" << endl;
    cout << "deleteClub(42): " << clubmanager->deleteClub(42) << " (0)" << endl;
    cout << "deleteClub(3): " << clubmanager->deleteClub(3) << " (1)" << endl;
    cout << "clubCount(): " << clubmanager->clubCount() << " (2)" << endl;
    cout << endl;

    cout << "Testing deleteClub(Club* const club)" << endl;
    Club* const firstClub = clubmanager->getClub(1);
    cout << "deleteClub(new Club('Test')): " << clubmanager->deleteClub(new Club("Test")) << " (0)" << endl;
    cout << "deleteClub(firstClub): " << clubmanager->deleteClub(firstClub) << " (1)" << endl;
    cout << "clubCount(): " << clubmanager->clubCount() << " (1)" << endl;
    cout << endl;

    cout << "Testing getId(Club* const club)" << endl;
    cout << "getId(new Club('Test')): " << clubmanager->getId(new Club("Test")) << " (0)" << endl;
    Club* const secondClub = clubmanager->getClub(2);
    cout << "getId(secondClub): " << clubmanager->getId(secondClub) << " (2)" << endl;
    cout << endl;

    cout << "Testing getClub(unsigned int id)" << endl;
    cout << "getClub(42): " << clubmanager->getClub(42) << " (0)" << endl;
    cout << "getClub(2)->getName(): " << clubmanager->getClub(2)->getName() << " ('LA SV Herten')" << endl;
    cout << endl;

    cout << "Testing setNewName(Club* club, std::string newName)" << endl;
    cout << "createClub('SuS Bertlich'): " << clubmanager->createClub("SuS Bertlich") << " (3)" << endl;
    cout << "setNewName(nullptr, ''): " << clubmanager->setNewName(nullptr, "") << " (0)" << endl;
    cout << "setNewName(secondClub, ''): " << clubmanager->setNewName(secondClub, "") << " (0)" << endl;
    cout << "setNewName(secondClub, 'SuS Bertlich'): " << clubmanager->setNewName(secondClub, "SuS Bertlich") << " (0)" << endl;
    cout << "setNewName(secondClub, 'TuS 09 Erkenschwick'): " << clubmanager->setNewName(secondClub, "TuS 09 Erkenschwick") << " (1)" << endl;
    cout << endl;
}

void TEST::testAthleteManager() {
    cout << "<<---- Testing of class AthleteManager ---->>" << endl;
    cout << "Testing createAthlete(unsigned short number)" << endl;
    cout << "createAthlete(0): " << athletemanager->createAthlete(0) << " (-1)" << endl;
    cout << "createAthlete(1): " << athletemanager->createAthlete(1) << " (0)" << endl;
    cout << "createAthlete(1): " << athletemanager->createAthlete(1) << " (-1)" << endl;
    cout << "createAthlete(2): " << athletemanager->createAthlete(2) << " (1)" << endl;
    cout << "createAthlete(3): " << athletemanager->createAthlete(3) << " (2)" << endl;
    cout << "athleteCount(): " << athletemanager->athleteCount() << " (3)" << endl;
    cout << endl;

    cout << "Testing createAthlete(unsigned short number, std::string name)" << endl;
    cout << "createAthlete(0, 'Hans'): " << athletemanager->createAthlete(0, "Hans") << " (-1)" << endl;
    cout << "createAthlete(1, 'Hans'): " << athletemanager->createAthlete(1, "Hans") << " (-1)" << endl;
    cout << "createAthlete(4, 'Hans'): " << athletemanager->createAthlete(4, "Hans") << " (3)" << endl;
    cout << "getAthlete(3)->getName(): " << athletemanager->getAthlete(3)->getName() << " ('Hans')" << endl;
    cout << "athleteCount(): " << athletemanager->athleteCount() << " (4)" << endl;
    cout << endl;

    cout << "Testing createAthlete(unsigned short number, std::string name, unsigned short yob)" << endl;
    cout << "createAthlete(5, 'Wilhelm', 1986): " << athletemanager->createAthlete(5, "Wilhelm", 1986) << " (4)" << endl;
    cout << "getAthlete(4)->getName(): " << athletemanager->getAthlete(4)->getName() << " ('Wilhelm')" << endl;
    cout << "getAthlete(4)->getYOB(): " << athletemanager->getAthlete(4)->getYOB() << " (1986)" << endl;
    cout << "athleteCount(): " << athletemanager->athleteCount() << " (5)" << endl;
    cout << endl;

    cout << "Testing createAthlete(unsigned short number, std::string name, unsigned short yob, Club* club)" << endl;
    Club* const testClub = clubmanager->getClub(3);
    cout << "createAthlete(6, 'Peter', 1995, testClub): " << athletemanager->createAthlete(6, "Peter", 1995, testClub) << " (5)" << endl;
    cout << "getAthlete(5)->getName(): " << athletemanager->getAthlete(5)->getName() << " ('Peter')" << endl;
    cout << "getAthlete(5)->getYOB(): " << athletemanager->getAthlete(5)->getYOB() << " ('1995')" << endl;
    cout << "getAthlete(5)->getClub()->getName(): " << athletemanager->getAthlete(5)->getClub()->getName() << " ('SuS Bertlich')" << endl;
    cout << "athletecount(): " << athletemanager->athleteCount() << " (6)" << endl;
    cout << endl;

    cout << "Testing deleteAthlete(int id)" << endl;
    cout << "deleteAthlete(42): " << athletemanager->deleteAthlete(42) << " (0)" << endl;
    cout << "deleteAthlete(0): " << athletemanager->deleteAthlete(0) << " (1)" << endl;
    cout << "athletecount(): " << athletemanager->athleteCount() << " (5)" << endl;
    cout << endl;

    cout << "Testing deleteAthlete(Athlete* const athlete)" << endl;
    cout << "deleteAthlete(new Athlete()): " << athletemanager->deleteAthlete(new Athlete(42)) << " (0)" << endl;
    cout << "deleteAthlete(getAthlete(1)): " << athletemanager->deleteAthlete(athletemanager->getAthlete(1)) << " (1)" << endl;
    cout << "athletecount(): " << athletemanager->athleteCount() << " (4)" << endl;
    cout << endl;
}
