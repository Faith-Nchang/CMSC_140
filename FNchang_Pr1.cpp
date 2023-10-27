/*
 * Class: CMSC140 40020
 * Instructor: Gary Thai
 * Project  1
 * Description: This program is intended to write a greeting script for a robot computer 
                in order for the robot to interact with a visitor human.
 * Due Date: 6/18/23
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Faith Nchang
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() 
{
  // variables that do no change all through the program
  const string ROBOTNAME = "Nao", //name of Robot
               PROGRAMMERNAME = "Faith Fru Nchang", //my name
               DUEDATE = "6/18/23"; //Assignment due date
               
  const int DAYSPERMONTH = 30, 
            GOLDFISHYEAR = 5,   // if the user inputs the age of a pet(goldfish or dog),
            DOGAGE = 7,         //these variables are used to convert the age to human age
            ASSIGNMENTNUMBER = 1,
            MONTHSPERYEAR = 12,
            HOURSPERDAY = 24,
            MINUTESPERHOUR = 60,
            SECONDSPERMINUTE = 60;

  //variables whose values change 
  string userName = " "; //name of the user
  int age; // stores person's or pet's age
  

  /*variables used in computation
  these variables are used to convert the age the user inputs in months,
  days, hours, minutes, and seconds */
  int monthsInAge, daysInAge, hoursInAge, minutesInAge, secondsInAge;

  //if it's a dog's age, converts it to human age
  int dogAgeInHuman;
  //if it's a gold fish's age, converts it to human age
  int goldFishAgeInHuman;

  //variables used in the 2nd game
  int number1, number2;



  cout << "**************** Robot Prototype Scripting ******************** \n\n";
  cout <<"Hello, welcome to Montgomery College! My name is " << ROBOTNAME << ". May I have your name? \n";
  // stores the userInput in the userName variable
  getline(cin, userName); 
  
  cout << "Nice to have you with us today, " << userName <<"!\n";
  cout << "Let me impress you with a small game. \n";
  cout << "Give me the age of an important person or a pet to you. \n";
  cout << "Please give me only a number: \n";
  cin >> age; // stores the userinput into the age variable
  cin.ignore(20, '\n');
   

  
  monthsInAge = age * MONTHSPERYEAR; // the age variable expressed in months
  daysInAge = monthsInAge * DAYSPERMONTH; // the age variable expressed in days
  hoursInAge = daysInAge * HOURSPERDAY; // the age variable expressed in hours
  minutesInAge = hoursInAge * MINUTESPERHOUR; // the age variable expressed in minutes
  secondsInAge = minutesInAge * MINUTESPERHOUR; // the age variable expressed in seconds
  
  cout << "\nYou have entered " << age << ".\n";
  cout << " If this is for a person, the age can be expressed as: \n";
  cout <<" " << age <<" years\n";
  cout << " or " << monthsInAge << " months. \n";
  cout << " or about " << daysInAge << " days. \n";
  cout << " or about " << hoursInAge << " hours. \n";
  cout << " or about " << minutesInAge << " minutes. \n";
  cout << " or about " << secondsInAge << " seconds. \n";

  dogAgeInHuman = age * DOGAGE; //converts the dog's age int human age
  cout <<" If this is for a dog, it is " << dogAgeInHuman <<" years old in human age. \n";

  goldFishAgeInHuman = age * GOLDFISHYEAR; // converts the gold fish age into human age
  cout <<" If this is for a gold fish, it is " << goldFishAgeInHuman <<" years old in human age. \n\n";


  cout << "Let's play another game, " << userName << ". Give me a whole number. \n";
  cin >> number1;
  cin.ignore(20, '\n'); //ignores extra spaces and truncated values
  
  cout << "Very well. Give me another whole number. \n";
  cin >> number2;
  cin.ignore(20, '\n');
  
  cout << "Using the operator '+' in C++, the result of " << number1 <<" + " << number2 << " is " << number1 + number2 << ".\n";
  cout << "Using the operator '/' in C++, the result of " << number1 <<" / " << number2 << " is " << number1 / number2 <<endl;
  
  cout << "however, the result of " << fixed << setprecision(1) << showpoint << double(number1) << " / " << static_cast<double>(number2) <<" is about "<< double(number1) / static_cast<double>(number2) <<".\n\n";
  cout << "Thank you for testing my program!! \n";
  cout << "PROGRAMMER: " << PROGRAMMERNAME << endl;
  cout << "CMSC140 Common Project " << ASSIGNMENTNUMBER << endl;
  cout << "Due Date: " << DUEDATE << endl;



  return 0;


}