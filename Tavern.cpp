#include "Tavern.hpp"
#include "MagicalBag.hpp"
#include "Creature.hpp"

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
    }
    else {
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
    if(this->contains(newCreature)) {
        this->remove(newCreature);
        totalLevel_ -= newCreature->getLevel();
        creatureCount_--;
        return true;
    }
    else {
        return false;
    }
}

/**
@return: Returns the combined level of all creatures in the tavern
*/
int Tavern::getLevelSum() const{
    return totalLevel_;
}
/**
@return: Returns the amount of creatures in the tavern
*/
int Tavern::getCreatureCount() const{
    return creatureCount_;
}
/**
@return: Returns the amount of creatures in the tavern that are hostile
*/
int Tavern::getHostileCount() const{
    

}
/**
@post: Computes the percentage of hostile creatures in the tavern rounded
up to 2 decimal places
@return: Returns the percentage of all the hostile creatures in the tavern
*/
double Tavern::calculateHostilePercentage() const{
    
}
/**
@param: A string representing a creature category
@return: An integer tally of the number of creatures in the tavern of the
given category
Hint: If string parameter does not match a category, return 0
*/

int Tavern::tallyCategory(const std::string& category) const{
    std::vector<Creature*> creatures = this->getVector();
    int numCreatures = 0;
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i]->getCategory() == category) {
            numCreatures++;
    }
}
    return numCreatures;
}
/**
@param: A string representing a creature school
@return: An integer tally of the number of creatures in the tavern of the
given school
Hint: If string parameter does not match a school, return 0
*/
int Tavern::tallySchool(const std::string& category) const{
   
    std::vector<Creature*> schools = this->getVector(); 
   int numCreatures = 0;
   for (int i = 0; i < schools.size(); i++) {
        if (schools[i] ->getSchool() == category) {
            numCreatures++;
        }
   } return numCreatures;
} 
/**
@param: An integer representing the level threshold of the creatures to be
removed from the tavern, with a default value of 0
@post: Removes all creatures from the tavern whose level is less than the
given level. If no level is given, remove no creatures. Ignore negative inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesBelowLevel(int level){

}
/**
@param: A string representing a creature category to be removed from the
tavern, with a default value of “ALL”
@post: Removes all creatures from the tavern whose category matches the
given category. If no category is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfCategory(const std::string& category){

}
/**
@param: A string representing a creature school to be removed from the
tavern, with a default value of “ALL”

@post: Removes all creatures from the tavern whose school matches the
given school . If no school is given, remove all creatures. Ignore invalid
inputs.
@return: The number of creatures removed from the tavern
*/
int Tavern::releaseCreaturesOfSchool(const std::string& school){

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

}
/**
@post: For every creature in the tavern, display each creature’s information
*/
void Tavern::displayCreatures() const {
    
}
