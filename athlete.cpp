#include "athlete.h"

Athlete::Athlete() {
}

unsigned short Athlete::getNumber() const {
    return number_;
}

std::string Athlete::getName() const {
    return name_;
}

unsigned short Athlete::getYOB() const {
    return yearOfBirth_;
}

Club* Athlete::getClub() const {
    return club_;
}
