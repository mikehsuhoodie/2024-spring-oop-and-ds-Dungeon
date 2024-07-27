#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "GameCharacter.h"
#include "Player.h"
#include "Item/Item.h"
#include "Item/Currency.h"
#include "Item/Consume.h"

using namespace std;
//class Item;


class NPC: public GameCharacter
{
private:
    string occupation;
    string script;
    vector<Item*>  commodity;
public:
    NPC();
    NPC(string newName, string newS, string newO, vector<Item*> newC);
//    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object*) override;

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<Item*>);
    void setOccupation(const string&);
    string getScript();
    vector<Item*> getCommodity();
    string getOccupation();
};


#endif // NPC_H_INCLUDED
