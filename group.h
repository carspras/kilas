#ifndef GROUP_H
#define GROUP_H

#include "team.h"

#include <vector>
#include <list>

namespace kilas {

/**
 * @brief Each Group consists of the teams in a Competition that do their events
 * together at the same time.
 *
 * Each Group is part of a Competition.
 */
class Group {
public:
    Group();

    /**
     * @brief Returns the teams in this Group.
     * @return The teams in this group.
     */
    std::vector<Team*> getTeams() const;

    /**
     * @brief Adds the team to this group.
     * @param team The Team to be added to this Group.
     * @return true if the Team was successfully added, false else.
     */
    bool addTeam(Team* const team);

    /**
     * @brief Removes the team from this group if possible.
     * @param team The Team to be removed from this Group.
     * @return true if the Team could be removed, false else.
     */
    bool removeTeam(Team* const team);
private:
    /**
     * @brief The teams that are doing their events together.
     */
    std::vector<Team*> teams_;
};

} //namespace kilas

#endif // GROUP_H
