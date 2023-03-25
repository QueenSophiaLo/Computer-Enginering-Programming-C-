#ifndef LAND_H
#define LAND_H


#include <string>
#include "player.h"


using namespace std;


enum LandTypes {FOREST, LAKE, JUNGLE, SWAMP, MOUNTAINS, TUNDRA, OCEAN, TOWN, DESERT, NUM_LANDS};


class Land {
   public:
   virtual string getDescription(){
       return "Description of land";
   }


   virtual string visit(Player& player){
       return "You visit a land";
   }
};


class Forest : public Land{
   public:
   string getDescription();
   string visit(Player& player);
};


class Lake : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Jungle : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Swamp : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Mountains : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Tundra : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Ocean : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Town : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


class Desert : public Land {
   public:
   string getDescription();
   string visit(Player& player);
};


Land* getLand(LandTypes selection);


#endif
