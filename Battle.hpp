#ifndef BATTLE_H
#define BATTLE_H
#include "Creature.hpp"
#include "Wizard.hpp"
#include "Tavern.hpp"
#include <stack>

class Battle {
    private:
        //A pointer to the player-controlled wizard
        Wizard* wizard_;
        //A tavern of enemy creature pointers participating in the battle
        Tavern enemies_;
        //A stack representing the current turn order
        std::stack<Creature*> turnStack_;

    public:
        Battle(Wizard* wizard, Tavern enemies);
        
        void simulate();

        void buildTurnStack();

        void executeTurn(Creature* attacker);

        void removeDefeatedEnemy();

        bool isWizardAlive() const;

        bool enemiesRemain() const;

        void displayRoundStatus() const;


};


#endif