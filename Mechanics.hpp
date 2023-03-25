//
//  Mechanics.hpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#ifndef Mechanics_hpp
#define Mechanics_hpp
#include <iostream>
#include"Person.hpp"

using namespace std;

class Mechanic : public person
{
private:
    int counter;//the number of appointments this mechanic have
    Appointment* apps;//an array of appointments this mechanic have
public:
    Mechanic();//default constructor for the mechanic
    Mechanic(string, int, int);//intial value constructor with the information of the mechanic directly assigned
    void printInfo() const;//the pure virtual function prints the information of the mechanic including his appointments
    bool IsAvailable(Appointment) const;//checks if a mechanic is available at a certain time
    int getCounter() const;//returns the number of appointments the mechanic have
    Appointment getApp(int) const;//returns the appoiintment a mechanic have at a certain index in the array
    void setCount(int);//sets the number of appointments a mechanic have(not sure what iam gonna use it for but its just here at the time)
    void setApp(Appointment);//sets an appointments for a mechanic as long as he is free at that time and didnt reach his maximum of 24 appointments per day
};

#endif /* Mechanics_hpp */
