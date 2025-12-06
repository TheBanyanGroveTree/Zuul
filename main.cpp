/* Description: Zuul
   Author: Aahana Sapra
   Date: 12/5/2025
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

// function prototypes
void printGameInstructions();
bool goRoom();
bool checkInventory();
void getItem();
void dropItem();
void printInventory();
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

  // initialize room exits
  char NORTH[] = "NORTH";
  char SOUTH[] = "SOUTH";
  char WEST[] = "WEST";
  char EAST[] = "EAST";

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
  char slipDesc[] = "Slip";
  Item* slip = new Item(slipDesc);
  inventory.push_back(slip);
  mainOffice->setItem(slip);

  char robotDesc[] = "Robot";
  Item* robot = new Item(robotDesc);
  inventory.push_back(robot);
  oneTwenty->setItem(robot);

  char protractorDesc[] = "Protractor";
  Item* protractor = new Item(protractorDesc);
  inventory.push_back(protractor);
  mathClass->setItem(protractor);

  char acidDesc[] = "Acid";
  Item* acid = new Item(acidDesc);
  inventory.push_back(acid);
  scienceClass->setItem(acid);

  char bananaDesc[] = "Banana";
  Item* banana = new Item(bananaDesc);
  inventory.push_back(banana);
  cafeteria->setItem(banana);

  char bookDesc[] = "Book";
  Item* book = new Item(bookDesc);
  inventory.push_back(book);
  library->setItem(book);

  char speakersDesc[] = "Speakers";
  Item* speakers = new Item(speakersDesc);
  inventory.push_back(speakers);
  auditorium->setItem(speakers);

  char basketballDesc[] = "Basketball";
  Item* basketball = new Item(basketballDesc);
  inventory.push_back(basketball);
  gym->setItem(basketball);

  // print game instructions
  printGameInstructions();

  // declare char arr for user input
  const int INPUT_LENGTH = 81;
  char userCommand[INPUT_LENGTH];
  
  // continue prompting user for input until QUIT command
  bool playing = true;
  while (playing) {
    // read in user input
    cout << "Enter a command: ";
    cin.getline(userCommand, INPUT_LENGTH);

    // convert input to uppercase for comparison
    for (int i = 0; i < strlen(userCommand); i++) {
      userCommand[i] = toupper(userCommand[i]);
    }

    // validate input
    if (strcmp(userCommand, "GO") == 0) {

    } else if (strcmp(userCommand, "GET") == 0) {

    } else if (strcmp(userCommand, "DROP") == 0) {

    } else if (strcmp(userCommand, "INVENTORY") == 0) {

    } else if (strcmp(userCommand, "HELP") == 0) {

    } else if (strcmp(userCommand, "QUIT") == 0) {
      // clear vectors
      for (Room* ptr : rooms) {
	delete ptr;
      }
      rooms.clear();

      for (Item* ptr : inventory) {
	delete ptr;
      }
      inventory.clear();
      
      playing = false;
    } else { // invalid input
      cout << "Please enter a valid command." << endl;
    }
  }
  
  return 0;
}

// define method to print game instructions
void printGameInstructions() {
  // instructions
  cout << "Welcome to Zuul, where you must not be a fool to escape.";
  cout << "You're currently trapped inside the abandoned Sunset High School, "
       << "where horrors like dangerous bananas and acids lurk the halls.";
  cout << "In order to save your life, you must successfully retrieve the "
       << "robot and make your way to the upper gym.";
  cout << "Good luck, and may the odds be ever in your favor." << endl;
  
  // help
  cout << "Type HELP if you get lost." << endl;

  // current room description
  //cout << "You are in " << currentRoom->getDescription() + "
  
}
