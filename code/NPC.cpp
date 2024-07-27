#include "NPC.h"

NPC::NPC() = default;
NPC::NPC(string newName, string newS, string newO, vector<Item*> newC) : GameCharacter(newName,"NPC",0,0,0){
    script = newS;
    commodity = newC;
    occupation = newO;
}

//void NPC::listCommodity() {
//    cout<<"I have something here...hehe..."<<endl;
//    listItems(commodity);
//}
bool NPC::triggerEvent(Object* _player){
    auto* player = dynamic_cast<Player*>(_player);
    if(player == nullptr){
        return false;
    }
    int level = player->getCurrentRoom()->getLevel();
    if(occupation == "Talker"){
        cout<<getName()<<": "<<script<<endl;
        if(!commodity.empty())
            cout<<getName()<<" gave you something"<<endl;
        int n = commodity.size()-1;
        while(!commodity.empty()){
            player->addItem(commodity[n]);
            commodity.pop_back();
            n--;
        }
        system("pause");
    }
    else if(occupation == "Merchant"){
        cout<<"Merchant: What you want, but not as cheap as you think."<<endl;
        int n= listGoods(commodity);
        cout<<n+1<<". Leave"<<endl;
        cout<<n+2<<". Change Money"<<endl;
        cout<<"========["<<player->getName()<<"'s WALLET]========"<<endl;
        Currency::listCurrency(player->getWallet());

        int index;
        bool validInput = false;
        while (!validInput){
            cout<<">>>";
            if (!(cin >> index) || index < 0 || index > n+2) {
                cout << "Invalid input. Try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                validInput = true;
            }
        }
        index--;
        if(index == n){
            cout<<"OK, bye bye."<<endl;
            return true;
        }else if(index == n+1){
            Currency::changeMoney(player->getWallet(),player->getCurrentRoom()->getLevel());
            return true;
        }
        Value* v=commodity[index]->getValue();
        bool canBuy = Currency::transaction(v->currency, v->dollar,player->getWallet());
        if(canBuy){
            cout<<"Good Deal."<<endl;
            player->addItem(commodity[index]);
            commodity.erase(commodity.begin()+index);
        }else{
            cout<<"Get OOOOOOOOOUTT!"<<endl;
        }
        system("pause");
    }else if(occupation == "Doctor"){
        cout<<"Doctor: Don't worry, I've dealt with worse. Tell me what's wrong, and I'll take care of it."<<endl;
        cout<<"Cost 50 ";
        if(level == 1)
            cout<<"coins ";
        else if(level == 2)
            cout<<"silvers ";
        else if(level == 3)
            cout<<"golds ";
        cout<<"for every option"<<endl;
        cout<<"1. Fully healed"<<endl;
        cout<<"2. Curing poison"<<endl;
        cout<<"3. Leave"<<endl;
        cout<<"========["<<player->getName()<<"'s WALLET]========"<<endl;
        Currency::listCurrency(player->getWallet());
        cout<<">>>";
        int op;
        while(true){
            cin>>op;
            if(op==1||op==2||op==3)
                break;
            else
                cout<<"Wrong op. Try again"<<endl;
        }
        if(op == 1||op == 2){
            bool canBuy= false;
            if(player->getCurrentHealth()==player->getMaxHealth() && op==1){
                cout<<"Your HP is full. The doctor can't help you anymore."<<endl;
                return true;
            }else if(player->getPoinson()==0 && op ==2){
                cout<<"You are health enough. The doctor can't help you anymore."<<endl;
                return true;
            }
            if(level == 1)
                canBuy = Currency::transaction("Coin",50,player->getWallet());
            else if(level == 2)
                canBuy = Currency::transaction("Silver",50,player->getWallet());
            else if(level == 3)
                canBuy = Currency::transaction("Gold",50,player->getWallet());
            if(canBuy){
                cout<<"You are recovered"<<endl;
                if(op==1)
                    player->setCurrentHealth(player->getMaxHealth());
                else if(op==2)
                    player->setPoison(0);
            }else{
                cout<<"Doctor: There is no such thing as a free lunch."<<endl;
            }
            system("pause");
        }else if(op == 3){
            cout<<"Doctor: Ok,Bye bye."<<endl;
        }
    }else if(occupation == "Chef"){
        cout<<"Chef: Well, well, what have we here? Another hungry soul seeking culinary salvation?"<<endl;
        cout<<"===[COOK (cost 10 ";
        if(level == 1)
            cout<<"coins)]==="<<endl;
        else if(level == 2)
            cout<<"silvers)]==="<<endl;
        else if(level == 3)
            cout<<"golds)]==="<<endl;

        cout<<"Which one do you want to cook?"<<endl;
        int cnt = Consume::listConsume(player->getInventory());
        cout<<cnt+1<<". Leave"<<endl;
        cout<<"========["<<player->getName()<<"'s WALLET]========"<<endl;
        Currency::listCurrency(player->getWallet());
        //input
        cout<<">>>";
        int index;
        while (true){
            cin>>index;
            if(0<=index&&index<=cnt+1)
                break;
            else
                cout<<"Wrong index. Try again"<<endl;
        }
        //output
        if(index == cnt+1){
            cout<<"Chef: OK, bye bye."<<endl;
            return true;
        }
        int toFindConsume = 0;

        while(index){
            if(player->getInventory()[toFindConsume]->getTag()=="Consume"){
                index--;
                if(index==0)
                    break;
            }
            toFindConsume++;
        }

        Consume* consume =dynamic_cast<Consume*>(player->getInventory()[toFindConsume]);
        if(consume == nullptr){
            cout<<"Wrong consume dynamic_cast, NPC triggerEvent"<<endl;
            return false;
        }
        if(!consume->isRaw()){
            cout<<"It has been cooked well."<<endl;
            return true;
        }
        bool canBuy= true;
        if(level == 1)
            canBuy = Currency::transaction("Coin",10,player->getWallet());
        else if(level == 2)
            canBuy = Currency::transaction("Silver",10,player->getWallet());
        else if(level == 3)
            canBuy = Currency::transaction("Gold",10,player->getWallet());
        if(canBuy){
            cout<<"Enjoy your meal"<<endl;
            consume->setRaw(false);
            consume->setHealth(consume->getHealth()+10);
            consume->setHunger(consume->getHunger()+10);
            consume->setThirst(consume->getThirst()+10);
            consume->setPoison(0);
        }else{
            cout<<"Chef: There is no such thing as a free lunch."<<endl;
        }
        system("pause");
    }

    return true;//if the event succeed
}
//mutator
void NPC::setScript(std::string s) {
    script = s;
}
void NPC::setCommodity(vector<Item*> items) {
    commodity = std::move(items);
}

void NPC::setOccupation(const std::string& newO) {
    if(newO=="Chef"||newO=="Merchant"||newO=="Doctor")
        occupation = newO;
    else
        cout<<"Wrong setOccupation"<<endl;
}
//accessor
string NPC::getScript() {
    return script;
}
vector<Item*> NPC::getCommodity() {
    return commodity;
}

string NPC::getOccupation() {
    return occupation;
}