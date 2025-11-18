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

// define destructor
Room::~Room() {

}
