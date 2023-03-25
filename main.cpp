//
//  main.cpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.


#include"Customer.hpp"
#include"Mechanics.hpp"
#include"Person.hpp"
#include"Queue.hpp"

const int MAXnum = 4;
const int CUSTnum = 5;
int main()
{
    

    Mechanic mechanics[MAXnum];
    mechanics[0].Mechanic::Mechanic("Mostafa", "15", 19);
    mechanics[1].Mechanic::Mechanic("Ahmed", "16", 20);
    mechanics[2].Mechanic::Mechanic("Mahmoud", "17", 18);
    /*for (int i = 0; i < Mnum; i++)
    {
        int num;
        string name, ID;
        cout << "Please enter the mechanics information such as name age id :  ";
        cin >> name >> num >> ID;
        workers[i].Mechanic::Mechanic(name,ID,num);
    }*/
    Customer customers[CUSTnum];
    for (int i = 0; i < CUSTnum; i++)
    {
        int num,h,m;
        string name, ID;
        cout << "Please enter the customer information such as name age id appointment time(hours min):  ";
        cin >> name >> num >> ID>>h>>m;
        Appointment temp(h, m);
        customers[i].Customer::Customer(name, ID, num,"",temp);
        int x=0;
        for (x = 0; x < MAXnum; x++)
        {
            if (mechanics[x].IsAvailable(temp))
                break;
        }
        if (x == MAXnum)
        {
            Appointment non(-1, -1);
            customers[i].SetApp(non);
        }
        else
        {
            for (int y = i % MAXnum; y > -3; y++)
            {
                if (mechanics[y].IsAvailable(temp))
                {
                    customers[i].setMID(mechanics[y].getID());
                    mechanics[y].setApp(temp);
                    break;
                }
            }
        }
    }
    Queue<Customer> line(CUSTnum);
    for (int x = 0; x < CUSTnum; x++)
    {
            for (int j = x + 1; j < CUSTnum; j++)
            {
                if (customers[j] < customers[x])
                {
                    Customer temp = customers[j];
                    customers[j] = customers[x];
                    customers[x] = temp;
                }
            }
            line.push(customers[x]);
    }

    for (int i = 0; i < CUSTnum; i++)
    {
        line.pop().PrintInfo();
    }
    return 0;
}

