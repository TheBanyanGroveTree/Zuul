#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

// Define constructor
Room::Room(char* description) {
  this->description = description;
}

// Define method to get room description
char* Room::getShortDescription() {
  return description;
}

// Define method to add exit from this room
void Room::setExit(char* direction, Room* neighbor) {
  exits[direction] = neighbor;
}

/* Define method to print a description of where you are right now,
   direction of exits, and items in current room
 */
void Room::printLongDescription() {
  // room description
  cout << "You are " << getShortDescription() << "." << endl;

  // exits
  cout << "Exits:";
  for (auto it = exits.begin(); it != exits.end(); ++it) {
    cout << " " << it->first;
  }
  cout << endl;

  // items
  cout << "Items in the room:";
  for (auto it = items.begin(); it != items.end(); ++it) {
    cout << " " << (*it)->getDescription();
  }
  cout << endl;
}

// Define method to return destination room when moving in specified direction
Room* Room::getExitRoom(char* direction) {
  return exits[direction];
}

// Define method to add item to room
void Room::setItem(Item* newItem) {
  items.push_back(newItem);
}

// define method to return item given it's name
Item* Room::getItem(char* itemName) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getDescription(), itemName)) {
      return items[i];
    }
  }
  return nullptr;
}

// define method to remove item from room given it's name
void Room::removeItem(char* itemName) {

}

// define destructor
Room::~Room() {
  delete description;
}
