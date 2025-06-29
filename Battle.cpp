#include "Battle.hpp"

/**
Parameterized constructor
@param: The wizard involved in the battle
@param: The tavern of creatures involved in the battle
*/
Battle::Battle(Wizard* wizard, Tavern enemies) {
    wizard_ = wizard;
    enemies_ = enemies;
}


/**
@post: Simulates the entire combat between the wizard and the enemy
creatures
Steps:
Display round status
Adds creatures into your turnStack_ based on speed. The higher the speed
the earlier the creature will go (Remember how stacks work)

Executes the turn of the creature at the top of the stack. If the creature is a
wizard, you will gather user input to dictate whether the wizard will attack
or heal. If the creature is an enemy they will do their standard attack
When the wizard attacks, display all of the creatures in the tavern and gather
user input to decide who the wizard attacks
If the creature’s health falls below zero, remove them from the tavern
Check to see if the wizard is still alive or if there are still any enemies left in
the tavern. If either of the conditions is true, print an action message to
signal that the battle is over and who came out victorious. If neither of the
conditions are true, build the stack once again and continue to simulate the
battle
Hint: Keep in mind that when a creature is attacking, they need to be popped
out of the stack. Because of this reason you need to build your stack every
time a full turn occurs
*/
void Battle::simulate() {

}
/**
@post: Populates the turnStack_ with all current combatants (wizard and all
enemies from the tavern) sorted by ascending speed (the faster the speed the
earlier you go)
*/
void Battle::buildTurnStack(){

}
/**
@param: Pointer to the creature taking a turn
@post: Executees the turn of a given creature. If the attacker is an enemy
they will perform an attack on the Wizard. If the attacker is a wizard, the
wizard chooses and casts a spell (either offensive or defensive) on a chosen
target (indexed from your tavern)
*/
void Battle::executeTurn(Creature* attacker) {

}
/**

@post: Removes any enemies whose health has dropped to 0 or below from
the tavern after turn execution
*/
void Battle::removeDefeatedEnemy() {

}

/**
@return: true if the wizard is still alive (health > 0), false otherwise
*/
bool Battle::isWizardAlive() const {

}
/**
@return: true if there are remaining enemies, false if all have been defeated
*/
bool Battle::enemiesRemain() const {
     
}
/**
@post: Displays the current status of all combatants at the start of a round.
The output should include:
The Wizard’s name and current health.
A numbered list of all enemies still in the battle, showing:
- Name
- Current health
- Speed
Example output:
=== Round Status ===
Wizard: Merlin
Health: 72
Enemies:
1. Lado - Health: 25, Speed: 4
2. Meheraan - Health: 30, Speed: 3
3. Ank - Health: 18, Speed: 2

=====================
*/
void Battle::displayRoundStatus() const {

}