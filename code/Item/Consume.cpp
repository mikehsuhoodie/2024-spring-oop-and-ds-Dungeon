#include "Consume.h"

Consume::Consume(string newName, int newHealth, int newHunger, int newThirst, int newPoison, Value v, bool r)
    : Item(newName,newHealth,newHunger,newThirst,newPoison,v){raw =r;} //food
Consume::Consume(string newName, int newHealth, int newAtk, int newDfs, int newHgr, int newThirst, int newPsn, Value v)
    : Item(newName,newHealth,newAtk,newDfs,newHgr,newThirst,newPsn,v){raw= true;}

bool Consume::triggerEvent(Object *_player) {
    Player* player = dynamic_cast<Player*>(_player);
    if(player == nullptr)
        return false;
    if(raw && getTag()=="Consume"){
        cout<<"Since you had raw food, you get POISONED."<<endl;
    }
    player->changeState(health, attack, defense);
    player->changeHungerSystem(hunger, thirst, poison);
    system("pause");
    return true;
}

void Consume::eatWhat(Player *player) {
    cout<<"Which food/drink/potion do you want?"<<endl;
    int numOfConsume = listConsume(player->getInventory());
    cout<<numOfConsume+1<<". Leave"<<endl;

    cout<<">>>";
    int op,findConsume=0;
    cin>>op;
    if(op == numOfConsume+1){
        cout<<"Ok Bye bye."<<endl;
        return;
    }
    while(op){
        if(player->getInventory()[findConsume]->getTag()=="Consume"||player->getInventory()[findConsume]->getTag()=="Potion"){
            op--;
            if(op==0)
                break;
        }
        findConsume++;
    }
    if(player->getInventory()[findConsume]->triggerEvent(player))
        player->popItem(player->getInventory()[findConsume]);
}
int Consume::listConsume(vector<Item*> items){
    int cnt=0;
    for(int i=0;i<items.size();i++){
        if(items[i]->getTag()=="Consume" || items[i]->getTag()=="Potion"){
            cout<<cnt+1<<". "<<items[i]->getName()<<":";
            Consume* consume = dynamic_cast<Consume*>(items[i]);
            if(consume== nullptr)
                cout<<"dynamic_cast false. listConsume"<<endl;
            else if(consume->isRaw())
                cout<<setw(10)<<right<< "Row || ";
            else
                cout<<setw(10)<<right<<"Cooked || ";
            cout<<"Increase ";
            if(consume->getHealth()>0)
                cout<<consume->getHealth()<<" health | ";
            if(consume->getAttack()>0)
                cout<<consume->getAttack()<<" attack | ";
            if(consume->getDefense()>0)
                cout<<consume->getDefense()<<" defense| ";
            if(consume->getHunger()>0)
                cout<<consume->getHunger()<<" hunger | ";
            if(consume->getThirst()>0)
                cout<<consume->getThirst()<<" thirst | ";
            if(consume->getPoison()>0)
                cout<<consume->getPoison()<<" poison | ";
            cout<<endl;
            cnt++;
        }
    }
    return cnt;
}

bool Consume::isRaw() {
    return raw;
}

void Consume::setRaw(bool r) {
    raw = r;
}