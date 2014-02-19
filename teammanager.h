#ifndef TEAMMANAGER_H
#define TEAMMANAGER_H

#include "team.h"

#include <map>

namespace kilas {

/**
 * @brief The TeamManager class manages the creation and deletion of teams.
 *
 * Assigns every Team a unique ID and assures that the name of every Team is unique.
 * New teams should only be created using TeamManager::createTeam() and deleted using
 * TeamManager::deleteTeam().
 */
class TeamManager {
public:
    TeamManager();

    /**
     * @brief teamCount returns the count of teams registered with the TeamManager.
     * @return Count of the teams.
     */
    unsigned int teamCount() const;

    /**
     * @brief Creates a new Team with a unique ID.
     * @param name Name of the new Team.
     * @return Unique ID of the new Team, 0 if the name was already in use.
     *
     * If the specified name is already in use or if name is empty, no new
     * Team is created and the return value is 0.
     */
    unsigned int createTeam(std::string name);

    /**
     * @brief Deletes the Team with the specified ID.
     * @param id The Id of the to be deleted Team.
     * @return false if no Club with the ID was found.
     */
    bool deleteTeam(unsigned int id);

    /**
     * @brief Returns the ID of the specified Team.
     * @param team
     * @return The ID of the specified Team; 0 if the Team is not found.
     */
    unsigned int getId(Team* const team) const;

    /**
     * @brief Returns a pointer to the Team with the specified ID.
     * @param id The ID of the Team.
     * @return The Team to the specified ID; nullptr if the ID is not in use.
     */
    Team* getTeam(unsigned int id) const;

    /**
     * @brief Sets newName as the name for team, if that name is not already in use.
     * @param team
     * @param newName The new name for team.
     * @return true if the name is not already in use, false else.
     */
    bool setNewName(Team* team, std::string newName) const;

private:
    /**
     * @brief Checks if the specified name is already in use.
     * @param name The name to be checked.
     * @return true if the name is already in use, false else
     */
    bool nameInUse(std::string name) const;

    /**
     * @brief teamToIdMap_ is the map from the teams to the corresponding IDs.
     */
    std::map<Team* const, unsigned int, compare_team> teamToIdMap_;

    /**
     * @brief idToTeamMap_ is the map from the team-IDs to the corresponding teams.
     */
    std::map<unsigned int, Team* const> idToTeamMap_;
};

} //namespace kilas

#endif // TEAMMANAGER_H
