//
//  Mechanics.cpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//


#include <iostream>
using namespace std;
#include "Person.hpp"
#include "Customer.hpp"
#include "Mechanics.hpp"

Mechanic::Mechanic(string n, int i, int a) : person(n,i,a)
{
    
    this->setCount(0);
    this->apps = new Appointment[24];//the maximum number of appointments a mechanic can have is 24
}
Mechanic::Mechanic() : person()
{
    this->setCount(0);
    this->apps = new Appointment[24];
    
}
Appointment Mechanic::getApp(int x) const
{
    return this->apps[x];
}
int Mechanic::getCounter() const
{
    return this->counter;
}
bool Mechanic::IsAvailable(Appointment test) const
{
    if (this->getCounter() == 24)
        return 0;
    for (int i = 0; i < this->getCounter(); i++)
    {
        if ((test.hours == this->getApp(i).hours) && (test.mins == this->getApp(i).mins))
            return 0;
    }
    return 1;
}
void Mechanic::setApp(Appointment temp)
{
    if (counter == 0)
    {
        this->counter = 1;
        apps[0] = temp;
    }
    else
        if (counter != 24)
            this->apps[counter++];
        else
            cout << "The mechanic is fully booked" << endl;

}
void Mechanic::setCount(int x)
{
    counter = x;
}
void Mechanic::printInfo() const
{
    cout << "Mechanic Name is " << this->getName() << endl;
    cout << "Mechanic Age is " << this->getAge() << endl;
    cout << "Mechanic ID is " << this->getID() << endl;
    for (int i = 0; i < this->getCounter(); i++)
    {
        cout<<"The Mechanic has an appointment at "<< this->getApp(i).hours << ":" << this->getApp(i).mins << endl;
    }


}

