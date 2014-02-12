#ifndef CLUB_H
#define CLUB_H

#include <string>

class Club
{
public:
    Club(std::string name);

    std::string getName() const;
    bool setName(std::string newName);

private:
    std::string name_;
};

struct compare_club {
    bool operator() (const Club* a, const Club* b) {
        if (a->getName() < b->getName())
            return true;
        else
            return false;
    }
};

#endif // CLUB_H
