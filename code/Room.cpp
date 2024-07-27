#include "Room.h"
Room::Room() = default;
Room::Room(bool ifIsExit, int newIndex,string newName,string newBiome, vector<Object *> newObj) {
    isExit = ifIsExit;
    index = newIndex;
    biome = newBiome;
    objects = newObj;
    name = newName;
    upRoom= nullptr;
    downRoom= nullptr;
    leftRoom= nullptr;
    rightRoom= nullptr;
}

bool Room::popObject(Object *obj) {
    for(int i=0;i<objects.size();i++){
        if(objects[i] == obj){
            objects.erase(objects.begin()+i);
            return true;
        }
    }
    return false;
}

//mutator
void Room::setUpRoom(Room *r) {
    upRoom = r;
}
void Room::setDownRoom(Room *r) {
    downRoom = r;
}

void Room::setLeftRoom(Room *r) {
    leftRoom = r;
}
void Room::setRightRoom(Room *r) {
    rightRoom = r;
}
void Room::setIsExit(bool e) {
    isExit = e;
}
void Room::setIndex(int i) {
    index = i;
}
void Room::setObjects(vector<Object *> objs) {
    objects = objs;
}

//accessor
string Room::getName() {
    return name;
}
string Room::getBiome() {
    return biome;
}
bool Room::getIsExit() const {
    return isExit;
}
int Room::getIndex() {
    return index;
}
int Room::getLevel() {
    if(index == 0)
        return 0;
    else if(index <=3)
        return 1;
    else if(index <=8)
        return 2;
    else if(index <=10)
        return 3;
    else if(index == 12)
        return 0;
    else
        return 999;
}
vector<Object *> Room::getObjects() {
    return objects;
}
Room *Room::getUpRoom() {
    return upRoom;
}
Room *Room::getDownRoom() {
    return downRoom;
}
Room *Room::getLeftRoom() {
    return leftRoom;
}
Room *Room::getRightRoom() {
    return rightRoom;
}

//check
bool Room::isFinished(){
    return objects.empty();
}