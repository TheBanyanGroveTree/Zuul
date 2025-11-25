/* Description: Zuul
   Author: Aahana Sapra
   Date: 11/24/2025
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
  
  // instantiate room objects and add to vector
  const char* OUTSIDE_DESC = "outside the main entrance of the campus";
  Room* outside = new Room(OUTSIDE_DESC);
  rooms.push_back(outside);

  const char* MAIN_OFFICE_DESC = "in the main office getting your late slip";
  Room* mainOffice = new Room(MAIN_OFFICE_DESC);
  rooms.push_back(mainOffice);

  const char* COUNSELOR_OFFICE_DESC = "in the counselor's office to talk";
  Room* counselorOffice = new Room(COUNSELOR_OFFICE_DESC);
  rooms.push_back(counselorOffice);
  
  const char* ONE_TWENTY_DESC = "in the coolest place in the world";
  Room* oneTwenty = new Room(ONE_TWENTY_DESC);
  rooms.push_back(oneTwenty);

  const char* COURTYARD_DESC = "outside surrounded by benches";
  Room* courtyard = new Room(COURTYARD_DESC);
  rooms.push_back(courtyard);

  const char* MAIN_HALL_DESC = "in main hall";
  Room* mainHall = new Room(MAIN_HALL_DESC);
  rooms.push_back(mainHall);

  const char* RESTROOM_DESC = "taking a ten minute break from class to use the \"restroom\"";
  Room* restroom = new Room(RESTROOM_DESC);
  rooms.push_back(restroom);

  const char* MATH_CLASS_DESC = "in the boringest room in the entire school";
  Room* mathClass = new Room(MATH_CLASS_DESC);
  rooms.push_back(mathClass);

  const char* ONE_HALL_DESC = "getting trampled by the masses in one hall";
  Room* oneHall = new Room(ONE_HALL_DESC);
  rooms.push_back(oneHall);

  const char* SCIENCE_CLASS_DESC = "surrounded by hazardous substances. Be careful";
  Room* scienceClass = new Room(SCIENCE_CLASS_DESC);
  rooms.push_back(scienceClass);

  const char* CAFETERIA_DESC = "eating a nutritious and delicious school lunch";
  Room* cafeteria = new Room(CAFETERIA_DESC);
  rooms.push_back(cafeteria);

  const char* LIBRARY_DESC = "in the quietest room";
  Room* library = new Room(LIBRARY_DESC);
  rooms.push_back(library);

  const char* UPPER_GYM_DESC = "on the second floor";
  Room* upperGym = new Room(UPPER_GYM_DESC);
  rooms.push_back(upperGym);

  const char* GYM_DESC = "in the middle of flying balls";
  Room* gym =  new Room(GYM_DESC);
  rooms.push_back(gym);

  const char* AUDITORIUM_DESC = "interrupting rehearsals for the school play";
  Room* auditorium = new Room(AUDITORIUM_DESC);
  rooms.push_back(auditorium);

  const char* A_HALL_DESC = "where the English classes are";
  Room* aHall = new Room(A_HALL_DESC);
  rooms.push_back(aHall);
  
  // initialize room exits
  const char* NORTH = "NORTH";
  const char* SOUTH = "SOUTH";
  const char* WEST = "WEST";
  const char* EAST = "EAST";

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
  // instantiate items and add to vector

  // print game instructions

  // continue prompting user for input until QUIT command
  
  return 0;
}
