#include "athletemanager.h"

using namespace kilas;

AthleteManager::AthleteManager() {
}

unsigned int AthleteManager::athleteCount() const {
    if (athleteToIdMap_.size() == idToAthleteMap_.size())
        return idToAthleteMap_.size();
    else
        return 0;
}

int AthleteManager::createAthlete(unsigned short number) {
    if (number == 0 || numberInUse(number))
        return -1;

    Athlete* const athlete = new Athlete(number);
    int id = 0;
    if (idToAthleteMap_.size() != 0)
        id = (idToAthleteMap_.rbegin()->first) + 1;

    idToAthleteMap_.emplace(id, athlete);
    athleteToIdMap_.emplace(athlete, id);

    athlete->name_ = "";
    athlete->yearOfBirth_ = 0;
    athlete->club_ = nullptr;

    return id;
}

int AthleteManager::createAthlete(unsigned short number, std::string name) {
    int id = createAthlete(number);

    if (id >= 0)
        getAthlete(id)->name_ = name;

    return id;
}

int AthleteManager::createAthlete(unsigned short number, std::string name,
                                  unsigned short yob) {
    int id = createAthlete(number, name);

    if (id >= 0)
        getAthlete(id)->yearOfBirth_ = yob;

    return id;
}

int AthleteManager::createAthlete(unsigned short number, std::string name,
                                  unsigned short yob, Club* club) {
    int id = createAthlete(number, name, yob);

    if (id >= 0)
        getAthlete(id)->club_ = club;

    return id;
}

bool AthleteManager::deleteAthlete(int id) {
    Athlete* const athlete = getAthlete(id);
    if (athlete) {
        idToAthleteMap_.erase(id);
        athleteToIdMap_.erase(athlete);
        delete(athlete);
        return 1;
    }

    return 0;
}

bool AthleteManager::deleteAthlete(Athlete* const athlete) {
    int id = getId(athlete);
    if (id != -1) {
        idToAthleteMap_.erase(id);
        athleteToIdMap_.erase(athlete);
        delete(athlete);
        return 1;
    }

    return 0;
}

int AthleteManager::getId(Athlete * const athlete) const {
    if (athleteToIdMap_.count(athlete) == 1)
        return athleteToIdMap_.at(athlete);

    return -1;
}

Athlete* AthleteManager::getAthlete(int id) const {
    if (idToAthleteMap_.count(id) == 1)
        return idToAthleteMap_.at(id);

    return nullptr;
}

bool AthleteManager::numberInUse(unsigned short number) const {
    if (athleteToIdMap_.size() == 0)
        return 0;

    for (std::pair<Athlete* const, int> pair: athleteToIdMap_) {
        if (pair.first->getNumber() == number)
            return 1;
    }

    return 0;
}
