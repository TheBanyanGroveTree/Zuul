#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

// Define constructor
Item::Item(char* description) {
  this->description = description;
}

// Define method to get item description
char* Item::getDescription() {
  return description;
}

// Define destructor
Item::~Item() {
  // do NOT delete description because it's a string literal
}
