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

unsigned int TeamManager::createTeam(std::string name, Bracket bracket) {
    if (name.size() == 0 || nameInUse(name))
        return 0;

    Team* const team = new Team(name, bracket);
    unsigned int id = 1;
    if (idToTeamMap_.size() != 0)
        id = (idToTeamMap_.rbegin()->first) + 1;

    idToTeamMap_.emplace(id, team);
    teamToIdMap_.emplace(team, id);

    return id;
}

bool TeamManager::deleteTeam(Team* team) {
    if (!team)
        return false;

    unsigned int id = getId(team);
    idToTeamMap_.erase(id);
    teamToIdMap_.erase(team);
    delete(team);
    return true;
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

bool TeamManager::setName(Team *team, std::string name) const {
    if (!team || name.size() == 0)
        return false;

    if (name == team->getName())
        return true;

    if (nameInUse(name))
        return false;

    team->name_ = name;
    return true;
}

bool TeamManager::setBracket(Team *team, Bracket bracket) const {
    if (!team)
        return false;

    if (team->athletes_.size() != 0 && team->bracket_ != bracket)
        return false;

    team->bracket_ = bracket;
    return true;
}

bool TeamManager::addClub(Team *team, Club *club) const {
    if (!team || !club)
        return false;

    team->clubs_.insert(club);
    return true;
}

bool TeamManager::removeClub(Team *team, Club *club) const {
    if (!team || !club)
        return false;

    for (unsigned int i = 0; i < team->athletes_.size(); i++)
        if (team->athletes_.at(i)->getClub() == club)
            return false;

    team->clubs_.erase(club);
    return true;
}

bool TeamManager::addAthlete(Team *team, Athlete *athlete) const {
    if (!team || !athlete)
        return false;

    if (team->clubs_.count(athlete->getClub()) == 0)
        return false;

    for (unsigned int i = 0; i < team->athletes_.size(); i++)
        if (team->athletes_.at(i) == athlete)
            return false;

    team->athletes_.push_back(athlete);
    return true;
}

bool TeamManager::removeAthlete(Team *team, Athlete *athlete) const {
    if (!team || !athlete)
        return false;

    for (unsigned int i = 0; i < team->athletes_.size(); i++)
        if (team->athletes_.at(i) == athlete)
            team->athletes_.erase(team->athletes_.begin() + i);

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
