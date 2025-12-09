#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room {
 public:
  Room(char*);
  char* getShortDescription();
  void setExit(char*, Room*);
  void printLongDescription();
  Room* getExitRoom(char*);
  void setItem(Item*);
  Item* getItem(char*);
  void removeItem(char*);
  ~Room();
 private:
  char* description;
  map<char*, Room*> exits;
  vector<Item*> items;
};

#endif
