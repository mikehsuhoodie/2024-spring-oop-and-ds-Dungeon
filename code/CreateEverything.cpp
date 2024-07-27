#include "CreateEverything.h"



vector<Object *> CreateEverything::createObjects(int index) {
    vector<Object*> objs;
    if(index==0){ //Entrance
        vector<Item*> commodity;
        Value arcanceEdge{100,"Gold"};
        commodity.push_back(new Weapon("Arcane Edge",10,10,arcanceEdge));
        //Money Wand
//        commodity.push_back(new Weapon("Money Wand",10,10,arcanceEdge));
        commodity.push_back(new Currency("A small pouch of coins",20,0,0));
        objs.push_back(new NPC("MIKE","Remember. Create Explore Expand Conquer.","Talker",commodity));
    }else if (index==1||index==5||index==8){ //Desert
        //NPC
        vector<Item*> commodity;
        Value LEpotion={100,"Coin"};
        Value AEpotion={50,"Coin"};
        Value DEpotion={50,"Coin"};
        Value RE = {100,"Silver"};
        commodity.push_back(new Consume("Life Enhancement Potion",30,0,0,0,0,0,LEpotion));
        commodity.push_back(new Consume("Attack Enhancement Potion",0,30,0,0,0,0,AEpotion));
        commodity.push_back(new Consume("Defense Enhancement Potion",0,0,30,0,0,0,DEpotion));
        commodity.push_back(new Consume("Revitalizing Elixir",0,0,0,50,50,-50,RE));
        objs.push_back(new NPC("Merchant","Quality goods at fair prices, guaranteed.","Merchant",commodity));
        //Monster
        vector<Item*> drops;
        Value dropsValue;
        dropsValue.dollar=25;
        if(index==1){
            dropsValue.currency="Coin";
            drops.push_back(new Currency("Bounty",20,0,0));
        }
        else if(index==5){
            dropsValue.currency="Silver";
            drops.push_back(new Currency("Bounty",0,20,0));
        }
        else{
            dropsValue.currency="Gold";
            drops.push_back(new Currency("Bounty",0,0,20));
        }
        drops.push_back(new Consume("Scorpion Meat",50,50,50,100,dropsValue,true));
        objs.push_back(new Monster("Desert Scorpion",20,10,20,drops));
        Value cactusValue = {10, "Coin"};
        objs.push_back(new Consume("Cactus Fruit", 5, 10, 15, 0, cactusValue, false));
        Value boxingValue = {20, "Coin"};
        if(index == 1)
        objs.push_back(new Weapon("Boxing Gloves",20,10,boxingValue));
    }else if (index==2||index==7||index==9){ //Forest
        //NPC
        vector<Item*> commodity;
        commodity.push_back(new Currency("Doctor's Property",5,150,10));
        objs.push_back(new NPC("Doctor","Let's get you feeling better soon.","Doctor",commodity));
        //Monster
        vector<Item*> drops;
        Value dropsValue;
        dropsValue.dollar=30;
        if(index==2){
            dropsValue.currency="Coin";
            drops.push_back(new Currency("Bounty",20,0,0));
        }
        else if(index==7){
            dropsValue.currency="Silver";
            drops.push_back(new Currency("Bounty",0,20,0));
        }
        else{
            dropsValue.currency="Gold";
            drops.push_back(new Currency("Bounty",0,0,20));
        }
        drops.push_back(new Consume("Wild Game Meat",10,20,5,20,dropsValue,true));
        if(index==2)
            objs.push_back(new Monster("Shadow Wolf",20,10,5,drops));
        else if(index==7)
            objs.push_back(new Monster("Wild Wolf",20,15,8,drops));
        else
            objs.push_back(new Monster("Beta Wild Wolf",25,25,12,drops));
    }else if (index==3||index==6||index==10){ //Swamp
        vector<Item*> commodity;
        commodity.push_back(new Currency("Chef's Property",500,10,10));
        objs.push_back(new NPC("Chef","Cooking is my passion, and I'm thrilled to share it with you.","Chef",commodity));
        //Monster
        vector<Item*> drops;
        Value dropsValue;
        dropsValue.dollar=25;
        if(index==3){
            dropsValue.currency="Coin";
            drops.push_back(new Currency("Bounty",30,0,0));
        }
        else if(index==6){
            dropsValue.currency="Silver";
            drops.push_back(new Currency("Bounty",0,30,0));
        }else{
            dropsValue.currency="Gold";
            drops.push_back(new Currency("Bounty",0,0,30));
        }
        drops.push_back(new Consume("Slime Jelly",5,5,100,25,dropsValue,true));
        objs.push_back(new Monster("Mud Elemental",50,5,3,drops));

    }else if(index==4){
        //NPC
        vector<Item*> chefCommodity;
        chefCommodity.push_back(new Currency("Chef's Property",500,10,10));
        objs.push_back(new NPC("Chef","Cooking is my passion, and I'm thrilled to share it with you.","Chef",chefCommodity));

        vector<Item*> doctorCommodity;
        doctorCommodity.push_back(new Currency("Doctor's Property",5,150,10));
        objs.push_back(new NPC("Doctor","Let's get you feeling better soon.","Doctor",doctorCommodity));

        vector<Item*> commodity;
        Value LEpotion={75,"Coin"};
        Value AEpotion={35,"Coin"};
        Value DEpotion={35,"Coin"};
        Value RE = {75,"Silver"};
        Value MW = {20,"Silver"};
        commodity.push_back(new Consume("Maelstrom Brew",-5,20,0,0,10,10,LEpotion));
        commodity.push_back(new Consume("Titan's Draught",20,0,20,20,0,0,AEpotion));
        commodity.push_back(new Consume("Celestial Essence Extract",20,0,10,0,0,-100,DEpotion));
        commodity.push_back(new Consume("Feast of Plenty Elixir",0,0,0,50,50,-50,RE));
        commodity.push_back(new Weapon("Money Wand",0,0,MW));
        objs.push_back(new NPC("Merchant","Quality goods at fair prices, guaranteed.","Merchant",commodity));
    }else if(index==11){
        //Monsters
        vector<Item*> MEdrops;
        Value dropsValue={25,"Gold"};
        MEdrops.push_back(new Consume("Slime Jelly",5,5,100,25,dropsValue,true));
        objs.push_back(new Monster("MAD Mud Elemental",50,50,5,MEdrops));
        vector<Item*> DSdrops;
        DSdrops.push_back(new Consume("Scorpion Meat",50,50,50,100,dropsValue,true));
        objs.push_back(new Monster("Desert Scorpion",10,20,10,DSdrops));
        vector<Item*> SWdrops;
        SWdrops.push_back(new Consume("Wild Game Meat",10,20,5,20,dropsValue,true));
        objs.push_back(new Monster("Shadow Wolf",22,35,5,SWdrops));
    }else if(index==12){

    }else
        cout<<"Wrong index"<<endl;
    return objs;
}

