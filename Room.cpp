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
void Room::setExit(char direction, Room* neighbor) {
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

// Define method to search for direction key in exits map
bool Room::searchDirection(char direction) {
  return (exits.find(direction) != exits.end());
}

// Define method to return destination room when moving in specified direction
Room* Room::getExitRoom(char direction) {
  return exits[direction];
}

// Define method to add item to room
void Room::setItem(Item* newItem) {
  items.push_back(newItem);
}


// Define method to return item given it's name
Item* Room::getItem(char* itemName) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(items[i]->getDescription(), itemName) == 0) {
      return items[i];
    }
  }
  return nullptr;
}


// Define method to remove item from room given it's name
void Room::removeItem(char* itemName) {
  // use erase-remove idiom to mark items for removal
  auto removeItem = remove_if(items.begin(), items.end(), [&itemName](Item* ptr) {
    return (strcmp(itemName, ptr->getDescription()) == 0);
  });

  // erase marked items
  items.erase(removeItem, items.end());
}


// Define destructor
Room::~Room() {
  // clear items vector
  for (Item* ptr : items) {
    if (ptr != nullptr) { // validate ptr
      delete ptr;
    }
  }
  
  // do NOT delete description because it's a string literal
}
