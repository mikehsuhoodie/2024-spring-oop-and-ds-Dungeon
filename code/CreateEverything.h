#ifndef DUNGEON_CREATEEVERYTHING_H
#define DUNGEON_CREATEEVERYTHING_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Object.h"
#include "Monster.h"
#include "NPC.h"
#include "Item/Item.h"
#include "Item/Consume.h"
//#include "Item/Weapon.h"
//#include "Item/Currency.h"

using namespace std;
class NPC;
class Monster;
class Item;

class CreateEverything {
public:
    vector<Object*> createObjects(int);
};


#endif //DUNGEON_CREATEEVERYTHING_H
