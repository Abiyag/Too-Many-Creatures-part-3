#include "Tavern.hpp"
#include "MagicalBag.hpp"
#include "Creature.hpp"
#include <iostream>
#include <cmath>

/**
Default constructor.
Default-initializes all private members.
Default total level count: 0
Default creature count: 0
*/
Tavern::Tavern() {
    totalLevel_ = 0;
    creatureCount_ = 0; 
}

/**
@param: A creature entering the tavern
@post: If the given creature is not already in the tavern, add the creature to
the tavern and update the level sum and the creature count
@return: Returns true if the creature was successfully added to the cavern,
false otherwise
*/
bool Tavern::enterTavern(Creature* newCreature){
    if (this->contains(newCreature)) {
        return false;
    } else {
        this->add(newCreature);
        totalLevel_ += newCreature->getLevel();
        creatureCount_++;
        return true;
    }
}

/**
@param: A creature exiting the tavern
@post: Removes the creature from the cavern, if they exist, and updates the
level sum and creature count accordingly.
@return: Returns true if the creature was successfully removed from the
cavern, false otherwise
*/
bool Tavern::exitTavern(Creature* newCreature){
    if (this->contains(newCreature)) {
        this->remove(newCreature);
        totalLevel_ -= newCreature->getLevel();
        creatureCount_--;
        return true;
    } else {
        return false;
    }
}

/**
@return: Returns the combined level of all creatures in the tavern
*/
int Tavern::getLevelSum() const {
    return totalLevel_;
}

/**
@return: Returns the amount of creatures in the tavern
*/
int Tavern::getCreatureCount() const {
    return creatureCount_;
}

/**
@return: Returns the amount of creatures in the tavern that are hostile
*/
int Tavern::getHostileCount() const {
    int count = 0;
    for (Creature* creature : this->getVector()) {
        if (creature->isHostile()) {
            count++;
        }
    }
    return count;
}

/**
@post: Computes the percentage of hostile creatures in the tavern rounded
up to 2 decimal places
@return: Returns the percentage of all the hostile creatures in the tavern
*/
double Tavern::calculateHostilePercentage() const {
    if (creatureCount_ == 0) return 0.0;
    double percentage = (static_cast<double>(getHostileCount()) / creatureCount_) * 100;
    return std::ceil(percentage * 100) / 100.0;
}

/**
@param: A string representing a creature category
@return: An integer tally of the number of creatures in the tavern of the
given category
Hint: If string parameter does not match a category, return 0
*/
int Tavern::tallyCategory(const std::string& category) const {
    int count = 0;
    for (Creature* creature : this->getVector()) {
        if (creature->getCategory() == category) {
            count++;
        }
    }
    return count;
}

/**
@param: A string representing a creature school
@return: An integer tally of the number of creatures in the tavern of the
given school
Hint: If string parameter does not match a school, return 0
*/
int Tavern::tallySchool(const std::string& school) const {
    int count = 0;
    for (Creature* creature : this->getVector()) {
        if (creature->getSchool() == school) {
            count++;
        }
    }
    return count;
} 

/**
@param: An integer representing the level threshold of the creatures to be
removed from the tavern, with a default value of 0
@post: Removes all creatures from the tavern whose level is less than the
given level. If no level is given, remove no creatures. Ignore negative inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesBelowLevel(int level) {
    if (level <= 0) return 0;
    int removedCount = 0;
    std::vector<Creature*> current = this->getVector();
    for (Creature* creature : current) {
        if (creature->getLevel() < level) {
            if (exitTavern(creature)) {
                removedCount++;
            }
        }
    }
    return removedCount;
}

/**
@param: A string representing a creature category to be removed from the
tavern, with a default value of “ALL”
@post: Removes all creatures from the tavern whose category matches the
given category. If no category is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfCategory(const std::string& category) {
    int removedCount = 0;
    std::vector<Creature*> current = this->getVector();
    for (Creature* creature : current) {
        if (category == "ALL" || creature->getCategory() == category) {
            if (exitTavern(creature)) {
                removedCount++;
            }
        }
    }
    return removedCount;
}

/**
@param: A string representing a creature school to be removed from the
tavern, with a default value of “ALL”
@post: Removes all creatures from the tavern whose school matches the
given school . If no school is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfSchool(const std::string& school) {
    int removedCount = 0;
    std::vector<Creature*> current = this->getVector();
    for (Creature* creature : current) {
        if (school == "ALL" || creature->getSchool() == school) {
            if (exitTavern(creature)) {
                removedCount++;
            }
        }
    }
    return removedCount;
}

/**
@post: Outputs a report of the creatures current in the tavern in the form:
CATEGORY COUNT:
MAGICAL: [INTEGER]
UNDEAD: [INTEGER]
ANIMAL: [INTEGER]
HUMANOID: [INTEGER]
CATEGORY_UNKNOWN: [INTEGER]
SCHOOL COUNT:
FIRE: [INTEGER]
ICE: [INTEGER]
STORM: [INTEGER]
LIFE: [INTEGER]
MYTH: [INTEGER]
DEATH: [INTEGER]
SCHOOL_UNKNOWN: [INTEGER]
AVERAGE LEVEL: [INTEGER]
HOSTILE: [DOUBLE]
*/
void Tavern::tavernReport() const {
    // Category counters
    int magical = 0, undead = 0, animal = 0, humanoid = 0, unknownCategory = 0;
    // School counters
    int fire = 0, ice = 0, storm = 0, life = 0, myth = 0, death = 0, unknownSchool = 0;

    for (Creature* creature : this->getVector()) {
        std::string cat = creature->getCategory();
        if (cat == "MAGICAL") magical++;
        else if (cat == "UNDEAD") undead++;
        else if (cat == "ANIMAL") animal++;
        else if (cat == "HUMANOID") humanoid++;
        else unknownCategory++;

        std::string school = creature->getSchool();
        if (school == "FIRE") fire++;
        else if (school == "ICE") ice++;
        else if (school == "STORM") storm++;
        else if (school == "LIFE") life++;
        else if (school == "MYTH") myth++;
        else if (school == "DEATH") death++;
        else unknownSchool++;
    }

    std::cout << "CATEGORY COUNT:" << std::endl;
    std::cout << "MAGICAL: " << magical << std::endl;
    std::cout << "UNDEAD: " << undead << std::endl;
    std::cout << "ANIMAL: " << animal << std::endl;
    std::cout << "HUMANOID: " << humanoid << std::endl;
    std::cout << "CATEGORY_UNKNOWN: " << unknownCategory << std::endl;

    std::cout << "SCHOOL COUNT:" << std::endl;
    std::cout << "FIRE: " << fire << std::endl;
    std::cout << "ICE: " << ice << std::endl;
    std::cout << "STORM: " << storm << std::endl;
    std::cout << "LIFE: " << life << std::endl;
    std::cout << "MYTH: " << myth << std::endl;
    std::cout << "DEATH: " << death << std::endl;
    std::cout << "SCHOOL_UNKNOWN: " << unknownSchool << std::endl;

    int averageLevel = creatureCount_ == 0 ? 0 : totalLevel_ / creatureCount_;
    std::cout << "AVERAGE LEVEL: " << averageLevel << std::endl;
    std::cout << "HOSTILE: " << calculateHostilePercentage() << std::endl;
}

/**
@post: For every creature in the tavern, display each creature’s information
*/
void Tavern::displayCreatures() const {
    for (Creature* creature : this->getVector()) {
        creature->display();
        std::cout << std::endl;
    }
}