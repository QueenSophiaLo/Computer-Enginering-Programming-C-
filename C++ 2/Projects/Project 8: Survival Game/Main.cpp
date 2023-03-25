#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "player.h"
#include "land.h"


using namespace std;


const int WORLD_SIZE = 6;


Land* world[WORLD_SIZE][WORLD_SIZE];


void buildWorld(){
   Land* lands[NUM_LANDS];
   for(int i = 0; i < NUM_LANDS; i++)
     lands[i] = getLand((LandTypes)(i % NUM_LANDS));
   for(int i = 0; i < WORLD_SIZE; i++){
       for(int j = 0; j < WORLD_SIZE; j++){
           world[i][j] = lands[rand() % NUM_LANDS];
       }
   }
}




int main(){
   srand(time(0));


   buildWorld();


   string east, west, north, south;


   Player player(WORLD_SIZE / 2, WORLD_SIZE / 2);


   cout << "You wake up in an unknown place." << endl;


   while(player.isAlive()){
       player.nextTurn();
       cout << player.toString() << endl;


       if (player.getXPosition() == 0)
           east = world[WORLD_SIZE - 1][player.getYPosition()]->getDescription();
       else
           east = world[player.getXPosition() - 1][player.getYPosition()]->getDescription();


       if (player.getXPosition() == WORLD_SIZE - 1)
           west = world[0][player.getYPosition()]->getDescription();
       else
           west = world[player.getXPosition() + 1][player.getYPosition()]->getDescription();


       if (player.getYPosition() == 0)
           north = world[player.getXPosition()][WORLD_SIZE - 1]->getDescription();
       else
           north = world[player.getXPosition()][player.getYPosition() - 1]->getDescription();


       if (player.getYPosition() == WORLD_SIZE - 1)
           south = world[player.getXPosition()][0]->getDescription();
       else
           south = world[player.getXPosition()][player.getYPosition() + 1]->getDescription();


       cout << "To the north you see " << north << endl;
       cout << "To the east you see " << east << endl;
       cout << "To the west you see " << west << endl;
       cout << "To the south you see " << south << endl;


       cout << "Which direction do you want to move?" << endl;
       cout << "1: North, 2: East, 3: West, 4: South" << endl;
       /* make this a while loop to check for valid input */
       bool stayin = false;
       int n = 0;
       while (stayin || n == 0){
           //char userInput[256];
           string userInput;
           stringstream ss;
           int userIntput;
           cin >> userInput;
           ss << userInput;
           ss >> userIntput;


           //userIntput = stoi(userInput);


           switch(userIntput){
               case 1: // North
                   if (player.getYPosition() == 0) {
                       cout << "You move North, but something feels strange." << endl;
                       player.setPosition(player.getXPosition(), WORLD_SIZE - 1);
                   } else {
                       cout << "You move North." << endl;
                       player.setPosition(player.getXPosition(), player.getYPosition() - 1);
                   }
                   stayin = false;
               break;
               case 2: // East
                   if (player.getXPosition() == 0) {
                       cout << "You move East, but something feels strange." << endl;
                       player.setPosition(WORLD_SIZE - 1, player.getYPosition());
                   } else {
                       cout << "You move East." << endl;
                       player.setPosition(player.getXPosition() - 1, player.getYPosition());
                   }
                   stayin = false;
               break;
               case 3: // West
                   if (player.getXPosition() == WORLD_SIZE - 1) {
                       cout << "You move West, but something feels strange." << endl;
                       player.setPosition(0, player.getYPosition());
                   } else {
                       cout << "You move West." << endl;
                       player.setPosition(player.getXPosition() + 1, player.getYPosition());
                   }
                   stayin = false;
               break;
               case 4: // South
                   if (player.getYPosition() == WORLD_SIZE - 1) {
                       cout << "You move South, but something feels strange." << endl;
                       player.setPosition(player.getXPosition(), 0);
                   } else {
                       cout << "You move South." << endl;
                       player.setPosition(player.getXPosition(), player.getYPosition() + 1);
                   }
                   stayin = false;
               break;
               default: // Error
                   cout << "What? You can't go that way!" << endl;
                   stayin = true;
               break;
           }
           n++;
       }




       cout << "Player position x: " << player.getXPosition() << " y: " << player.getYPosition() << endl;
       cout << world[player.getXPosition()][player.getYPosition()]->visit(player) << endl;
       cout << endl << endl;
   }


   cout << "You died" << endl;
   cout << "Score: " << player.getScore() << endl;


   return 0;
}
