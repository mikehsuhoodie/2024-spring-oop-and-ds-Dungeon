//
// Created by seash on 2024/4/9.
//

#ifndef DUNGEON_WEAPON_H
#define DUNGEON_WEAPON_H
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>
#include "Item/Item.h"
//#include "Player.h"
//#include "NPC.h"
//#include "Monster.h"



using namespace std;
class Player;
struct Value;
class Weapon: public Item {
public:
    Weapon(string,int,int,Value v);
//    bool triggerEvent(Object*) override;
    int fight(string opponent);

};


#endif //DUNGEON_WEAPON_H
