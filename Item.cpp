#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

// define constructor
Item::Item(char* description) {
  this->description = description;
}

// define method to get item description
char* Item::getDescription() {
  return description;
}

// define destructor
Item::~Item() {
  delete description;
}
