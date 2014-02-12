#ifndef CLUBMANAGER_H
#define CLUBMANAGER_H

#include "club.h"

#include <map>
#include <string>


class ClubManager
{
public:
    ClubManager();

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
    bool deleteClub(const Club* club);

    /**
     * @brief Returns the ID of the specified Club
     * @param club
     * @return The ID of the specified Club; 0 if the Club is not found
     */
    unsigned int getId(const Club* club);

    /**
     * @brief Returns a pointer to the Club with the specified id
     * @param id
     * @return The Club to the specified ID; nullptr if the ID is not found
     */
    const Club* getClub(unsigned int id);

private:
    /**
     * @brief Checks if the specified name is already in use.
     * @param name The name to be checked
     * @return true if the name is already in use; false else
     */
    bool nameInUse(std::string name) const;

    std::map<const Club*, unsigned int, compare_club> clubToIdMap_;
    std::map<unsigned int, const Club*> idToClubMap_;
};

#endif // CLUBMANAGER_H
