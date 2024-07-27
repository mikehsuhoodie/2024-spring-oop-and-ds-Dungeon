#include "Dungeon.h"
Dungeon::Dungeon(): player("NoName",100, 5, 5, 100, 100, 0) {round=0; activityRound=-1;}

void Dungeon::createPlayer() {
    string newName;
    cout<<"What's your name?"<<endl;
    cout<<">>>";
    getline(cin, newName);
    player.setName(newName);

}

void Dungeon::createMap() {
    rooms.reserve(13);
    CreateEverything creator;
    vector<vector<Object*>> objsInRooms(13);
    for(int i=0;i < 13;i++){
        objsInRooms[i] = creator.createObjects(i);
    }
    rooms.emplace_back(false,0,"Magical Gate","Entrance",objsInRooms[0]);
    rooms.push_back(Room(false,1,"Sandstorm Desert","Desert",objsInRooms[1]));
    rooms.push_back(Room(false,2,"Whispering Woods","Forest",objsInRooms[2]));
    rooms.push_back(Room(false,3,"Misty Marsh","Swamp",objsInRooms[3]));
    rooms.push_back(Room(false,4,"Golden Haven","Market",objsInRooms[4]));
    rooms.push_back(Room(false,5,"Arid Wasteland","Desert",objsInRooms[5]));
    rooms.push_back(Room(false,6,"Misty Marsh","Swamp",objsInRooms[6]));
    rooms.push_back(Room(false,7,"Emerald Grove","Forest",objsInRooms[7]));
    rooms.push_back(Room(false,8,"Mirage Sands","Desert",objsInRooms[8]));
    rooms.push_back(Room(false,9,"Enchanted Forest","Forest",objsInRooms[9]));
    rooms.push_back(Room(false,10,"Misty Marsh","Swamp",objsInRooms[10]));
    rooms.push_back(Room(false,11,"Demon King's Gate","Final",objsInRooms[11]));
    rooms.push_back(Room(true,12,"The Freedom Gateway","Exit",objsInRooms[12]));

    rooms[0].setDownRoom(&rooms[1]);
    rooms[1].setUpRoom(&rooms[0]);
    rooms[1].setRightRoom(&rooms[2]);
    rooms[1].setLeftRoom(&rooms[3]);
    rooms[2].setLeftRoom(&rooms[1]);
    rooms[2].setDownRoom(&rooms[5]);
    rooms[3].setRightRoom(&rooms[1]);
    rooms[3].setDownRoom(&rooms[7]);
    rooms[4].setRightRoom(&rooms[5]);
    rooms[4].setLeftRoom(&rooms[7]);
    rooms[5].setLeftRoom(&rooms[4]);
    rooms[5].setUpRoom(&rooms[2]);
    rooms[5].setRightRoom(&rooms[6]);
    rooms[5].setDownRoom(&rooms[9]);
    rooms[6].setLeftRoom(&rooms[5]);
    rooms[7].setUpRoom(&rooms[3]);
    rooms[7].setRightRoom(&rooms[4]);
    rooms[7].setLeftRoom(&rooms[8]);
    rooms[7].setDownRoom(&rooms[10]);
    rooms[8].setRightRoom(&rooms[7]);
    rooms[9].setUpRoom(&rooms[5]);
    rooms[9].setLeftRoom(&rooms[11]);
    rooms[10].setUpRoom(&rooms[7]);
    rooms[10].setRightRoom(&rooms[11]);
    rooms[11].setRightRoom(&rooms[9]);
    rooms[11].setLeftRoom(&rooms[10]);
    rooms[11].setDownRoom(&rooms[12]);
    rooms[12].setUpRoom(&rooms[11]);
    player.setCurrentRoom(&rooms[0]);
}

void Dungeon::showMap(){
    cout<<"       ___  _   _ _  _  ___ ___ ___  _  _ \n"
          "      |   \\| | | | \\| |/ __| __/ _ \\| \\| |\n"
          "      | |) | |_| | .` | (_ | _| (_) | .` |\n"
          "      |___/ \\___/|_|\\_|\\___|___\\___/|_|\\_|"<<endl;
    cout<<endl;
    cout<<"                    [Room 0]\n"
          "                       ||\n"
          "          [Room 3]==[Room 1]==[Room 2]\n"
          "             ||                  ||\n"
          "[Room 8]==[Room 7]==[MARKET]==[Room 5]==[Room 6]\n"
          "             ||                  ||\n"
          "          [Room10]\\          /[Room 9]\n"
          "                   \\\\[BOSS]//"<<endl;
}

