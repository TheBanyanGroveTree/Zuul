#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(char*);
  char* getDescription();
  ~Item();
 private:
  char* description;
};

#endif
