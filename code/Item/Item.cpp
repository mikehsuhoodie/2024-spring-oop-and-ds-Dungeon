#include "Item.h"
using namespace std;

Item::Item():Object("noName","noTag") {script = "No Script";}
Item::Item(string newName,string newTag):Object(newName,newTag) {script = "No Script";}
Item::Item(string s,int newAtk,int newDef,Value v):Object(s,"Weapon"), attack(newAtk), defense(newDef), value(v){script = "No Script";};
Item::Item(string s,int newHealth,int newHunger,int newThirst,int newPoison,Value v):Object(s,"Consume"),
    health(newHealth), hunger(newHunger), thirst(newThirst), poison(newPoison), value(v){script = "No Script";};
Item::Item(string newName,int newHealth,int newAtk,int newDfs,int newHgr,int newThirst,int newPsn,Value v):Object(newName,"Potion"){
    health = newHealth;
    attack = newAtk;
    defense = newDfs;
    hunger = newHgr;
    thirst = newThirst;
    poison = newPsn;
    value = v;
    script = "No Script";
}

bool Item::triggerEvent(Object * _player) {
    cout<<"You use a nothing item"<<endl;
    return true;
}


int listItems(vector<Item*> items){
    int cnt=0;
    for(int i=0;i<items.size();i++){
        cout<<i+1<<". "<<items[i]->getName()<<endl;
        cnt++;
    }
    return cnt;
}
int listGoods(vector<Item*> goods){
    int cnt=0;
    for(int i=0;i<goods.size();i++){
        cout<<i+1<<". "<<setw(30)<<left<<goods[i]->getName();
        cout<<setw(3)<<left<<goods[i]->getValue()->dollar<<" ";
        cout<<setw(7)<<left<<goods[i]->getValue()->currency;
        if(goods[i]->getTag() == "Weapon"){
            cout<<endl;
            cnt++;
            continue;
        }

//        cout<<goods[i]->getScript()<<endl;
        //Just For Consume
        cout<<"Increase ";
        if(goods[i]->getHealth()>0)
            cout<<goods[i]->getHealth()<<" health | ";
        if(goods[i]->getAttack()>0)
            cout<<goods[i]->getAttack()<<" attack | ";
        if(goods[i]->getDefense()>0)
            cout<<goods[i]->getDefense()<<" defense| ";
        if(goods[i]->getHunger()>0)
            cout<<goods[i]->getHunger()<<" hunger | ";
        if(goods[i]->getThirst()>0)
            cout<<goods[i]->getThirst()<<" thirst | ";
        if(goods[i]->getPoison()>0)
            cout<<goods[i]->getPoison()<<" poison | ";
        cout<<endl;
//        cout<<"points"<<endl;
        cnt++;
    }
    return cnt;
}
int listOneType(vector<Item*> items,string type){
    int cnt=0;
    for(int i=0;i<items.size();i++){
        //cout<<setw(20)<<it->getName()<<endl;
        if(items[i]->getTag()==type){
            cout<<i+1<<". "<<items[i]->getName();
            cout<<endl;
            cnt++;
        }
    }
    return cnt;
}

//accessor
int Item::getHealth() const {
    return health;
}
int Item::getAttack() const{
    return attack;
}
int Item::getDefense() const {
    return defense;
}
int Item::getHunger() const {
    return hunger;
}
int Item::getThirst() const {
    return thirst;
}
int Item::getPoison() const {
    return poison;
}

Value* Item::getValue() {
    return &value;
}
string Item::getScript() {
    return script;
}

//mutator
void Item::setHealth(int h) {
    health = h;
    if(health>100)
        health=100;
}
void Item::setAttack(int a) {
    attack = a;
    if(attack>100)
        attack=100;
}
void Item::setDefense(int d) {
    defense = d;
    if(defense>100)
        defense=100;
}
void Item::setHunger(int h) {
    hunger = h;
    if(hunger>100)
        hunger=100;
}
void Item::setThirst(int t) {
    thirst = t;
    if(thirst>100)
        thirst=100;
}
void Item::setPoison(int p) {
    poison = p;
    if(poison>100)
        poison=100;
}

void Item::setValue(Value v) {
    value = v;
}
void Item::setScript(std::string s) {
    script = s;
}

