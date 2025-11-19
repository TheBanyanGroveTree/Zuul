#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

// define constructor
Room::Room(char* description) {
  this->description = description;
}

// define method to get room description
char* Room::getDescription() {
  return description;
}

// define method to add exit from this room
void Room::setExit(char* direction, Room* neighbor) {
  exits[direction] = neighbor;
}

// define method to return description of room exits
char* Room::getExitDescriptions() {

}

// define method to return destination room when moving in specified direction
Room* Room::getExitRoom(char* direction) {
  return exits[direction];
}

// define method to add item to room
void Room::setItem(Item* newItem) {
  items.push_back(newItem);
}

// define method to return item given it's name
Item* Room::getItem(char* itemName) {

}

// define method to get a description of the items in a room
void Room::getRoomItemDescriptions() {

}

// define method to remove item from room given it's name
void Room::removeItem(char* itemName) {

}

// define destructor
Room::~Room() {
  delete description;
}
