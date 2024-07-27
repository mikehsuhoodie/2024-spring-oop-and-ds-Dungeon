#include "Monster.h"
Monster::Monster() = default;
Monster::Monster(string newName, int newH, int newA, int newD,vector<Item*> newDrops)
    : GameCharacter(newName,"Monster",newH,newA,newD){
    drops = newDrops;
}


bool Monster::triggerEvent(Object * _player) {
    Player* player = dynamic_cast<Player*>(_player);
    if(player== nullptr)
        return false;
    cout<<"You("<<player->getName()<<") want to fight "<<getName()<<endl;
    int round=1;
    while(!checkIsDead()){
        cout<<"----------{ROUND "<<round<<"}-----------"<<endl;
        cout<<player->getName()<<": "<<player->getCurrentHealth()<<" HP, "<<player->getAttack()<<" AP, "<<player->getDefense()<<" DP, "
        <<player->getPoinson()<<" PP(poison points)"<<endl;
        cout<<getName()<<": "<<getCurrentHealth()<<" HP, "<<getAttack()<<" AP, "<<getDefense()<<" DP"<<endl;
        cout<<"=========[Your round]========="<<endl;
        cout<<"1.Fight"<<endl;
        cout<<"2.Retreat (You will be transmitted to previous room)"<<endl;
        int op;
        bool validInput = false;
        while (!validInput){
            cout<<">>>";
            if (!(cin >> op) || op<1 || op>2) {
                cout << "Invalid input. Try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                validInput = true;
            }
        }
        if(op ==2){ //Retreat
            cout<<"You retreated."<<endl;
            system("pause");
            return false;
        }
        cout<<"Which weapon do you want to attack?"<<endl;
        vector<Item*> playerInventory = player->getInventory();
        int n = listOneType(playerInventory,"Weapon");
        cout<<n+1<<". Retreat (You will be transmitted to previous room)"<<endl;

        int index;
        validInput= false;
        while(!validInput){
            cout<<">>>";
            if(!(cin>>index)||index<0||index>n+1){
                cout << "Wrong option. Try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else
                validInput= true;
        }
        int cnt =0;
        if(index == n+1){ //Retreat
            cout<<"You retreated."<<endl;
            system("pause");
            return false;
        }
        while(index){
            if(playerInventory[cnt]->getTag()=="Weapon"){
                index--;
                if(index==0)break;
            }
            cnt++;
        }
        cout<<"You used "<<playerInventory[cnt]->getName()<<endl;
        auto *toUse = dynamic_cast<Weapon*>(playerInventory[cnt]);
        if(toUse== nullptr){
            cout<<"dynamic_cast false toUse"<<endl;
            return false;
        }
        int damage = toUse->fight(getName()) - player->getPoinson() + player->getAttack();
        if(damage<0)
            damage=0;
        if(player->getPoinson()>0){
            cout<<"Your poison level weakens your attacks."<<endl;
            cout<<"Now your attack is only "<<damage<<endl;
        }
        fight(player->getName(),getName(),0,damage,getDefense());
        if(checkIsDead())
            break;
        system("pause");
//        Monster round
        cout<<"=======["<<getName()<< " Round]======="<<endl;
        int def = player->getDefense() - player->getPoinson();
        if(def <0)
            def=0;
        if(player->getPoinson()>0){
            cout<<"Your poison level weakens your defense."<<endl;
            cout<<"Now your defense is only "<<def<<endl;
        }
        player->fight(getName(),player->getName(),0,getAttack(),def);
        if(player->checkIsDead())
            return true;
        else
            round++;
    }

    cout<<"You beat "<<getName()<<endl;
    system("pause");
    cout<<"Here's the drops: "<<endl;
    while (!drops.empty()){
        cout<<"Which one do you want?"<<endl;
        int n = listItems(drops);
        cout<<n+1<<". Leave"<<endl;
        cout<<">>>";
        int op;
        while(true){
            cin>>op;
            if(0<=op&&op<=n+1)
                break;
            else
                cout<<"Wrong op. Try again"<<endl;
        }
        op--;
        if(n==op)
            break;
        player->addItem(drops[op]);
        drops.erase(drops.begin()+op);
        n--;
    }
    return true;
}

void Monster::setDrops(vector<Item *> newDrops) {
    drops = newDrops;
}

vector<Item *> Monster::getDrops() {
    return drops;
}