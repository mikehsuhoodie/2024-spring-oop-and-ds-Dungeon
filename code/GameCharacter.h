#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    //string name;
    int maxHealth{};
    int currentHealth{};
    int attack{};
    int defense{};
public:
    GameCharacter();
    GameCharacter(string,string,int,int,int);
    bool checkIsDead();

    void fight (string attacker, string opponent, int Hval, int Aval, int Dval);//use in action between characters(fight,heal)
    void changeState(int healVal, int attackVal, int defenseVal);//use in action between player and item(potion,food)

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
};
#endif // GAMECHARACTER_H_INCLUDED
