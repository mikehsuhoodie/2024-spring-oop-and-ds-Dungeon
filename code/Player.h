#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <vector>
#include <iomanip>
#include "GameCharacter.h"
#include "Room.h"
#include "Item/Currency.h"

using namespace std;

class Item;
class Weapon;

class Player: public GameCharacter
{
private:
    Room* currentRoom{};
    Room* previousRoom{};
    vector<Item*> inventory{};
    int hunger{},thirst{},poison{};
    Currency wallet;// wallet

public:
//    int notorious;

//    Player();
    Player(string,int,int,int,int,int,int);
    void addItem(Item*);
    bool popItem(Item*);
    void changeHungerSystem(int hungerVal, int thirstVal, int poisonVal);
    void checkHS();
    void changeRoom(Room*);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*) override;
    bool hasConsume();
    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(const vector<Item*>&);
    void setPoison(int);
    int getPoinson();
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item*> getInventory();
    Currency* getWallet();// Let Currency function
};

#endif // PLAYER_H_INCLUDED
