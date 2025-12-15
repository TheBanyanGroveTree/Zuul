/**
   Description: Zuul is a simple, text-based adventure game. This rendition
   takes place in a school and the players must navigate to the Upper Gym
   and have the Robot item in their inventory to win. Their commands are:
   GO, GET, DROP, INVENTORY, HELP, and QUIT (end game).
   Author: Aahana Sapra
   Date: 12/15/2025
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <ios>
#include <algorithm>
#include "Room.h"
#include "Item.h"

using namespace std;

// Function prototypes
void printGameInstructions(Room*& currentRoom);
bool goRoom(Room*& currentRoom, Room*& upperGym, vector<Item*>& inventory);
bool checkInventory(vector<Item*>& inventory);
void getItem(const int& INPUT_LENGTH, Room*& currentRoom,
	     vector<Item*>& inventory);
void dropItem(const int& INPUT_LENGTH, Room*& currentRoom,
	      vector<Item*>& inventory);
void printInventory(vector<Item*>& inventory);
void printHelp();

int main() {
  // declare vector of room pointers
  vector<Room*> rooms;
  
  // instantiate room objects and add to vector
  char outsideDesc[] = "outside the main entrance of the campus";
  Room* outside = new Room(outsideDesc);
  rooms.push_back(outside);

  char mainOfficeDesc[] = "in the main office getting your late slip";
  Room* mainOffice = new Room(mainOfficeDesc);
  rooms.push_back(mainOffice);

  char counselorOfficeDesc[] = "in the counselor's office to talk";
  Room* counselorOffice = new Room(counselorOfficeDesc);
  rooms.push_back(counselorOffice);
  
  char oneTwentyDesc[] = "in the coolest place in the world";
  Room* oneTwenty = new Room(oneTwentyDesc);
  rooms.push_back(oneTwenty);

  char courtyardDesc[] = "outside surrounded by benches";
  Room* courtyard = new Room(courtyardDesc);
  rooms.push_back(courtyard);

  char mainHallDesc[] = "in main hall";
  Room* mainHall = new Room(mainHallDesc);
  rooms.push_back(mainHall);

  char restroomDesc[] = "taking a ten minute break from class to use the \"restroom\"";
  Room* restroom = new Room(restroomDesc);
  rooms.push_back(restroom);

  char mathClassDesc[] = "in the boringest room in the entire school";
  Room* mathClass = new Room(mathClassDesc);
  rooms.push_back(mathClass);

  char oneHallDesc[] = "getting trampled by the masses in one hall";
  Room* oneHall = new Room(oneHallDesc);
  rooms.push_back(oneHall);

  char scienceClassDesc[] = "surrounded by hazardous substances. Be careful";
  Room* scienceClass = new Room(scienceClassDesc);
  rooms.push_back(scienceClass);

  char cafeteriaDesc[] = "eating a nutritious and delicious school lunch";
  Room* cafeteria = new Room(cafeteriaDesc);
  rooms.push_back(cafeteria);

  char libraryDesc[] = "in the quietest room";
  Room* library = new Room(libraryDesc);
  rooms.push_back(library);

  char upperGymDesc[] = "on the second floor";
  Room* upperGym = new Room(upperGymDesc);
  rooms.push_back(upperGym);

  char gymDesc[] = "in the middle of flying balls";
  Room* gym =  new Room(gymDesc);
  rooms.push_back(gym);

  char auditoriumDesc[] = "interrupting rehearsals for the school play";
  Room* auditorium = new Room(auditoriumDesc);
  rooms.push_back(auditorium);

  char aHallDesc[] = "where the English classes are";
  Room* aHall = new Room(aHallDesc);
  rooms.push_back(aHall);

  // set starting point
  Room* currentRoom = mainOffice;

  // initialize room exits
  char NORTH = 'N';
  char SOUTH = 'S';
  char WEST = 'W';
  char EAST = 'E';

  outside->setExit(NORTH, mainOffice);

  mainOffice->setExit(NORTH, mainHall);
  mainOffice->setExit(EAST, counselorOffice);
  mainOffice->setExit(SOUTH, outside);

  counselorOffice->setExit(NORTH, restroom);
  counselorOffice->setExit(WEST, mainOffice);

  oneTwenty->setExit(EAST, courtyard);

  courtyard->setExit(NORTH, mathClass);
  courtyard->setExit(EAST, mainHall);
  courtyard->setExit(WEST, oneTwenty);

  mainHall->setExit(NORTH, oneHall);
  mainHall->setExit(EAST, restroom);
  mainHall->setExit(SOUTH, mainOffice);
  mainHall->setExit(WEST, courtyard);

  restroom->setExit(SOUTH, counselorOffice);
  restroom->setExit(WEST, mainHall);

  mathClass->setExit(NORTH, scienceClass);
  mathClass->setExit(EAST, oneHall);
  mathClass->setExit(SOUTH, courtyard);

  oneHall->setExit(NORTH, cafeteria);
  oneHall->setExit(SOUTH, mainHall);
  oneHall->setExit(WEST, mathClass);

  scienceClass->setExit(EAST, cafeteria);
  scienceClass->setExit(SOUTH, mathClass);

  cafeteria->setExit(NORTH, gym);
  cafeteria->setExit(EAST, library);
  cafeteria->setExit(SOUTH, oneHall);
  cafeteria->setExit(WEST, scienceClass);

  library->setExit(NORTH, auditorium);
  library->setExit(WEST, cafeteria);

  upperGym->setExit(EAST, gym);

  gym->setExit(EAST, auditorium);
  gym->setExit(SOUTH, cafeteria);
  gym->setExit(WEST, upperGym);

  auditorium->setExit(EAST, aHall);
  auditorium->setExit(SOUTH, library);
  auditorium->setExit(WEST, gym);

  aHall->setExit(WEST, auditorium);
  
  // declare vector of items for inventory
  vector<Item*> inventory;

  // instantiate items and add to vector
  char slipDesc[] = "Slip\0";
  Item* slip = new Item(slipDesc);
  mainOffice->setItem(slip);

  char robotDesc[] = "Robot";
  Item* robot = new Item(robotDesc);
  oneTwenty->setItem(robot);

  char protractorDesc[] = "Protractor";
  Item* protractor = new Item(protractorDesc);
  mathClass->setItem(protractor);

  char acidDesc[] = "Acid";
  Item* acid = new Item(acidDesc);
  scienceClass->setItem(acid);

  char bananaDesc[] = "Banana";
  Item* banana = new Item(bananaDesc);
  cafeteria->setItem(banana);

  char bookDesc[] = "Book";
  Item* book = new Item(bookDesc);
  library->setItem(book);

  char speakersDesc[] = "Speakers";
  Item* speakers = new Item(speakersDesc);
  auditorium->setItem(speakers);

  char basketballDesc[] = "Basketball";
  Item* basketball = new Item(basketballDesc);
  gym->setItem(basketball);

  // print game instructions
  printGameInstructions(currentRoom);

  // declare char arr for user input
  const int INPUT_LENGTH = 81;
  char userCommand[INPUT_LENGTH];
  
  // continue prompting user for input until QUIT command
  bool playing = true;
  while (playing) {
    // read in user input
    cout << endl << "Enter a command: ";
    cin.getline(userCommand, INPUT_LENGTH);

    // convert input to uppercase for comparison
    for (int i = 0; i < strlen(userCommand); i++) {
      userCommand[i] = toupper(userCommand[i]);
    }

    // validate input and call appropriate methods
    if (strcmp(userCommand, "GO") == 0) {
      playing = goRoom(currentRoom, upperGym, inventory);
    } else if (strcmp(userCommand, "GET") == 0) {
      getItem(INPUT_LENGTH, currentRoom, inventory);
    } else if (strcmp(userCommand, "DROP") == 0) {
      dropItem(INPUT_LENGTH, currentRoom, inventory);
    } else if (strcmp(userCommand, "INVENTORY") == 0) {
      printInventory(inventory);
    } else if (strcmp(userCommand, "HELP") == 0) {
      printHelp();
    } else if (strcmp(userCommand, "QUIT") == 0) {
      // clear rooms vector
      for (Room* ptr : rooms) {
	if (ptr != nullptr) { // validate ptr
	  delete ptr;
	}
      }
      rooms.clear();

      // clear inventory vector
      for (Item* ptr : inventory) {
	if (ptr != nullptr) { // validate ptr
	  delete ptr;
	}
      }
      inventory.clear();
      
      playing = false;
    } else { // invalid input
      cout << "Please enter a valid command." << endl;
    }
  }
  
  return 0;
}


// Define method to print game instructions
void printGameInstructions(Room*& currentRoom) {
  // instructions
  cout << "Welcome to Zuul, where you must not be a fool to escape. ";
  cout << "You're currently trapped inside the abandoned Sunset High School campus, "
       << "where horrors like dangerous bananas and acids lurk the halls. ";
  cout << "In order to save your life, you must successfully retrieve the "
       << "robot and make your way to the upper gym. ";
  cout << "Good luck, and may the odds be ever in your favor." << endl << endl;
  
  // help
  cout << "Type HELP if you get lost." << endl << endl;

  // current room description
  currentRoom->printLongDescription();
}


/* Enter a new room if there is an exit in the given direction.
   Player wins the game if they are in the upper gym with the Robot item
   in their inventory.
 */
