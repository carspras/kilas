#ifndef ATHLETEMANAGER_H
#define ATHLETEMANAGER_H

#include "athlete.h"

#include <map>
#include <string>

namespace kilas {

/**
 * @brief The AthleteManager class manages the instances of Athletes
 */
class AthleteManager {
public:
    AthleteManager();

    /**
     * @brief Returns the count of Athletes registered with the AthleteManager
     * @return Count of the Athletes
     */
    unsigned int athleteCount() const;

    /**
     * @brief Creates a new Athlete with a unique ID.
     * @param number Bib number of the new Athlete.
     * @return ID of the new Athlete if successful, -1 if number==0 or already in use.
     *
     * name_ is set to the empty string, yearOfBirth_ to 0, club_ to nullptr.
     */
    int createAthlete(unsigned short number);

    /**
     * @brief Creates a new Athlete with a unique ID.
     * @param number Bib number of the new Athlete.
     * @param name name of the new Athlete.
     * @return ID of the new Athlete if successful, -1 if number==0 or already in use.
     *
     * yearOfBirth_ is set to 0, club_ to nullptr.
     */
    int createAthlete(unsigned short number, std::string name);

    /**
     * @brief Creates a new Athlete with a unique ID.
     * @param number Bib number of the new Athlete.
     * @param name name of the new Athlete.
     * @param yob year of birth of the new Athlete
     * @return ID of the new Athlete if successful,
     * -1 if number==0 or already in use.
     *
     * club_ is set to nullptr.
     *
     * TODO: Check if yob is within acceptable range (return -3 if not)
     */
    int createAthlete(unsigned short number, std::string name,
                      unsigned short yob);

    /**
     * @brief Creates a new Athlete with a unique ID.
     * @param number Bib number of the new Athlete.
     * @param name Name of the new Athlete.
     * @param yob Year of birth of the new Athlete.
     * @param club Club of the new Athlete.
     * @return ID of the new Athlete if successful,
     * -1 if number==0 or already in use
     */
    int createAthlete(unsigned short number, std::string name,
                      unsigned short yob, Club* club);

    /**
     * @brief Deletes the Athlete with the specified ID.
     * @param id The ID of the to be deleted Athlete.
     * @return 0 if no Athlete with the ID was found.
     */
    bool deleteAthlete(int id);

    /**
     * @brief Deletes the specified Athlete.
     * @param Athlete The to be deleted Athlete.
     * @return 0 if the Athlete was not found.
     */
    bool deleteAthlete(Athlete* const Athlete);

    /**
     * @brief Returns the ID of the specified Athlete.
     * @param athlete
     * @return The ID of the specified Athlete;
     * -1 if the Athlete is not found.
     */
    int getId(Athlete* const athlete) const;

    /**
     * @brief Returns a pointer to the Athlete with the specified ID.
     * @param id
     * @return The Athlete to the specified; nullptr if the ID is not found.
     */
    Athlete* getAthlete(int id) const;

private:
    /**
     * @brief Checks if the specified number is already in use.
     * @param number The number to be checked.
     * @return 1 if the number is already in use, 0 else.
     */
    bool numberInUse(unsigned short number) const;

    /**
     * @brief athleteToIdMap_ is the map from the Athletes to the
     * corresponding IDs.
     */
    std::map<Athlete* const, int, compare_athlete> athleteToIdMap_;

    /**
     * @brief idToAthleteMap_ is the map from Athlete-IDs to the
     * corresponding Athletes.
     */
    std::map<int, Athlete* const> idToAthleteMap_;
};

} //namespace kilas

#endif // ATHLETEMANAGER_H
