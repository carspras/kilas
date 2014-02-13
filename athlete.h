#ifndef ATHLETE_H
#define ATHLETE_H

#include "club.h"

#include <string>

/**
 * @brief Each instance of the Athlete class represents an athlete with
 */
class Athlete {
friend class AthleteManager;
friend class TEST;
public:
    /**
     * @brief Returns the bib number of this Athlete
     * @return The bib number of this Athlete
     */
    unsigned short getNumber() const;

    /**
     * @brief Returns the name of this Athlete
     * @return The name of this Athlete
     */
    std::string getName() const;

    /**
     * @brief Returns the year of birth of this Athlete
     * @return The year of birth of this Athlete
     */
    unsigned short getYOB() const;

    /**
     * @brief Returns a pointer to the Club of this Athlete
     * @return Pointer to the Club of this Athlete
     */
    Club* getClub() const;


private:
    /**
     * @brief Use AthleteManager::createAthlete(unsigned short number) instead.
     * @param number The number of the new Athlete
     */
    Athlete(unsigned short number);

    /**
     * @brief The bib number of this Athlete
     */
    unsigned short number_;

    /**
     * @brief The name of this Athlete
     */
    std::string name_;

    /**
     * @brief The year of birth of this Athlete
     */
    unsigned short yearOfBirth_;

    /**
     * @brief The Club of this Athlete
     */
    Club* club_;
};

/**
 * @brief The compare_athlete struct is used to compare two Athletes.
 */
struct compare_athlete {
    /**
     * @brief operator () returns true if number of the first Athlete < number of the second Athlete
     * @param a The first Athlete
     * @param b The second Athlete
     * @return true if number of a < number of b, false else.
     */
    bool operator() (Athlete* const a, Athlete* const b) const {
        if (a->getNumber() < b->getNumber())
            return true;
        else
            return false;
    }
};

#endif // ATHLETE_H
