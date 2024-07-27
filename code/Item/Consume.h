#ifndef DUNGEON_CONSUME_H
#define DUNGEON_CONSUME_H
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Item.h"
using namespace std;

struct Value;
class Consume : public Item{
private:
    bool raw;
public:

    Consume(string, int, int, int, int, Value, bool);//for food
    Consume(string, int, int, int, int, int, int, Value);//for potion
    //player use it and the object will be deleted.
    bool triggerEvent(Object*) override;
    static void eatWhat(Player*);
    static int listConsume(vector<Item*> items); //consume with row and cooked
    bool isRaw();
    void setRaw(bool);
};


#endif //DUNGEON_CONSUME_H
