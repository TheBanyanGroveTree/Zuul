/* Description: Zuul
   Author: Aahana Sapra
   Date: 11/18/2025
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

int main() {
  // declare vector of room pointers
  vector<Room*> rooms;
  
  // initialize room objects and add to vector
  const char* outsideDescription = "outside the main entrance of the campus";
  Room* outside = new Room(outsideDescription);
  rooms.push_back(outside);
  
  // initialize room exits
  
  // declare vector of items for inventory
  // initialize items

  // print game instructions

  // continue prompting user for input until QUIT command
  
  return 0;
}
