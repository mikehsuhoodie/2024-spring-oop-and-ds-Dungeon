#ifndef DUNGEON_CURRENCY_H
#define DUNGEON_CURRENCY_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include "Item/Item.h"


using namespace std;


class  Currency : public Item{
private:
    int coin{};
    int silver{};
    int gold{};
public:
    Currency(int,int,int);    Currency(string,int c,int s,int g);
    static void changeMoney(Currency* wallet,int level);
    static bool transaction(string,int,Currency*);
    static void listCurrency(Currency *m);//For player show status

    bool triggerEvent(Object*) override;
//    void setCoin(int);
//    void setSilver(int);
//    void setGold(int);
    int getCoin();
    int getSilver();
    int getGold();
    friend ostream& operator <<(ostream& output,const Currency *currency);

};
ostream& operator <<(ostream& output,const Currency *currency);//For player getting money

#endif //DUNGEON_CURRENCY_H
