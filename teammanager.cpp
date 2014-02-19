#include "teammanager.h"

using namespace kilas;

TeamManager::TeamManager() {
}

unsigned int TeamManager::teamCount() const {
    if (idToTeamMap_.size() == teamToIdMap_.size())
        return idToTeamMap_.size();
    else
        return 0;
}

unsigned int TeamManager::createTeam(std::string name) {
    if (name.size() == 0 || nameInUse(name))
        return 0;

    Team* const team = new Team(name);
    unsigned int id = 1;
    if (idToTeamMap_.size() != 0)
        id = (idToTeamMap_.rbegin()->first) + 1;

    idToTeamMap_.emplace(id, team);
    teamToIdMap_.emplace(team, id);

    return id;
}

bool TeamManager::deleteTeam(unsigned int id) {
    Team* const team = getTeam(id);
    if (team) {
        idToTeamMap_.erase(id);
        teamToIdMap_.erase(team);
        delete(team);
        return true;
    }

    return false;
}

unsigned int TeamManager::getId(Team * const team) const {
    if (teamToIdMap_.count(team) == 1)
        return teamToIdMap_.at(team);
    return 0;
}

Team* TeamManager::getTeam(unsigned int id) const {
    if (idToTeamMap_.count(id) == 1)
        return idToTeamMap_.at(id);
    return nullptr;
}

bool TeamManager::setNewName(Team *team, std::string newName) const {
    if (!team || newName.size() == 0)
        return false;

    if (newName == team->getName())
        return true;

    if (nameInUse(newName))
        return false;

    team->name_ = newName;
    return true;
}

bool TeamManager::nameInUse(std::string name) const {
    if (teamToIdMap_.size() == 0)
        return false;

    for (std::pair<Team* const, unsigned int> pair : teamToIdMap_) {
        if (pair.first->getName() == name)
            return true;
    }

    return false;
}
