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
  Room(const char*);
  const char* getDescription();
  void setExit(char*, Room*);
  char* getExitDescriptions();
  Room* getExitRoom(char*);
  void setItem(Item*);
  Item* getItem(char*);
  void getRoomItemDescriptions();
  void removeItem(char*);
  ~Room();
 private:
  const char* description;
  map<char*, Room*> exits;
  vector<Item*> items;
};

#endif
