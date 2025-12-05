#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item {
 public:
  Item(const char*);
  const char* getDescription();
  ~Item();
 private:
  const char* description;
};

#endif
