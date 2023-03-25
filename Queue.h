//
//  Queue.h
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    int rear;
    int front;
     int count;
    T *values;
    int maxSize;
    
public:
    
    Queue(int x)
    {
        maxSize = x;
        rear=-1;
        front = -1;
        values= new T [maxSize];
        count=0;
    }
    ~Queue()
    {
        delete []values;
    }

    bool isEmpty()
    {
        if(front == -1 && rear==-1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(front== 0 && rear == maxSize -1)
            return true;
        else
            return false;
    }

    void push(T x)
    {
        if(isFull())
        {
            
            cout<<"Queue is full"<<endl;
        }
        else
        {
            
            rear = (rear+1)%maxSize;
            values[rear] = x;
            count++;
            if(front == -1)
            front = 0;
        }

    }

    T pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        return -1;
        }
        else
        {
            front = (front + 1)%maxSize;
            front ++;
            count --;
            if(count == 0)
            {
                front = -1;
                rear= -1;
            }
            return values[front];
        }
    }
    
    void printQueue()
    {
        cout << "front -->";
        for (int i = 0; i < count; i++) {
            if (i == 0)
                cout << "\t";
            else
                cout << "\t\t";
            cout << values[(front + i) % maxSize];
            if (i != count - 1)
                cout << endl;
            else
                cout << "\t<-- rear" << endl;
        }
    }
};
#endif /* Queue_h */
