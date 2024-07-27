#include "Currency.h"
Currency::Currency(int c,int s,int g):coin(c),silver(s),gold(g),Item("noName","Currency") {}
Currency::Currency(string newName,int c,int s,int g):coin(c),silver(s),gold(g),Item(newName,"Currency") {}
void Currency::changeMoney(Currency* wallet, int level) {
    Currency* money = wallet;
    int SCrate = level * 4;
    int GSrate = level * 8;
    int GCrate = level * 10;

    while(true){
        cout<<"Let's change!"<<endl;
        cout<<"1. silver -> coin   || The rate is : "<<"1 : "<< SCrate<<endl;
        cout<<"2. Gold   -> silver || The rate is : "<<"1 : "<< GSrate<<endl;
        cout<<"3. Gold   -> coin   || The rate is : "<<"1 : "<< GCrate<<endl;
        cout<<"4. Leave"<<endl;
        cout<<"Note that you can't change the currency from low value to high value\n";
        cout<<"Also note that currency cannot be split\n";
        cout<<"Which option do you want?\n";
        cout<<">>>";
        int op,numUWant,numToCost;
        cin>>op;
        if(op == 4){
            break;
        }
        cout<<"The amount of target currency"<<endl;
        cin>>numUWant;
        if(op == 1){
            if(money->silver * SCrate >= numUWant){
                if(numUWant%SCrate != 0){
                    cout<<"Currency cannot split, so you have to cost one more silver"<<endl;
                    numToCost = numUWant / SCrate +1;
                    while(numToCost > money->silver){
                        cout<<"OOPs, U don't have one more."<<endl;
                        numToCost--;
                    }
                    system("pause");
                }else{
                    numToCost = numUWant / SCrate ;
                }
                money->silver -= numToCost;
                money->coin += numToCost*SCrate;
                listCurrency(money);
                break;
            }
        }else if(op == 2){
            if(money->gold * GSrate >= numUWant) {
                if(numUWant%GSrate != 0){
                    cout<<"Currency cannot split, so you have to cost one more gold"<<endl;
                    numToCost = numUWant / GSrate +1;
                    while(numToCost > money->gold){
                        cout<<"OOPs, U don't have one more."<<endl;
                        numToCost--;
                    }
                    system("pause");
                }else{
                    numToCost = numUWant / GSrate ;
                }
                money->gold -= numToCost;
                money->silver += numToCost*GSrate;
                listCurrency(money);
                break;
            }
        }else if(op == 3){
            if(money->gold * GCrate >= numUWant) {
                if(numUWant%GCrate != 0){
                    cout<<"Currency cannot split, so you have to cost one more gold"<<endl;
                    numToCost = numUWant / GCrate +1;
                    while(numToCost > money->gold){
                        cout<<"OOPs, U don't have one more."<<endl;
                        numToCost--;
                    }
                    system("pause");
                }else{
                    numToCost = numUWant / GCrate ;
                }
                money->gold -= numToCost;
                money->coin += numToCost*GCrate;
                listCurrency(money);
                break;
            }
        }
        cout<<"You don't have enough amount...@@@@@@@@@@"<<endl;
        system("pause");
    }
    cout<<"You leave the change"<<endl;
}

bool Currency::transaction(string money, int dollars, Currency *wallet) {
    if(money == "Coin"){
        if(wallet->coin >= dollars){
            wallet->coin-=dollars;
//            listCurrency(wallet);
            return true;
        }
    }else if(money == "Silver"){
        if(wallet->silver >= dollars){
            wallet->silver-=dollars;
//            listCurrency(wallet);
            return true;
        }
    }else if(money == "Gold"){
        if(wallet->gold >= dollars){
            wallet->gold-=dollars;
//            listCurrency(wallet);
            return true;
        }
    }
//    listCurrency(wallet);
    return false;
}
void Currency::listCurrency(Currency *m) {
//    cout<<"===[Currency]==="<<endl;
    cout<<setw(5)<<left<<"coin:"<<setw(25)<<right<<m->coin<<endl;
    cout<<setw(7)<<left<<"silver:"<<setw(23)<<right<<m->silver<<endl;
    cout<<setw(5)<<left<<"gold:"<<setw(25)<<right<<m->gold<<endl;
}

bool Currency::triggerEvent(Object* _newCurrency){
    auto *newC = dynamic_cast<Currency*>(_newCurrency);
    if(newC == nullptr){
        cout<<"dynamic_cast wrong"<<endl;
        return false;
    }
    coin=newC->getCoin()+coin;
    silver+=newC->getSilver();
    gold+=newC->getGold();
    return true;
}

//accessor
int Currency::getCoin() {
    return coin;
}

int Currency::getSilver() {
    return silver;
}

int Currency::getGold() {
    return gold;
}

//For player getting money
ostream& operator<<(ostream& output,const Currency* currency){
    if(currency->coin>0)
        output << "Coin: +"<<currency->coin<<endl;
    if(currency->silver>0)
        output << "Silver: +"<<currency->silver<<endl;
    if(currency->gold>0)
        output << "Gold: +"<<currency->gold<<endl;
    return output;
}