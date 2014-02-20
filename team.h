#ifndef TEAM_H
#define TEAM_H

#include "meeting.h"
#include "club.h"
#include "athlete.h"

#include <vector>
#include <unordered_set>

namespace kilas {

/**
 * @brief Each instance of the Team class represents a team that is competing in one of the competitions.
 *
 * A Team should only be created using TeamManager::createTeam() and destroyed by using
 * TeamManager::deleteClub() to assure that the IDs are handled correctly.
 * The name of each Team is unique within its competition.
 */
class Team {
    friend class TeamManager;
    friend class TEST;
public:
    /**
     * @brief Returns the name of this Team.
     * @return The name of this Team.
     */
    std::string getName() const;

    /**
     * @brief Returns the Bracket of this Team.
     * @return The Bracket of this Team.
     */
    Bracket getBracket() const;

    /**
     * @brief Returns the clubs of this Team.
     * @return The clubs of this Team.
     */
    std::unordered_set<Club*> getClubs() const;

    /**
     * @brief Returns a vector with pointers to the athletes of this Team.
     * @return A vector with pointers to the athletes of this Team.
     */
    std::vector<Athlete*> getAthletes() const;

private:
    /**
     * @brief Use TeamManager::createTeam() instead.
     */
    Team(std::string name, Bracket bracket);

    /**
     * @brief The name of this Team.
     */
    std::string name_;

    /**
     * @brief The Bracket this team competes in.
     */
    Bracket bracket_;

    /**
     * @brief The Club or clubs this Team belongs to.
     */
    std::unordered_set<Club*> clubs_;

    /**
     * @brief The athletes that are part of this Team.
     *
     * To be considered valid for the standings size of athletes_ has to be between 6 and 11.
     */
    std::vector<Athlete*> athletes_;
};

/**
 * @brief The compare_team struct is used to compare two teams.
 */
struct compare_team {
    /**
     * @brief operator () returns true if name of the first Team < name of the second Team
     * @param a The first Team
     * @param b The second Team
     * @return true if name of a < name of b, false else.
     */
    bool operator() (Team* const a, Team* const b) const {
        if (a->getName() < b->getName())
            return true;
        else
            return false;
    }
};

} //namespace kilas

#endif // TEAM_H
