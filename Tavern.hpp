#ifndef TAVERN_H
#define TAVERN_H

#include "Creature.hpp"
#include "MagicalBag.hpp"
#include <string>
#include <iostream>


class Tavern : public MagicalBag<Creature*> {
    private:
        int totalLevel_;
        int creatureCount_;

    
    public:
        Tavern();
        bool enterTavern(Creature* newCreature);
        bool exitTavern(Creature* newCreature);
        int getLevelSum() const;
        int getCreatureCount() const;
        int getHostileCount() const;
        double calculateHostilePercentage() const;
        int tallyCategory(const std::string& category) const;
        int tallySchool(const std::string& category) const;
        int releaseCreaturesBelowLevel(int level);
        int releaseCreaturesOfCategory(const std::string& category);
        int releaseCreaturesOfSchool(const std::string& school);
        void tavernReport() const;
        void displayCreatures() const;

};

#endif