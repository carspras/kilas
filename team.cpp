#include "team.h"

using namespace kilas;

Team::Team(std::string name) {
    name_ = name;
    bracket_ = Bracket::U8;
    club_ = nullptr;
}

std::string Team::getName() const {
    return name_;
}

Bracket Team::getBracket() const {
    return bracket_;
}

Club* Team::getClub() const {
    return club_;
}

std::vector<Athlete*> Team::getAthletes() const {
    return athletes_;
}
