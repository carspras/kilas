#ifndef CLUB_H
#define CLUB_H

#include <string>

/**
 * @brief Each instance of the Club class represents a Club with a unique name.
 *
 * A Club should only be created by using ClubManager::createClub() and destroyed by using
 * ClubManager::deleteClub() to assure that the IDs and names are handled correctly.
 */
class Club {
friend class ClubManager;
public:
    /**
     * @brief Returns the name of the Club.
     * @return The name of the Club.
     */
    std::string getName() const;

private:    
    /**
     * @brief Use ClubManager::createClub(std::string name) instead.
     * @param name The name of the new Club.
     */
    Club(std::string name);

    /**
     * @brief The name of the Club.
     *
     * The name of a Club is unique between all instances of Club. This is assured by the
     * ClubManager.
     */
    std::string name_;
};

/**
 * @brief The compare_club struct is used to compare two Clubs.
 */
struct compare_club {
    /**
     * @brief operator () returns true if name of the first Club < name of the second Club
     * @param a The first Club
     * @param b The second Club
     * @return true if name of a < name of b, false else.
     */
    bool operator() (Club* const a, Club* const b) const {
        if (a->getName() < b->getName())
            return true;
        else
            return false;
    }
};

#endif // CLUB_H
