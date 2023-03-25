//
//  workshop.cpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#include "Header.h"
#include <iostream>
using namespace std;

//For class Person
Person::Person()
{
    name = " ";
    id_ = 0;
    age=0;
}
//setters
void Person::setName(string n)
{
    name = n;
}
void Person::setID(int x)
{
    id_=x;
}
void Person::setAge(int a)
{
    age = a;
}
//getters
string Person::getName()const
{
    return name;
}
int Person::getID()const
{
    return id_;
}
int Person::getAge()const
{
    return age;
}
//print func

void Person::printInfo()
{
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id_<<endl;
    cout<<"Age: "<<age<<endl;
    
}

//For class Customer
//setters
void Customer::setMecID(int x)
{
    mechanicID=x;
}
void Customer::setApp(Appointment y)
{
    appoint = y;
}

//getters
int Customer::getMecID()const
{
    return mechanicID;
}
Customer::Appointment Customer::getApp()const
{
    return appoint;
}

//Overloaded operators
bool Customer::operator >(Customer x)
{
    Appointment temp1 = this->getApp();
    Appointment temp2 = x.getApp();
    
    if(temp1.hours > temp2.hours)
        return true;
    else if(temp1.hours < temp2.hours)
        return false;
    else
    {
        if(temp1.mins>temp2.mins)
            return true;
        else
            return false;
    }
}
bool Customer::operator <(Customer x)
{
    Appointment temp1 = this->getApp();
    Appointment temp2 = x.getApp();
    
    if(temp1.hours < temp2.hours)
        return true;
    else if(temp1.hours > temp2.hours)
        return false;
    else
    {
        if(temp1.mins<temp2.mins)
            return true;
        else
            return false;
    }
}
bool Customer::operator ==(Customer x)
{
    Appointment temp1 = this->getApp();
    Appointment temp2 = x.getApp();
    
    if(temp1.hours == temp2.hours)
    {
        if(temp1.mins == temp2.mins)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

//For mechanic class
bool Mechanic::isAvailable()
{
    Appointment *ptr = this->getArr();
    for(int i = 0; i<this->getCount(); i++)
    {
        if((ptr+i)->hours == 0)
        {
            if((ptr+i)->mins == 0)
                return true;
        }
        else
            return false;
    }
    return false;
}
//setters
void Mechanic::setArr(Appointment x)
{
    arr[++counter] = x;
}
void 
//getters
int Mechanic::getCount()const
{
    return counter;
}
Customer::Appointment* Mechanic::getArr()const
{
    return arr;
}




