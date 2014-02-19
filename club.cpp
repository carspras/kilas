#include "club.h"

using namespace kilas;

Club::Club(std::string name) {
    name_ = name;
}

std::string Club::getName() const {
    return name_;
}
