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
    unsigned int createTeam(std::string name, Bracket bracket);

    /**
     * @brief Deletes the Team
     * @param team
     * @return true if the team was deleted.
     */
    bool deleteTeam(Team* team);

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
     * @brief Sets name as the name for team, if that name is not already in use.
     * @param team
     * @param name The new name for the team.
     * @return true if the name is not already in use, false else.
     */
    bool setName(Team* team, std::string name) const;

    /**
     * @brief Sets bracket as the new bracket for the team.
     * @param team
     * @param bracket The new bracket for the team.
     * @return true if the bracket of team was set to the new bracket, false else.
     *
     * Will return false if the team already has athletes. You have to remove all athletes before
     * the bracket of the team can be changed.
     */
    bool setBracket(Team* team, Bracket bracket) const;

    /**
     * @brief Adds the club to the team.
     * @param team
     * @param club
     * @return true if the club was added to the team, false else.
     */
    bool addClub(Team* team, Club* club) const;

    /**
     * @brief Removes the club from the team if possible.
     * @param team
     * @param club
     * @return true if the club was removed from the team or if the club was not a
     *  part of this team, false else.
     *
     * If an athlete in this team is from the club, the club will not be removed and the function
     * returns false. You have to remove all athletes of a club from a team before removing the club.
     */
    bool removeClub(Team* team, Club* club) const;

    /**
     * @brief Adds the athlete to this team if possible.
     * @param team
     * @param athlete
     * @return true is the athlete was added to the team, false else.
     *
     * The athlete will only be added if its club belongs to the team.
     */
    bool addAthlete(Team* team, Athlete* athlete) const;

    /**
     * @brief Removes the athlete from this team if possible.
     * @param team
     * @param athlete
     * @return true if the athlete was removed from the team or if the athlete was not
     * a part of the team, false else.
     */
    bool removeAthlete(Team* team, Athlete* athlete) const;

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
