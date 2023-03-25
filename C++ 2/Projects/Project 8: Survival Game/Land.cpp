#include "land.h"


Land* getLand(LandTypes selection){


   switch(selection){
       case FOREST:
           return new Forest;
           break;
       case LAKE:
           return new Lake;
           break;
       case JUNGLE:
           return new Jungle;
           break;
       case SWAMP:
           return new Swamp;
           break;
       case MOUNTAINS:
           return new Mountains;
           break;
       case TUNDRA:
           return new Tundra;
           break;
       case OCEAN:
           return new Ocean;
           break;
       case TOWN:
           return new Town;
           break;
       case DESERT:
           return new Desert;
           break;
       default:
           return nullptr;
           break;
   }
}


string Forest::getDescription(){
   return "a densely wooded forest.";
}


string Lake::getDescription(){
   return "a sparkling clear lake.";
}


string Jungle::getDescription() {
   return "a hot and humid jungle.";
}


string Swamp::getDescription() {
   return "Shrek's swamp.";
}


string Mountains::getDescription() {
   return "The mountain range where BigFoot has freuqently been spotted.";
}


string Tundra::getDescription() {
   return "a cold and unforgiving tundra.";
}


string Ocean::getDescription() {
   return "a lovely island on the ocean.";
}


string Town::getDescription() {
   return "just an average town.";
}


string Desert::getDescription() {
   return "a hot and sandy desert.";
}


string Forest::visit(Player& player){
   player.setHunger(player.getHunger() + 1);
   return "You venture into the forest and forage for nuts and berries, restoring your hunger";
}


string Lake::visit(Player& player){
   player.setThirst(player.getThirst() + 1);
   return "You drink from the lake, re-hydrating yourself.";
}


string Jungle::visit(Player& player) {
   string description = "You look for exotic fruits and medicinal plants and find nothing.";


   int chance = rand() % 101;


   // Chance of dangerous wildlife poison dart frog
   if (chance > 95) {
       description = "You accidentally ate a poison dart frog!";
       player.setHealth(player.getHealth() - 5);
       return description;
   }
   // Chance of dangerous wildlife piranha
   if (chance < 95 && chance > 85) {
       description = "You fell into the river and got mauled by piranhas!";
       player.setHealth(player.getHealth() - 8);
       return description;
   }
   // Chance of dangerous wildlife mosquito
   if (chance < 85 && chance > 78) {
       description = "You got bit by mosquitos and got malaria!";
       player.setHealth(player.getHealth() - 3);
       return description;
   }
   // Chance of poisonous plants
   if (chance < 78 && chance > 70) {
       description = "You ate a delicious looking plant but it was poisonous!";
       player.setHealth(player.getHealth() - 2);
       return description;
   }
   // Chance of potable water
   if (chance < 70 && chance > 40) {
       description = "You stopped at the river to drink the water";
       player.setThirst(player.getThirst() + 3);
       return description;
   }
   // Chance of medicinal plants
   if (chance < 40 && chance > 35) {
       description = "You ate a medicinal jungle plant and restored your energy";
       player.setHealth(player.getHealth() + 3);
       return description;
   }
   // Chance of edible foods
   if (chance < 35 && chance > 20) {
       description = "You found bananas and jungle bugs to eat";
       player.setHunger(player.getHunger() + 4);
       return description;
   }
   else {
       return description;
   }
}


string Swamp::visit(Player& player) {
   string description = "You look around the swamp find nothing.";


   int chance = rand() % 100;


   // Chance of toxic sludge water
   if (chance < 80 && chance > 60) {
       description = "You stopped at the swamp to drink but the water was sludge!";
       player.setThirst(player.getThirst() - 3);
       return description;
   }
   // Chance of quicksand
   if (chance < 60 && chance > 45) {
       description = "You found yourself sinking in quicksand!";
       player.setHealth(player.getHealth() - 2);
       return description;
   }
   else {
       return description;
   }
}