bool Dungeon::handleMovement() {
    Room* r=player.getCurrentRoom();
    cout<<setw(8)<<left<<"OPTION"<<right<<'|';
    cout<<setw(20)<<right<<"PLACE NAME"<<right<<'|';
    cout<<setw(6)<<"LEVEL"<<right<<'|';
    cout<<setw(6)<<"BIOME"<<endl;
    if(r->getUpRoom()){
        cout<<setw(9)<<left<<"UP(w)";
        cout<<setw(20)<<right<<r->getUpRoom()->getName();
        cout<<setw(7)<<r->getUpRoom()->getLevel();
        cout<<setw(7)<<r->getUpRoom()->getBiome()<<endl;
    }
    if(player.getCurrentRoom()->getDownRoom()){
        cout<<setw(9)<<left<<"DOWN(s)";
        cout<<setw(20)<<right<<r->getDownRoom()->getName();
        cout<<setw(7)<<r->getDownRoom()->getLevel();
        cout<<setw(7)<<r->getDownRoom()->getBiome()<<endl;
    }
    if(player.getCurrentRoom()->getLeftRoom()){
        cout<<setw(9)<<left<<"LEFT(a)";
        cout<<setw(20)<<right<<r->getLeftRoom()->getName();
        cout<<setw(7)<<r->getLeftRoom()->getLevel();
        cout<<setw(7)<<r->getLeftRoom()->getBiome()<<endl;
    }
    if(player.getCurrentRoom()->getRightRoom()){
        cout<<setw(9)<<left<<"Right(d)";
        cout<<setw(20)<<right<<r->getRightRoom()->getName();
        cout<<setw(7)<<r->getRightRoom()->getLevel();
        cout<<setw(7)<<r->getRightRoom()->getBiome()<<endl;
    }
    char op;
    cout<<">>>";
    cin>>op;
    while(op!='w' && op!='s' && op != 'd' && op != 'a'){
        cout<<"Typo. Try again."<<endl;
        cout<<"L. Leave"<<endl;
        cin>>op;
        if(op=='L')
            return false;
    }
    switch (op){
        case 'w':
            if(player.getCurrentRoom()->getUpRoom()== nullptr){
                cout<<"There's no path to the Up room."<<endl;
                return false;
            }
            player.changeRoom(player.getCurrentRoom()->getUpRoom());
            cout<<"You went up."<<endl;
            break;
        case 's':
            if(player.getCurrentRoom()->getDownRoom()== nullptr){
                cout<<"There's no path to the Down room."<<endl;
                return false;
            }
            player.changeRoom(player.getCurrentRoom()->getDownRoom());
            cout<<"You went down."<<endl;
            break;
        case 'd':
            if(player.getCurrentRoom()->getRightRoom()== nullptr){
                cout<<"There's no path to the Right room."<<endl;
                return false;
            }
            player.changeRoom(player.getCurrentRoom()->getRightRoom());
            cout<<"You went right."<<endl;
            break;
        case 'a':
            if(player.getCurrentRoom()->getLeftRoom()== nullptr){
                cout<<"There's no path to the Left room."<<endl;
                return false;
            }
            player.changeRoom(player.getCurrentRoom()->getLeftRoom());
            cout<<"You went left."<<endl;
            break;
        default:
            cout<<"Wrong op"<<endl;
            return false;
    }
    return true;
}

bool Dungeon::handleEvent(Object *obj) {
    bool finish = obj->triggerEvent(&player);
    if(finish){
        if(obj->getTag()!="NPC")
            player.getCurrentRoom()->popObject(obj);
    }else{
        if(obj->getTag()=="Monster"){
            return false;
        }else{
            cout<<"Fail to interact."<<obj->getName()<<endl;
        }
    }
    return true;
}

