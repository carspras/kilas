#include "clubmanager.h"

#include <iostream>

using namespace kilas;

ClubManager::ClubManager() {
}

unsigned int ClubManager::clubCount() const {
    if (idToClubMap_.size() == clubToIdMap_.size())
        return idToClubMap_.size();
    else
        return 0;
}

unsigned int ClubManager::createClub(std::string name) {
    if (name.size() == 0 || nameInUse(name))
        return 0;

    Club* const club = new Club(name);
    unsigned int id = 1;
    if (idToClubMap_.size() != 0)
        id = (idToClubMap_.rbegin()->first) + 1;

    idToClubMap_.emplace(id, club);
    clubToIdMap_.emplace(club, id);

    return id;
}

bool ClubManager::deleteClub(unsigned int id) {
    Club* const club = getClub(id);
    if (club) {
        idToClubMap_.erase(id);
        clubToIdMap_.erase(club);
        delete(club);
        return true;
    }

    return false;
}

bool ClubManager::deleteClub(Club* const club) {
    unsigned int id = getId(club);
    if (id) {
        clubToIdMap_.erase(club);
        idToClubMap_.erase(id);
        delete(club);
        return true;
    }

    return false;
}

unsigned int ClubManager::getId(Club* const club) const {
    if (clubToIdMap_.count(club) == 1)
        return clubToIdMap_.at(club);
    return 0;
}

Club* ClubManager::getClub(unsigned int id) const {
    if (idToClubMap_.count(id) == 1)
        return idToClubMap_.at(id);
    return nullptr;
}

bool ClubManager::setNewName(Club* club, std::string newName) const {
    if (!club || newName.size() == 0)
        return false;

    if (newName == club->getName())
        return true;

    if (nameInUse(newName))
        return false;

    club->name_ = newName;
    return true;
}

bool ClubManager::nameInUse(std::string name) const {
    if (clubToIdMap_.size() == 0)
        return false;

    for (std::pair<Club* const, unsigned int> pair : clubToIdMap_) {
        if (pair.first->getName() == name)
            return true;
    }

    return false;
}