string Mountains::visit(Player& player) {
   string description = "You hike around and see the sights but you just get tired.";


   int chance = rand() % 100;


   // Chance of falling off a cliff
   if (chance > 90) {
       description = "You fell off a cliff and broke both legs!";
       player.setHealth(player.getHealth() - 5);
       return description;
   }
   // Chance of BigFoot
   if (chance < 90 && chance > 85) {
       description = "You met BigFoot and got mauled!";
       player.setHealth(player.getHealth() - 3);
       return description;
   }
   // Chance of Mountain Hermit
   if (chance < 85 && chance > 50) {
       description = "You met a mountain hermit and he gave you food and shelter!";
       player.setHealth(player.getHealth() + 3);
       player.setThirst(player.getThirst() + 2);
       player.setHunger(player.getHunger() + 3);
       return description;
   }
   // Chance of clean mountain springs
   if (chance < 50 && chance > 30) {
       description = "You drank from a fresh mountain stream";
       player.setThirst(player.getThirst() + 2);
       return description;
   }
   else {
       return description;
   }
}


string Tundra::visit(Player& player) {
   string description = "You walk around but the land is barren.";


   int chance = rand() % 100;


   // Chance of frostbite
   if (chance > 40) {
       description = "A rogue truck hits you!";
       player.setHealth(player.getHealth() - 5);
       return description;
   }
   // Chance of Snowstorm
   if (chance > 20 && chance < 40) {
       description = "You fell off a cliff and broke both legs!";
       player.setHealth(player.getHealth() - 5);
       return description;
   }
   else {
       return description;
   }
}


string Ocean::visit(Player& player) {
   string description = "You get a bad sunburn";


   int chance = rand() % 100;


   // Chance of drinking water
   if (chance > 90) {
       description = "You drink the salty water but become more thirsty.";
       player.setThirst(player.getThirst() - 3);
       return description;
   }
   // Chance of mermaid spotting
   if (chance < 90 && chance > 80) {
       description = "You spot a beautiful mermaid!";
       player.setHealth(player.getHealth() + 3);
       player.setThirst(player.getThirst() + 2);
       player.setHunger(player.getHunger() + 3);
       return description;
   }
   // Chance of catching fish
   if (chance < 80 && chance > 55) {
       description = "You go finshing and have an abundant catch!";
       player.setHunger(player.getHunger() + 3);
       return description;
   }
   // Chance of finding coconuts
   if (chance < 40 && chance > 25) {
       description = "You find some coconuts and eat/drink the coconut meat/juices!";
       player.setThirst(player.getThirst() + 2);
       player.setHunger(player.getHunger() + 2);
       return description;
   }
   else {
       player.setHealth(player.getHealth() - 2);
       return description;
   }
}


string Town::visit(Player& player) {
   string description = "You wander from door to door but no one will let you in.";


   int chance = rand() % 100;


   // Chance of being mugged
  if (chance < 80 && chance > 70) {
       description = "You get mugged by local hoodlums";
       player.setHealth(player.getHealth() -2);
       return description;
   }
   // Chance of being offered food
  if (chance < 70 && chance > 50) {
       description = "You stumble upon a local farmers market and have money to spare";
       player.setHunger(player.getHunger() + 3);
       return description;
   }
   // Chance of being offered water
   if (chance < 50 && chance > 40) {
       description = "Kids are giving away bottled water for their local fundraiser";
       player.setThirst(player.getThirst() + 3);
       return description;
   }
   // Chance of shelter
   if (chance < 40 && chance > 25) {
       description = "The townspeople take you in, you stay the night and wake up to a hearty breakfast!";
       player.setHealth(player.getHealth() + 4);
       player.setThirst(player.getThirst() + 3);
       player.setHunger(player.getHunger() + 3);
       return description;
   }
   return description;
}


string Desert::visit(Player& player) {
   string description = "The sun is unbearable and you become more thirsty.";


   int chance = rand() % 100;


   // Chance of Sandstorm
   if (chance > 90) {
       description = "You get caught in a sandstorm!";
       player.setHealth(player.getHealth() - 1);
       return description;
   }
   // Chance of Oasis
   if (chance < 90 && chance > 75) {
       description = "You stumble upon an oasis and drink your fill.";
       player.setHealth(player.getHealth() + 1);
       player.setThirst(player.getThirst() + 2);
       return description;
   }
   player.setThirst(player.getThirst() - 4);
   return description;
}