bool goRoom(Room*& currentRoom, Room*& upperGym, vector<Item*>& inventory) {
  // ask user for direction
  char userDirection;
  cout << "Enter a direction: ";
  cin >> userDirection;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // convert direction input to uppercase for comparison
  userDirection = toupper(userDirection);

  // check if exit exists
  bool exitExists = currentRoom->searchDirection(userDirection);

  // enter new room if possible
  if (exitExists) {
    // NOT allocated with new keyword
    Room* newRoom = currentRoom->getExitRoom(userDirection);
    currentRoom = newRoom;
    cout << endl;
    currentRoom->printLongDescription();
    
    // check for winning condition
    if ((currentRoom == upperGym) && (checkInventory(inventory))) {
      cout << endl << "Congratulations, you somehow managed to escape!" << endl;
      return false; // game over so no longer playing
    }
  } else {
    cout << "There is no exit in that direction." << endl;
  }
  
  return true; // still playing
}


// Pick up item from current room and add it to inventory
void getItem(const int& INPUT_LENGTH, Room*& currentRoom,
	     vector<Item*>& inventory) {
  // prompt user for item
  char userItem[INPUT_LENGTH];
  cout << "Enter an item: ";
  cin.getline(userItem, INPUT_LENGTH);

  // check if item exists
  Item* newItem = currentRoom->getItem(userItem);
  if (newItem == nullptr) {
    cout << "That item is not here." << endl;
  } else {
    inventory.push_back(newItem); // add to inventory
    currentRoom->removeItem(userItem); // remove from current room
    cout << "Picked up: " << newItem->getDescription() << endl;
  }
}


