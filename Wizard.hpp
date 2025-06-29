#ifndef WIZARD_H
#define WIZARD_H

#include "Creature.hpp"
#include <string>
#include <iostream>

class Wizard: public Creature {

    Wizard();

    Wizard(const std::string& name, Category category, School school, int health, int level, bool tame, int speed);

    void attackSpell(Creature* target);

    void healSpell();



};


#endif