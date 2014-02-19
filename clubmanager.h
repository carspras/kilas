#ifndef CLUBMANAGER_H
#define CLUBMANAGER_H

#include "club.h"

#include <map>
#include <string>

namespace kilas {

/**
 * @brief The ClubManager class manages the creation and deletion of Clubs.
 *
 * Assigns every Club a unique ID and assures that every Club name is unique.
 * New Clubs should only be created by using ClubManager::createClub() and deleted by using
 * ClubManager::deleteClub().
 */
class ClubManager {
public:
    ClubManager();

    /**
     * @brief clubCount returns the count of Clubs registered with the ClubManager
     * @return Count of the Clubs
     */
    unsigned int clubCount() const;

    /**
     * @brief Creates a new Club with a unique ID.
     * @param name Name of the new Club
     * @return unique ID of the new Club
     */
    unsigned int createClub(std::string name);

    /**
     * @brief Deletes the Club with the specified ID.
     * @param id The ID of the to be deleted Club
     * @return false if no Club with the ID was found.
     */
    bool deleteClub(unsigned int id);

     /**
     * @brief Deletes the specified Club.
     * @param club The to be deleted Club
     * @return false if the Club was not found.
     */
    bool deleteClub(Club* const club);

    /**
     * @brief Returns the ID of the specified Club
     * @param club
     * @return The ID of the specified Club; 0 if the Club is not found
     */
    unsigned int getId(Club* const club) const;

    /**
     * @brief Returns a pointer to the Club with the specified id
     * @param id
     * @return The Club to the specified ID; nullptr if the ID is not found
     */
    Club* getClub(unsigned int id) const;

    /**
     * @brief Sets newName as the name for the specified Club, if that name is not already in use.
     * @return true if the name was not already in use, false else.
     */
    bool setNewName(Club* club, std::string newName) const ;

private:
    /**
     * @brief Checks if the specified name is already in use.
     * @param name The name to be checked
     * @return true if the name is already in use; false else
     */
    bool nameInUse(std::string name) const;

    /**
     * @brief clubToIdMap_ is the map from the Clubs to the corresponding IDs.
     */
    std::map<Club* const, unsigned int, compare_club> clubToIdMap_;

    /**
     * @brief idToClubMap_ is the map from the Club-IDs to the corresping Clubs.
     */
    std::map<unsigned int, Club* const> idToClubMap_;
};

} //namespace kilas

#endif // CLUBMANAGER_H
