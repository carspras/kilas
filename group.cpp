#include "group.h"

using namespace kilas;

Group::Group() {
}

std::vector<Team*> Group::getTeams() const {
    return teams_;
}

bool Group::addTeam(Team * const team) {
    if (!team)
        return false;

    teams_.push_back(team);
    return true;
}

bool Group::removeTeam(Team * const team) {
    if (!team)
        return false;

    for (unsigned int i = 0; i < teams_.size(); i++) {
        if (teams_.at(i) == team) {
            teams_.erase(teams_.begin() + i);
            return true;
        }
    }
    return false;
}
