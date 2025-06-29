#include "Wizard.hpp"
#include "Creature.hpp"


/**
Default constructor.
Default-initializes all private members.
Default Wizard Category: HUMANOID
Default Wizard School: Choose what you like
*/
Wizard::Wizard() : Creature() {
    Category cateogry_ = HUMANOID;
    setSchool(MYTH);
}

/**
Parameterized constructor.
@param: The name of the wizard (a string)
@param: The category of the wizard (a Category enum) with a default value
HUMANOID
@param: The school of the wizard (a School enum) with a default value of
whatever you like
@param: The health of the wizard (an integer) with default value 100 if not
provided, or if the value provided is 0 or negative
@param: The level of the wizard (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the wizard (a boolean) with default value of False
@param: The speed of the wizard (an integer) with default value of 10 if not
provided, or if the value provided is 0 or negative
*/

Wizard::Wizard(const std::string& name, Category category, School school, int health, int level, bool tame, int speed) 
: Creature(name, category, school, (health > 0 ? health : 100), (level > 0 ? level : 1), (speed > 0? speed : 10), isHostile)
{
    tame = false;
}

/**
Offensive spell - attacks a target creature with magic
@param: A pointer to the creature being attacked
@post: Decreases the health of the creature being attacked by 20 and
displays a different message for the spell used based on wizard’s school:
FIRE: Fire Cat
STORM: Thunder Snake
ICE: Frost Beetle
LIFE: Imp
MYTH: Blood Bat
DEATH: Dark Sprite
<Wizard Name> casts <School spell> on <Target Name>!
*/
void Wizard::attackSpell(Creature* target) {
    int currHealth = target->getHealth();
    target->setHealth(currHealth - 20);

    std::string school = getSchool();  //  Get school name as string
    std::string spellName;

    if (school == "FIRE")       spellName = "Fire Cat";
    else if (school == "STORM") spellName = "Thunder Snake";
    else if (school == "ICE")   spellName = "Frost Beetle";
    else if (school == "LIFE")  spellName = "Imp";
    else if (school == "MYTH")  spellName = "Blood Bat";
    else if (school == "DEATH") spellName = "Dark Sprite";
    else                        spellName = "Mystery Magic";

    std::cout << getName() << " casts " << spellName
              << " on " << target->getName() << "!\n";
}

/**
Defensive spell - heals the wizard
@post: Increases the wizard’s health by 15 points and displays an action
message
<Wizard Name> casts Fairy!
*/
void Wizard::healSpell() {
    int currHealth = getHealth();
    setHealth(currHealth + 15); 
    std::cout << getName() << " casts Fairy!";
}