#include "club.h"

Club::Club(std::string name) {
    name_ = name;
}

std::string Club::getName() const {
    return name_;
}

bool Club::setName(std::string newName) {
    name_ = newName;
    return true;
}
