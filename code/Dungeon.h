#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "CreateEverything.h"
using namespace std;
class Monster;
class NPC;

class Dungeon{
private:
    Player player;
    vector<Room> rooms;
    int round;
    int activityRound;
    int roundToLast;
public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();
    void showMap();
    /* Deal with player's moving action */
    bool handleMovement();

    /* Deal with player's iteraction with objects in that room */
    bool handleEvent(Object*);
    bool activity();
    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    bool chooseAction();// true: Update Status/ false: don't update status
    void updateStatus(string biome);
    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();
};


#endif // DUNGEON_H_INCLUDED