// Drop item in current room and remove it from the inventory
void dropItem(const int& INPUT_LENGTH, Room*& currentRoom,
	      vector<Item*>& inventory) {
  // prompt user for item
  char userItem[INPUT_LENGTH];
  cout << "Enter an item: ";
  cin.getline(userItem, INPUT_LENGTH);

  // use erase-remove idiom to mark item for removal
  auto itemToRemove = remove_if(inventory.begin(), inventory.end(),
				[&userItem, &currentRoom](Item* ptr) {
      // check if item in inventory
      if (strcmp(userItem, ptr->getDescription()) == 0) {
        // drop item in current room
        currentRoom->setItem(ptr);
        cout << "Dropped: " << userItem << endl;

        return true;  // mark item for removal
      }
      return false;
    });

  // erase item from inventory after marked for removal
  inventory.erase(itemToRemove, inventory.end());
}


// Check if robot item is in the player's inventory
bool checkInventory(vector<Item*>& inventory) {
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    if (strcmp("Robot", (*it)->getDescription()) == 0) {
      return true;
    }
  }
  return false;
}


// Define method to output items in inventory
void printInventory(vector<Item*>& inventory) {
  cout << "You are carrying:";
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    cout << " " << (*it)->getDescription();
  }
  cout << endl;
}


// Define method to print list of command words
void printHelp() {
  cout << "You are lost. You are alone. You wander around the campus." << endl;
  cout << "Your command words are: GO GET DROP INVENTORY HELP QUIT." << endl;
  cout << "Do not enter any characters after a command." << endl;
  cout << "You will be prompted for all of the required information." << endl;
}
