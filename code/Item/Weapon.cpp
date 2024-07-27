#include "Weapon.h"
Weapon::Weapon(string newName,  int newAtk, int newDef,Value v):Item(newName,newAtk,newDef,v){}
//bool Weapon::triggerEvent(Object* _opponent){
//    if(_opponent->getTag() == "Monster"){
//        Monster* opponent = dynamic_cast<Monster*>(_opponent);
//        if(opponent == nullptr)
//            return false;
//        //take damage
//        opponent->fight(host->getName(),opponent->getName(),0, fight(), opponent->getDefense());
//
//    }else if(_opponent->getTag() == "NPC"){
//        NPC* opponent = dynamic_cast<NPC*>(_opponent);
//        if(opponent == nullptr)
//            return false;
//        opponent->fight(host->getName(),opponent->getName(),0, fight(), opponent->getDefense());
//        getHost()->notorious++;
//    }
//    return true;
//}

int Weapon::fight(string opponent){
    int val = 0;
    if(getName()=="Boxing Gloves"){
        val = getAttack();
    }else if(getName()=="Money Wand"){
        cout<<"Enter your ATM card password: ";
        string input;
        cin>>input;
        int numDigits = input.length();
        char medianChar = input[numDigits / 2];
        int median = medianChar - '0';
        val =medianChar*median%100;
    }else if(getName()=="Arcane Edge"){
        cout<<"Input an alphabet as your attack."<<endl;
        char a;
        bool continueLoop = true;
        while(continueLoop){
            cout<<">>>";
            cin>>a;
            if(a == opponent[0]){
                cout<<"You hit the monster's weak spot, causing it to die instantly."<<endl;
                val=9999;
                break;
            }
            if(!isalpha(a) ){
                cout << "Invalid input. Try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else if(islower(a)){
                cout<<"You choose lower case"<<endl;
                val = static_cast<int>(a)-90;
                continueLoop= false;
            }else{
                cout<<"You choose upper case"<<endl;
                val = static_cast<int>(a)-60;
                continueLoop= false;
            }
        }
    }
//    system("pause");
    return val;
}
//mutator
//void Weapon::setHost(Player *p) {
//    host = p;
//}
//
//
////accessor
//Player* Weapon::getHost() {
//    return host;
//}
