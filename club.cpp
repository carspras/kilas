#include "club.h"

Club::Club(std::string name) {
    name_ = name;
}

std::string Club::getName() const {
    return name_;
}
