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
  const char* outsideDesc = "outside the main entrance of the campus";
  Room* outside = new Room(outsideDesc);
  rooms.push_back(outside);

  const char* mainOfficeDesc = "in the main office getting your late slip";
  Room* mainOffice = new Room(mainOfficeDesc);
  rooms.push_back(mainOffice);

  const char* counselorOfficeDesc = "in the counselor's office to talk";
  Room* counselorOffice = new Room(counselorOfficeDesc);
  rooms.push_back(counselorOffice);
  
  const char* oneTwentyDesc = "in the coolest place in the world";
  Room* oneTwenty = new Room(oneTwentyDesc);
  rooms.push_back(oneTwenty);

  const char* courtyardDesc = "outside surrounded by benches";
  Room* courtyard = new Room(courtyardDesc);
  rooms.push_back(courtyard);

  const char* mainHallDesc = "in main hall";
  Room* mainHall = new Room(mainHallDesc);
  rooms.push_back(mainHall);

  const char* restroomDesc = "taking a ten minute break from class to use the \"restroom\"";
  Room* restroom = new Room(restroomDesc);
  rooms.push_back(restroom);

  const char* mathClassDesc = "in the boringest room in the entire school";
  Room* mathClass = new Room(mathClassDesc);
  rooms.push_back(mathClass);

  const char* oneHallDesc = "getting trampled by the masses in one hall";
  Room* oneHall = new Room(oneHallDesc);
  rooms.push_back(oneHall);

  const char* scienceClassDesc = "surrounded by hazardous substances. Be careful";
  Room* scienceClass = new Room(scienceClassDesc);
  rooms.push_back(scienceClass);

  const char* cafeteriaDesc = "eating a nutritious and delicious school lunch";
  Room* cafeteria = new Room(cafeteriaDesc);
  rooms.push_back(cafeteria);

  const char* libraryDesc = "in the quietest room";
  Room* library = new Room(libraryDesc);
  rooms.push_back(library);

  const char* upperGymDesc = "on the second floor";
  Room* upperGym = new Room(upperGymDesc);
  rooms.push_back(upperGym);

  const char* gymDesc = "in the middle of flying balls";
  Room* gym =  new Room(gymDesc);
  rooms.push_back(gym);

  const char* auditoriumDesc = "interrupting rehearsals for the school play";
  Room* auditorium = new Room(auditoriumDesc);
  rooms.push_back(auditorium);

  const char* aHallDesc = "where the English classes are";
  Room* aHall = new Room(aHallDesc);
  rooms.push_back(aHall);
  
  // initialize room exits
  
  // declare vector of items for inventory
  // instantiate items and add to vector

  // print game instructions

  // continue prompting user for input until QUIT command
  
  return 0;
}
