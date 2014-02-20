#include "team.h"

using namespace kilas;

Team::Team(std::string name, Bracket bracket) {
    name_ = name;
    bracket_ = bracket;
}

std::string Team::getName() const {
    return name_;
}

Bracket Team::getBracket() const {
    return bracket_;
}

std::unordered_set<Club*> Team::getClubs() const {
    return clubs_;
}

std::vector<Athlete*> Team::getAthletes() const {
    return athletes_;
}
