#include "Player.h"
#include "Item/Currency.h"

Player::Player(std::string newName, int newH,int newA,int newD,int newHgr,int newT,int newP)
    :GameCharacter(newName,"Player",newH,newA,newD),hunger(newHgr),thirst(newT),poison(newP),wallet(0,0,0){}

void Player::addItem(Item* item) {
    if(item->getTag() == "Currency"){
        Currency* currency = dynamic_cast<Currency*>(item);
        cout<<"You got: "<<currency->getName()<<endl;
        cout << currency;
        wallet.triggerEvent(currency);
    }else{
        cout<<"You got: "<<item->getName()<<endl;
        inventory.push_back(item);
    }
}

bool Player::popItem(Item *item) {
    for(int i=0;i<inventory.size();i++){
        if(inventory[i] == item){
            inventory.erase(inventory.begin()+i);
            return true;
        }
    }
    return false;
}
void Player::changeHungerSystem(int hungerVal, int thirstVal, int poisonVal) {
    if(hungerVal != 0){
        if(hungerVal>0)
            cout<<"Hunger: +"<<hungerVal<<endl;
        else
            cout<<"Hunger: "<<hungerVal<<endl;
        hunger+=hungerVal;
        if(hunger>100)
            hunger=100;
    }

    if(thirstVal != 0){
        if(thirstVal>0)
            cout<<"Thirst: +"<<thirstVal<<endl;
        else
            cout<<"Thirst: "<<thirstVal<<endl;
        thirst+=thirstVal;
        if(thirst>100)
            thirst=100;
    }
    if(poisonVal != 0){
        if(poisonVal>0)
            cout<<"Poison: +"<<poisonVal<<endl;
        else
            cout<<"Poison: "<<poisonVal<<endl;
        poison+=poisonVal;
        if(poison<0)
            poison=0;
    }
    checkHS();
}

void Player::checkHS() {
    if(hunger<0){
        cout<<"AHHH! You are extremely hungry."<<endl;
        cout<<"Any excess hunger will be offset by your health points."<<endl;
        int cnt = -hunger;
        cout<<"Excess Hunger: "<<cnt<<endl;
        changeState(-cnt,0,0);
        hunger=0;
        system("pause");
    }
    if(thirst<0){
        cout<<"@#$%!#&! You are extremely thirsty."<<endl;
        cout<<"Any excess thirst will be offset by your health points."<<endl;
        int cnt = -thirst;
        cout<<"Excess Thirst: "<<cnt<<endl;
        changeState(-cnt,0,0);
        thirst=0;
        system("pause");
    }
    if(poison>100){
        cout<<"You are severely poisoned."<<endl;
        cout<<"Any excess poison will be offset by your health points."<<endl;
        cout<<"$%!#&@#$%!@#$%!#&@#$%!#&@#&@#$%!@#$%!#&#$%!#&@#$%!@#$%!#&@#"<<endl;
        cout<<"$%!#&@#$%!@#$%!#&@#$%!#&@#&@#$%!@#$%!#&#$%!#&@#$%!@#$%!#&@#"<<endl;
        cout<<"$%!#&@#$%!@#$%!#&@#$%!#&@#&@#$%!@#$%!#&#$%!#&@#$%!@#$%!#&@#"<<endl;
        int cnt = 100-poison;
        cout<<"Excess Poison: "<<cnt<<endl;
        changeState(cnt,0,0);
        poison=100;
        system("pause");
    }
}

void Player::changeRoom(Room * toRoom) {
    previousRoom = currentRoom;
    currentRoom = toRoom;
}

bool Player::triggerEvent(Object * _gameCharacter) {
    GameCharacter* gameCharacter = dynamic_cast<GameCharacter*>(_gameCharacter);
    if(gameCharacter== nullptr)
        return false;
    cout<<"==========[LOCATION]=========="<<endl;
    cout<<setw(5)<<left<<"Room:"<<setw(25)<<right<<currentRoom->getName()<<endl;
    cout<<setw(6)<<left<<"Level:"<<setw(24)<<right<<currentRoom->getLevel()<<endl;
    cout<<setw(6)<<left<<"Biome:"<<setw(24)<<right<<currentRoom->getBiome()<<endl;
    cout<<"===========[STATUS]==========="<<endl;
    cout<<setw(5)<<left<<"Name:"<<setw(25)<<right<<getName()<<endl;
    cout<<setw(8)<<left<<"Health:"<<setw(22)<<right<<getCurrentHealth()<<endl;
    cout<<setw(8)<<left<<"Attack:"<<setw(22)<<right<<gameCharacter->getAttack()<<endl;
    cout<<setw(8)<<left<<"Defense:"<<setw(22)<<right<<gameCharacter->getDefense()<<endl;
    cout<<setw(8)<<left<<"Hunger:"<<setw(22)<<right<<hunger<<endl;
    cout<<setw(8)<<left<<"Thirst:"<<setw(22)<<right<<thirst<<endl;
    cout<<setw(8)<<left<<"Poison:"<<setw(22)<<right<<poison<<endl;
    cout<<"=========[INVENTORY]=========="<<endl;
    for(auto& it:inventory){
        cout<<setw(30)<<right<<it->getName()<<endl;
    }
    cout<<"===========[WALLET]==========="<<endl;
    Currency::listCurrency(&wallet);
    system("pause");
    return true;
}

bool Player::hasConsume() {
    for(auto it:inventory){
        if(it->getTag()=="Consume" || it->getTag() == "Potion")
            return true;
    }
    return false;
}
//mutator
void Player::setCurrentRoom(Room *r) {
    currentRoom = r;
}
void Player::setPreviousRoom(Room *p) {
    previousRoom = p;
}
void Player::setInventory(const vector<Item*>& items) {
    inventory = items;
}
void Player::setPoison(int p) {
    poison = p;
}
//accessor
int Player::getPoinson() {
    return poison;
}
Room* Player::getCurrentRoom() {
    return currentRoom;
}
Room *Player::getPreviousRoom() {
    return previousRoom;
}
vector<Item*> Player::getInventory() {
    return inventory;
}

Currency* Player::getWallet() {
    return &wallet;
}


