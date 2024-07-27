#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "GameCharacter.h"
#include "Player.h"
#include "Item/Item.h"
#include "Item/Weapon.h"


using namespace std;

class Monster: public GameCharacter
{
private:
    vector<Item*>  drops{};
public:
    Monster();
    Monster(string,int,int,int,vector<Item*>);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
    void setDrops(vector<Item*>);
    vector<Item*> getDrops();

};


#endif // ENEMY_H_INCLUDED
