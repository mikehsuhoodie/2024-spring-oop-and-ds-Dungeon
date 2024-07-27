#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Player;

struct Value{
    int dollar;
    string currency;
};


class Item: public Object
{
private:
    Value value;
    string script;
protected:
    int health{}; //food,potion
    int attack{},defense{}; //weapon, potion
    int hunger{},thirst{},poison{}; //food,potion
public:
    Item();//for currency
    Item(string,string);//for currency
    Item(string,int,int,Value);//for weapon
    Item(string,int,int,int,int,Value);//for food
    Item(string, int, int, int, int, int, int,Value);//for potion

    /* function overload */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    virtual bool triggerEvent(Object*);

    /* Set & Get function*/
    Value* getValue();
    string getScript();
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getHunger() const;
    int getThirst() const;
    int getPoison() const;


    void setValue(Value);
    void setScript(string);
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setHunger(int);
    void setThirst(int);
    void setPoison(int);

};

int listItems(vector<Item*>);// all, just name
int listGoods(vector<Item*>); // all, with value and effect
int listOneType(vector<Item*>,string);// one type, just name

#endif // ITEM_H_INCLUDED
