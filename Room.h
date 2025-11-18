#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room {
 public:
  Room(char*);
  char* getDescription();
  void setExit(char*, Room);
  char* getExitString();
  Room getExitRoom(char*);
  void setItem(Item);
  Item getItem(char*);
  void getRoomItemsDescription();
  void removeItem(char*)
  ~Room();
 private:
  char* description;
  map<int, char*> exits;
  vector<Item> items;
};