bool Dungeon::activity() {
    string biome = player.getCurrentRoom()->getBiome();
    if(biome == "Entrance"){
        cout<<"  .-')\n"
              " ( OO ).\n"
              "(_)---\\_)"<<endl;
        cout<<"Welcome! Challenger: "<<player.getName()<<endl;
        cout<<"Find the best method to defeat the monster!"<<endl;
        cout<<"Also, remember to eat food."<<endl;
        cout<<"After all, you can't do anything on an empty stomach, right?"<<endl;
        system("pause");
        cout<<"So now, enjoy the battles!"<<endl;
        cout<<"You'll soon see me, won't you?"<<endl;
        system("pause");
    }else if(biome == "Desert"){
        if(roundToLast>0){
            player.changeHungerSystem(-10,-10,0);
            player.checkHS();
            roundToLast--;
            return true;
        }
        srand(time(nullptr));
        int dice = rand()%4;
        if(dice == 0){
            cout<<"You discovered an oasis and replenished your water supply."<<endl;
            player.changeHungerSystem(0,20,0);
        }else{
            cout<<"Ah ah ah ahhhh"<<endl;
            cout<<"You encountered ";
            if(dice == 1){
                cout<<"a normal ";
            }else if(dice ==2){
                cout<<"a severe ";
            }else {
                cout<<"an apocalyptic ";
            }
            roundToLast = dice;
            cout<<"sandstorm,"<<endl;
            cout<<"so your thirst and hunger will decrease by 10 following "<<roundToLast<<" rounds."<<endl;
        }
        return true;
    }else if(biome == "Forest"){
        srand(time(nullptr));
        int dice = rand()%2;
        if(dice == 0){
            cout<<"Your stomach is rumbling."<<endl;
            cout<<"The forest in this area is too dense, requiring a lot of effort to move through."<<endl;
            cout<<"Therefore, your hunger will decrease by five."<<endl;
            player.changeHungerSystem(-5,0,0);
        }else if(dice == 1){
            cout<<"You encounter a lake, "<<endl;
            cout<<"so your thirst increases by 15 points."<<endl;
            player.changeHungerSystem(0,15,0);
        }
        player.checkHS();
    }else if(biome == "Swamp"){
        cout<<"Croak Croak"<<endl;
        cout<<"You encountered a swamp poison frog."<<endl;
        cout<<"Your poison will increase by five."<<endl;
        player.changeHungerSystem(0,0,5);
        player.checkHS();
    }else if(biome == "Market"){
        cout<<"We don't ask questions, just business."<<endl;
        cout<<"><><><><[BLACK MARKET]><><><><"<<endl;
        cout<<"1. Sell"<<endl;
        cout<<"2. Leave"<<endl;
//        cout<<"3. BUY"<<endl;
        int op;
        bool valid= false;
        while(!valid){
            cout<<">>>";
            if(!(cin>>op)||op<1||op>2){
                cout << "Invalid input. Try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
                valid= true;
        }
        if(op==1){
            cout<<"What kind of goods do you have?"<<endl;
            int numOfGoods = listGoods(player.getInventory());
            cout<<numOfGoods+1<<". Leave"<<endl;
            cout<<">>>";
            int index;
            cin>>index;
            index--;
            if(index == numOfGoods){
                cout<<"OK. BYE BYE"<<endl;
            }else{
                cout<<"Mysterious Merchant: Deal."<<endl;
                Currency* income = new Currency(0,0,0);
                Value* value = player.getInventory()[index]->getValue();
                if(value->currency=="Coin")
                    income= new Currency("Income",value->dollar,0,0);
                else if(value->currency=="Silver")
                    income= new Currency("Income",0,value->dollar,0);
                else if(value->currency=="Gold")
                    income= new Currency("Income",0,0,value->dollar);
                player.addItem(income);
                player.popItem(player.getInventory()[index]);
                system("pause");
            }
        }else if(op==2)
            cout<<"OK. BYE BYE"<<endl;
//        else if(op==2){
//            cout<<"Mysterious Merchant: The value of these goods goes beyond money."<<endl;
//
//        }
    }else if(biome == "Final"){
        cout<<"  .-')\n"
              " ( OO ).\n"
              "(_)---\\_)"<<endl;
        cout<<"We meet again."<<endl;
        cout<<"Looks like you've gotten quite strong."<<endl;
        system("pause");
        cout<<"Indeed, that's my intention."<<endl;
        cout<<"To make you stronger and then defeat you. Ha!"<<endl;
        cout<<"Boss makes your HP full"<<endl;
        player.setCurrentHealth(player.getMaxHealth());
        system("pause");
        cout<<"Now, you should choose one English letter from the options below."<<endl;
        cout<<"If it matches the Boss's chosen letter, the Boss will lose 10 HP."<<endl;
        cout<<"Otherwise, you will lose 10 HP. (Case-insensitive)"<<endl;
        int BossHP = 30;
        while(BossHP){
            srand(time(nullptr));
            vector<char> str(4);
            for(int i=0;i<str.size();i++){
                str[i] = static_cast<char>(rand() % ('Z'-'A' + 1) + 'A');
                for(int j=0;j<i;j++){
                    if(str[j]==str[i])
                        i--;
                }
            }
            int randomNum = rand() %4;
            char op;
            cout<<player.getName()<<": "<<player.getCurrentHealth()<<" HP"<<endl;
            cout<<"Boss: "<<BossHP<<" HP"<<endl;
            cout<<"CHOOSE ONE"<<endl;
            cout<<"  .-')\n"
                  " ( OO ).\n"
                  "(_)---\\_)"<<endl;
            cout<<" _____  _____  _____  _____ "<<endl;
            cout<<R"(|\   /||\   /||\   /||\   /|)"<<endl;
            cout<<"|  "<<str[0]<<"  ||  "<<str[1]<<"  ||  "<<str[2]<<"  ||  "<<str[3]<<"  |"<<endl;
            cout<<R"(|/___\||/___\||/___\||/___\|)"<<endl;
            cout<<">>>";
            cin>>op;
            cout<<"Boss's selection: "<<str[randomNum]<<endl;
            if(op==str[randomNum]){
                cout<<"Boss: Awwww"<<endl;
                BossHP-=10;
            }else{
                player.fight("Boss",player.getName(),0,10,0);
            }
            if(player.checkIsDead())
                return false;
        }
        cout<<"  .-')\n"
              " ( XX ).\n"
              "(_)---\\_)"<<endl;
        cout<<"Boss: You've defeated me!"<<endl;
        cout<<"What a lucky person you are!"<<endl;
        cout<<"But in real life, luck is also a part of one's strength, isn't it?"<<endl;
    }
    return true;
}

bool Dungeon::chooseAction() {

    Room *curRoom=player.getCurrentRoom();
    string biome = curRoom->getBiome();
    vector<Object*> objs = curRoom->getObjects();
    int size = objs.size();
    bool haveMonster=false;
    bool hasConsume = player.hasConsume();
    bool generalRoom = (biome!="Final")&&(biome!="Market");

    cout<<"You are in Room "<<curRoom->getIndex()<<" level "<<curRoom->getLevel()<<endl;
    if(curRoom->isFinished()&&generalRoom){
        cout<<"Here is Nothing..."<<endl;
        cout<<"Let's go to another room."<<endl;
        system("pause");
        handleMovement();
        return false;
    }

    //set/check Activity
    if(biome!="Market" && biome!="Final" && biome!="Entrance"){
        if(round==0){
            srand(time(nullptr));
            activityRound = rand()%(size+1);
        }
        if(round == activityRound){
            cout<<"Wait. Something happened."<<endl;
            system("pause");
            activity();
            system("pause");
            activityRound=-1;
        }
        if(biome=="Desert"&&roundToLast>0){
            cout<<"Sandstorm last "<<roundToLast<<" round"<<endl;
            activity();
        }else{
            roundToLast=0;
        }
    }else if(biome=="Entrance"&&round==0)
        activity();
    //Show option
    for(int i=0;i<size;i++){
        if(objs[i]->getTag()=="Monster"){
            cout<<i+1<<". Fight against "<<objs[i]->getName()<<endl;
            haveMonster=true;
        }else if(objs[i]->getTag()=="NPC")
            cout<<i+1<<". Interact with "<<objs[i]->getName()<<endl;
        else{
            cout<<i+1<<". Pick up "<<objs[i]->getName()<<endl;
        }

    }
    if(biome == "Market"){
        cout<<"$. Trade in Black Market"<<endl;
    }
    cout<<"N. Check The Map"<<endl;
    cout<<"S. Show Status"<<endl;
    if(hasConsume){
        cout<<"C. Consume something"<<endl;
    }
    if(haveMonster){
        cout<<"(When finish all monsters, you can move to another room)"<<endl;
    }else{
        if(biome=="Final"){
            if(!activity())
                return false;
        }
        cout<<"M. Move"<<endl;
    }

    //input

    char input;
    int op;
    while(true){
        cout<<">>>";
        cin>>input;
        if('0'<=input && input<='9'){
            op = static_cast<int>(input) -48;
            if(0<=op&&op<=size)
                break;
        }else if(input == 'M'||input == 'S'||input == 'C'||input == '$'||input=='N')
            break;
        cout<<"Wrong OP. Try again"<<endl;
    }
    op--;
    if(input == 'N'){
        showMap();
        system("pause");
        return false;
    }else if(input == 'S'){
        player.triggerEvent(&player);
        return false;
    }else if(input == 'M'){
        if(!handleMovement())
            return false;
        round=0; // Move to a new room, set round to zero
        activityRound = -1;// Move to a new room, set activityRound to -1
        system("pause");
        return true;
    }else if(input == 'C'){
        Consume::eatWhat(&player);
        player.checkHS();
        if(player.checkIsDead())
            return false;
    }
    else if(input == '$'){
        activity();
    }
    else{
        //Pick up item
        Item* it = dynamic_cast<Item*>(objs[op]);
        if(it!= nullptr){
            player.addItem(it);
            curRoom->popObject(objs[op]);
        }else{
            //NPC or Monster
            bool event = handleEvent(objs[op]);
            //Monster: retreat case
            if(!event){//retreat
                cout<<"You've been transmitted to previous room."<<endl;
                player.setCurrentRoom(player.getPreviousRoom());
                round=0;
                activityRound=-1;
                return true;
            }
        }
    }
    round++;
    return true;
}

void Dungeon::updateStatus(std::string biome) {
    if(round == 0)
        return;
    int hunger=0,thirst=0,poison=0;
    cout<<"[Status Update] Biome: "<<biome<<endl;
    if(biome == "Desert"){
        hunger = -5;
        thirst = -8;
    }else if(biome == "Forest"){
        hunger = -8;
        thirst = -5;
    }else if(biome == "Swamp"){
        hunger = -3;
        thirst = -3;
        poison = 7;
    }else if(biome == "Market"){
        hunger = -5;
        thirst = -5;
    }else if(biome == "Final"){
        hunger = -5;
        thirst = -5;
        poison = 5;
    }
    player.changeHungerSystem(hunger,thirst,poison);
    system("pause");
}

void Dungeon::startGame() {
    cout<<"PRESS TO START\n";
    system("pause");
    createPlayer();
    createMap();

}

bool Dungeon::checkGameLogic() { //0 is end, 1 is continued
    if(player.getCurrentRoom()->getIsExit())
        return false;
    return !player.checkIsDead();
}

void Dungeon::runDungeon() {
    startGame();
    while(checkGameLogic()){
        if(chooseAction()){
            //Update Status
            string biome = player.getCurrentRoom()->getBiome();
            if(player.checkIsDead()){
                cout<<"You have died."<<endl;
                break;
            }
            else if(biome!="Entrance"&&round>0)
                updateStatus(biome);
        }
        cout<<"------------------------------"<<endl;
    }
    if(!player.checkIsDead()){
        cout<<"__      _____ _  _ \n"
              "\\ \\    / /_ _| \\| |\n"
              " \\ \\/\\/ / | || .` |\n"
              "  \\_/\\_/ |___|_|\\_|"<<endl;
    }else{
        cout<<" _    ___  ___ ___ \n"
              "| |  / _ \\/ __| __|\n"
              "| |_| (_) \\__ \\ _| \n"
              "|____\\___/|___/___|"<<endl;
    }
    system("pause");
}


//
//                    [Room 0]
//                       ||
//          [Room 3]==[Room 1]==[Room 2]
//             ||                  ||
//[Room 8]==[Room 7]==[MARKET]==[Room 5]==[Room 6]
//            ||                  ||
//          [Room10]\          /[Room 9]
//                   \\[BOSS]//
//