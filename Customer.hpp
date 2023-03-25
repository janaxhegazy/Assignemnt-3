//
//  Customer.hpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#ifndef Customer_hpp
#define Customer_hpp
#include<iostream>
#include<string>
#include"Person.hpp"
using namespace std;

class Customer : public person
{
private:
    int MechanicID;
    Appointment app;
public:
    Customer();//default constructor for a customer
    Customer(string, Appointment);//initial value constructor when only the name and appointments time is known
    Customer(string, int, int, string, Appointment);//initial value constructor to a customer with known name,age,id,MID, and appointment
    virtual void PrintInfo() const;//the virtual function that must be implemented prints the info of the customer including their appointment time
    void setMID(string);//sets a mechanical with a unique ID to handle the customer
    void setApp(Appointment);//sets the appointment of the customer(can be used as an indicator that no mechanic was available to this customer)
    string getMID() const;//returns the id of the mechanic assigned to this cutomer
    Appointment getApp() const;//returns the appointment time of this customer
    bool operator<(const Customer&) const;//overloads the < operator to compare between the appointment times of 2 customers
    bool operator>(const Customer&) const;//overloads the > operator to compare between the appointment times of 2 customers
    bool operator==(const Customer&) const;//overloads the == operator to compare between the appointment times of 2 customers

};
#endif /* Customer_hpp */



