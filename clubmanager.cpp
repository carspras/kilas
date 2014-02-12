#include "clubmanager.h"

#include <iostream>

ClubManager::ClubManager()
{
}

unsigned int ClubManager::createClub(std::string name) {
    if (nameInUse(name))
        return 0;

    Club* club = new Club(name);
    unsigned int id = 1;
    if (idToClubMap_.size() != 0)
        id = (idToClubMap_.rbegin()->first) + 1;

    idToClubMap_.emplace(id, club);
    clubToIdMap_.emplace(club, id);

    return id;
}

bool ClubManager::deleteClub(unsigned int id) {
    int found = idToClubMap_.erase(id);
    if (found) {
        const Club* club = getClub(id);
        clubToIdMap_.erase(club);
        delete(club);
        return true;
    } else
        return false;
}

bool ClubManager::deleteClub(const Club* club) {
    int found = clubToIdMap_.erase(club);

    if (found) {
        idToClubMap_.erase(getId(club));
        delete(club);
        return true;
    } else
        return false;
}

unsigned int ClubManager::getId(const Club* club) {
    if (clubToIdMap_.find(club) != clubToIdMap_.end())
        return clubToIdMap_[club];
    else
        return 0;
}

const Club* ClubManager::getClub(unsigned int id) {
    if (idToClubMap_.find(id) != idToClubMap_.end())
        return idToClubMap_[id];
    else
        return nullptr;
}

bool ClubManager::nameInUse(std::string name) const {
    if (clubToIdMap_.size() == 0)
        return false;

    for (std::pair<const Club*, unsigned int> pair : clubToIdMap_) {
        if (pair.first->getName() == name)
            return true;
    }

    return false;
}
