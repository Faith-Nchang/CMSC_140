
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    const double KILOMETERSPERMILE = 1.6, //used to convert the distance to km
                 DOLLARSPERPOUND = 1.27,  //used to convert the money from dollars to pounds
                 POUNDSPERKILLOGRAM = 2.205; //used to convert weight from Ibs to kg
    string countryName; 
    int userChoice; // stores the option the user picks from the menu
    
            

    cout <<"\nWelcome to this program. \n";


    cout <<"Before we start, where are you travelling to? \n";
    getline(cin, countryName); //stores the userInput in the countryName variable

    cout << countryName <<"! Sounds fun!\n\n";

    cout << "Converter App\n";
    cout << "__________________\n";
    cout << "1. Temperature Converter (Fahrenheit(F) to Celsius(C)) \n";
    cout << "2. Distance Converter (Miles to Kilometers) \n";
    cout << "3. Weight Converter (Pounds to Kilograms) \n";
    cout << "4. Currency Converter (U.S.A Dollars to Pounds)\n";
    cout << "5. Quit\n\n";

    cout << "Pick an option from the menu: ";
    cin >> userChoice;
    cin.ignore(20, '\n'); //if the user inputs a decimal rather than an int, this ignores the floating point
    
    //specifies the range of of menu option
    if(userChoice >=1 && userChoice <= 5)
    {
        switch (userChoice)
        {
            //converts temperature from fahrenheit to celsius
            case 1:
                
                int temperatureInFahrenheit,  //variables used to store the temperature the user inputs
                    temperatureInCelsius; // used to store the temperature 
                
                cout << "Input the temperature in fahrenheit: ";
                cin >> temperatureInFahrenheit;
                if(temperatureInFahrenheit > -459.67 && !(cin.fail()))
                {
                    temperatureInCelsius = (temperatureInFahrenheit - 32) * 5 / 9;
                    cout << "The temperature in degree Celsius is " << temperatureInCelsius <<" degrees C\n";
                }
                else if(cin.fail()) //if the user inputs a letter or other character
                    cout << "Error. Please input an integer value for the temperature\n";
                
                else //if the user inputs a value below -459.67
                    cout << "Error. Temperature in fahrenheit cannot be less than -459.67F\n";
                
                break;
                
                //converts distance from Miles to Kilometers
            case 2:
                double distanceInMiles, //used to store the user's input(distance) in miles
                        distanceInkilometers; //used to store the  distance converted to km
                
                cout << "Input the distance in Miles (must be greater than or equal to 0): ";
                cin >> distanceInMiles;
                //ensures the user inputs a number >= 0 and not other characters
                if (distanceInMiles >= 0 && !(cin.fail()))
                {
                    distanceInkilometers = distanceInMiles * KILOMETERSPERMILE;
                    cout << setprecision(1) << fixed << showpoint<<"The distance in kilometers is " << distanceInkilometers << " km\n";
                }
                else if(cin.fail())
                    cout << "Error. Please input a number value for the distance\n";
                
                else 
                    cout << "Error. Distance cannot be less than 0\n";
            
                break;
                
                //converts weight from pounds to kilograms
            case 3:
                double weightInPounds, // variables used to store the weight the user inputs
                        weightInKilograms; // variable used to store the weight converted to kg
                
                cout << "Input the weight in pounds (must be greater than or equal to 0): ";
                cin >> weightInPounds;
                //ensures the weight is not less than 0
                if (weightInPounds >= 0 && !(cin.fail()))
                {
                    weightInKilograms = weightInPounds / POUNDSPERKILLOGRAM;
                    cout <<setprecision(2) << fixed << showpoint<<"The weight in kilograms is " << weightInKilograms <<" kg\n";
                }
                else if(cin.fail())
                    cout << "Error. Please input a number value for the Weight\n";
                else
                    cout << "Error. Weight can not be less than 0\n";
                
                break;

            //converts the amount of money(in dollars) the user inputs to another currency(pounds)
            case 4:
                double  moneyInDollars, 
                        moneyInPounds;
                
                cout << "Input the amount of money in U.S Dollars (must be greater than or equal to 0): ";
                cin >> moneyInDollars;
    
                //ensures the money is not less than 0
                if(moneyInDollars >= 0 && !(cin.fail()))
                {
                    moneyInPounds = moneyInDollars / DOLLARSPERPOUND;
                    cout <<setprecision(2) << fixed << showpoint << "The amount of money $"<<moneyInDollars<<" in pounds is £" << moneyInPounds <<endl;
                }
                else if(cin.fail())
                    cout << "Error. Please input a number value for the money\n";
                else 
                    cout << "Error. Money can not have a negative value.\n";
                
                break;
    
            //exits the program
            case 5:
                cout << "Quit....\n";
                break;
        
        }
        //displays this message after the switch statement is executed
        cout << "Enjoy your time in " << countryName <<"!\n\n";
        
    }
     //if the user enters a menu option out of range
    else
        cout << "Please pick an option from the range 1-5\n\n";
    

    cout << "Programmer: Faith Nchang\n";
    cout << "CMSC140 Project 2\n";
    cout << "Due Date: 6/25/23";

    return 0;
}
