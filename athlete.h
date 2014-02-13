#ifndef ATHLETE_H
#define ATHLETE_H

#include "club.h"

#include <string>

/**
 * @brief Each instance of the Athlete class represents an athlete with
 */
class Athlete {
friend class AthleteManager;
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
     * @brief Use AthleteManager::createAthlete() instead
     */
    Athlete();

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

#endif // ATHLETE_H
