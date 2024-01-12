/*
  CMSC140 Project 4
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  /*************  Variable declarations***********************/
  const int PRICEPERSINGLEROOM = 60, 
            PRICEPERDOUBLEROOM = 80, 
            PRICEPERKINGROOM = 120, 
            PRICEPERSUITEROOM = 150,
            MINNUMBEROFFLOORS = 1, 
            MAXNUMBEROFFLOORS = 5, 
            MAXROOMSPERFLOOR = 30, 
            MINROOMSPERFLOOR = 1, 
            ASSIGNMENTNUMBER = 3;
          
  string hotelLocation; 
  int totalNumberOfFloors, 
      numberOfRoomsPerFloor, 
      numberOfOccupiedRooms = 0, 
      numberOfUnoccupiedRooms, 
      numberOfSingleRooms, 
      numberOfDoubleRoom, 
      numberOfKingRooms, 
      numberOfSuiteRooms, 
      totalNumberOfRooms = 0; 
  double totalHotelIncome, 
         occupancyRate = 0, 
         incomePerSingleRoom, 
         incomePerDoubleRoom, 
         incomePerKingRoom,
         incomePerSuiteRoom;
  int floorNumber; //initialization variable used in the for-loop to determine the current floor number
  /***********************************************************/

  cout <<"====================================================\n";
  cout << setw(35) << "BlueMont Hotel\n";
  cout <<"====================================================\n";

  cout << "Enter the location of this hotel chain: ";
  getline(cin, hotelLocation);

  cout << "Enter the total number of floors of the hotel: ";
  cin >> totalNumberOfFloors;
  cin.ignore(20, '\n'); //if the user inputs a floating point number
  //if the user inputs a number out of the range of 1 and 5
  while(totalNumberOfFloors < MINNUMBEROFFLOORS || totalNumberOfFloors > MAXNUMBEROFFLOORS)      
  {
    cout << "Number of floors should be between " << MINNUMBEROFFLOORS << " and " << MAXNUMBEROFFLOORS
         << ". Please try again.\n\n";
    cout << "Enter the total number of floors of the hotel: ";
    cin >> totalNumberOfFloors;
    cin.ignore(20, '\n'); //if the user inputs a floating point
  }
  
  int numberOfRoomsForFloorWithMinimumRooms = 30, //stores the # of rooms for the floor w/ min rooms
      floorWithMinimumRooms = 0,// used to determine the floor with the least number of rooms
      sumOfRoomsPerfloor = 0; // stores the sum of single,double, king, and suit rooms per floor
  /*used in the do-while loop to check if the do-while loop has iterated more than once in 
   order to print a message to tell the user the error they made*/
  int iterationNumber = 1; 

  // loops through each floor number and ask the user to input the number of rooms based on the category
  for(floorNumber = 1; floorNumber <= totalNumberOfFloors; floorNumber++)
  {
    do
    {
      if (iterationNumber > 1) 
        cout << "Total number of occupied rooms exceeds the total number of rooms in this floor. Please try again\n";
      
      iterationNumber++; //increments the # of times the do-while loop executes

      //gets the number of rooms on each floor
      cout << "\nEnter total number of rooms in floor "<< floorNumber<<": ";
      cin >> numberOfRoomsPerFloor;
      cin.ignore(20, '\n');
      //if the user inputs a number out of the range 1 and 30 for the number of rooms on each floor
      while(numberOfRoomsPerFloor < MINROOMSPERFLOOR || numberOfRoomsPerFloor > MAXROOMSPERFLOOR)
      {
        cout << "Number of rooms should be between " << MINROOMSPERFLOOR << " and " << MAXROOMSPERFLOOR
             << ". Please try again.\n\n";
        cout << "Enter total number of rooms in floor "<< floorNumber<<": ";
        cin >> numberOfRoomsPerFloor;
        cin.ignore(20, '\n');
      }
      cout << "How many SINGLE rooms are occupied in the "<<floorNumber<<"th floor: ";
      cin >> numberOfSingleRooms;
      cin.ignore(20, '\n');
      // when the user inputs a negative value
      if (numberOfSingleRooms < 0)
        numberOfSingleRooms = 0;

      cout << "How many DOUBLE rooms are occupied in the "<<floorNumber<<"th floor: ";
      cin >> numberOfDoubleRoom;
      cin.ignore(20, '\n');
      if (numberOfDoubleRoom < 0)  // when the user inputs a negative value
        numberOfDoubleRoom = 0;

      cout << "How many KING rooms are occupied in the "<<floorNumber<<"th floor: ";
      cin >> numberOfKingRooms;
      cin.ignore(20, '\n');
      if (numberOfKingRooms < 0) // when the user inputs a negative value
        numberOfKingRooms = 0;

      cout << "How many SUITE rooms are occupied in the "<<floorNumber<<"th floor: ";
      cin >> numberOfSuiteRooms;
      cin.ignore(20, '\n');
      if (numberOfSuiteRooms < 0)// when the user inputs a negative value
        numberOfSuiteRooms = 0;

      //all the rooms occupied in the hotel per night
      sumOfRoomsPerfloor = numberOfSingleRooms + numberOfDoubleRoom + numberOfKingRooms + numberOfSuiteRooms;

    } while (sumOfRoomsPerfloor > numberOfRoomsPerFloor);

    //checks for the floor w/ min # of rooms
    if (numberOfRoomsPerFloor <= numberOfRoomsForFloorWithMinimumRooms)
    {
      //floor with the least number of rooms
      floorWithMinimumRooms = floorNumber;
      //total number OF ROOMS in the floor which has the minimum number of rooms
      numberOfRoomsForFloorWithMinimumRooms = numberOfRoomsPerFloor;
    }
    // number of rooms in the entire hotel
    totalNumberOfRooms += numberOfRoomsPerFloor;
    //sum of all occupied rooms
    numberOfOccupiedRooms += sumOfRoomsPerfloor;

    incomePerSingleRoom = numberOfSingleRooms * PRICEPERSINGLEROOM; //income per night for a single room
    incomePerDoubleRoom = numberOfDoubleRoom * PRICEPERDOUBLEROOM; //income per night for a double room
    incomePerKingRoom = numberOfKingRooms * PRICEPERKINGROOM; //income per night for a king room
    incomePerSuiteRoom = numberOfSuiteRooms * PRICEPERSUITEROOM; //income per night for a suite room

    //run total of the total income the hotel gains per night on each floor
    totalHotelIncome += (incomePerSingleRoom + incomePerDoubleRoom + incomePerKingRoom + incomePerSuiteRoom);

    iterationNumber = 1; // for the next execution of the for loop
  }
  //computes the number of empty rooms in the hotel
  numberOfUnoccupiedRooms = totalNumberOfRooms - numberOfOccupiedRooms;
  occupancyRate = static_cast<double>(numberOfOccupiedRooms) / totalNumberOfRooms * 100;
  
  /*********************************************************************/
  cout << "============================================================================================\n";
  cout << setw(40) <<" BlueMont Hotel located in " << hotelLocation << endl << endl;
  cout << setw(50) << "TODAY'S ROOM'S RATES<US$/night> \n\n";
  cout << setw(20) << "Single Room" <<setw(20) << "Double Room" << setw(20) 
       << "King Room" << setw(20) << "Suite Room\n";
  cout << setw(20) << PRICEPERSINGLEROOM <<setw(20) << PRICEPERDOUBLEROOM << setw(20) 
       << PRICEPERKINGROOM << setw(20) << PRICEPERSUITEROOM <<endl;
  cout <<"============================================================================================\n"; 
  /*********************************************************************/
  cout << setprecision(2) << fixed << showpoint;
  cout << setw(35) << "Hotel income: " << setw(5) <<"$"<< totalHotelIncome << endl;                                                                                                                                                                                                                  ;
  cout << setw(35) <<"Total number of rooms: "<< setw(10) << totalNumberOfRooms << endl;
  cout << setw(35) <<"Total # of occupied Rooms: "<< setw(10) << numberOfOccupiedRooms << endl;
  cout << setw(35) <<"Total # of unoccupied Rooms: "<< setw(10) << numberOfUnoccupiedRooms << endl;
  cout << setw(35) <<"Occupancy rate: "<< setw(9) << occupancyRate <<"%"<<endl<<endl;
  
  cout << floorWithMinimumRooms <<"th Floor with "<<numberOfRoomsForFloorWithMinimumRooms
       <<" rooms, has the least number of rooms.";
  if(occupancyRate < 60)
    cout << "\nNeed to improve Hotel occupancy rate!!";
 
  cout << "\n\nThank you for testing my program.\n";
  cout << "Programmer: Faith Nchang\n";
 
  return 0;

}
