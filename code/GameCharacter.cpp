#include "GameCharacter.h"
GameCharacter::GameCharacter() = default;
GameCharacter::GameCharacter(std::string newName, std::string newTag, int newMaxHealth=0, int newAtk=0, int newDefense=0)
    : Object(newName,newTag) {
    maxHealth = newMaxHealth;
    currentHealth = newMaxHealth;
    attack = newAtk;
    defense = newDefense;
}

bool GameCharacter::checkIsDead() {
    if(getCurrentHealth()<=0)
        return true;
    return false;
}

void GameCharacter::fight(string attacker, string opponent, int Hval, int Aval, int Dval) {//use in action between characters(fight,heal)
    if (Hval == 0 && Aval == 0 && Dval == 0)// The function is not use
        return;
    if (Hval > 0)
        cout << attacker << " heals " << opponent <<" "<< Hval << " points." << endl;
    if (Aval > 0)
        cout << attacker << " attacks " << opponent <<" "<< Aval << " points." << endl;
    if (Dval > 0)
        cout << opponent << " defenses " << Dval << " points." << endl;

    int total = Hval - Aval + Dval;

    if (Dval >= Aval)// Defense is lager than attack => attack = 0
        total = Hval;

    currentHealth += total;
    if (total > 0)
        cout <<opponent<<"+" << total << " HP" << endl;
    else if(total == 0)
        cout <<opponent<<"-"<<total<<" HP"<<endl;
    else
        cout <<opponent<< " " << total << " HP" << endl;
//    system("pause");

}


void GameCharacter::changeState(int healVal, int attackVal, int defenseVal){ //use in action between player and item(potion,food)
    if(healVal==0&&attackVal==0&&defenseVal==0)// The function is not use
        return;
    if(healVal != 0){
        if(healVal>0)
            cout<<"Health: +"<<healVal<<endl;
        else
            cout<<"Health: "<<healVal<<endl;
    }
    if(defenseVal != 0){
        if(defenseVal>0)
            cout<<"Defense: +"<<defenseVal<<endl;
        else
            cout<<"Defense: "<<defenseVal<<endl;
    }
    if(attackVal != 0){
        if(attackVal>0)
            cout << "Attack: +" << attackVal << endl;
        else
            cout << "Attack : " << attackVal << endl;
    }
    currentHealth+=healVal;
    defense+=defenseVal;
    attack+=attackVal;
}


//mutator
void GameCharacter::setMaxHealth(int m) {
    maxHealth = m;
}
void GameCharacter::setCurrentHealth(int c) {
    currentHealth = c;
}
void GameCharacter::setAttack(int a) {
    attack = a;
}
void GameCharacter::setDefense(int d) {
    defense = d;
}
//accessor
int GameCharacter::getMaxHealth() {
    return maxHealth;
}
int GameCharacter::getCurrentHealth() {
    return currentHealth;
}
int GameCharacter::getAttack() {
    return attack;
}
int GameCharacter::getDefense() {
    return defense;
}