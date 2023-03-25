//
//  Customer.cpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#include<iostream>
#include<string>
using namespace std;
#include "Customer.hpp"
Customer::Customer()
{
    this->person:: person();
    this->MechanicID = "";
    this->app.hours = -1;
    this->app.mins = -1;
}
Customer::Customer(string str, Appointment moment)
{
    Customer(str, 0, 0, "", moment);

}
Customer::Customer(string nam,int id, int ag, string mid, Appointment temp): person(nam,id,ag)
{
    
    this->MechanicID = mid;
    this->app = temp;
}
void Customer::PrintInfo() const
{
    cout << "Customer Name is " << this->getName() << endl;
    cout << "Customer Age is " << this->getAge() << endl;
    cout << "Customer ID is " << this->getID() << endl;
    if (this->getApp().hours == -1)
        cout << "No Mechanic was Available at the time chosen " << endl<<endl;
    else
    {
        cout << "Customer has an Appointment at " << this->getApp().hours << ":" << this->getApp().mins <<endl;
        cout << "The Mechanic Assigned to this customer has ID " << this->getMID() << endl<<endl;
    }
}
void Customer::setMID(int id)
{
    this->MechanicID = id;
}
void Customer::setApp(Appointment test)
{
    this->app = test;
}
string Customer::getMID() const
{
    return this->MechanicID;
}
Appointment Customer::getApp() const
{
    return this->app;
}
bool Customer::operator<(const Customer &compare) const
{
    if (this->getApp().hours < compare.getApp().hours)
    {
        return true;
    }
    else if (this->getApp().hours > compare.getApp().hours)
    {
        return false;
    }
    else if (this->getApp().mins >= compare.getApp().mins)
    {
        return false;
    }
    else if (this->getApp().mins < compare.getApp().mins)
    {
        return true;
    }
}
bool Customer::operator>(const Customer &compare) const
{
    if ((*this < compare) || ((this->getApp().hours == compare.getApp().hours) && (this->getApp().mins == compare.getApp().mins)))
        return false;
    else
        return true;
}
bool Customer::operator==(const Customer &compare) const
{
    if ((this->getApp().hours == compare.getApp().hours) && (this->getApp().mins == compare.getApp().mins))
        return true;
    else
        return false;
}
