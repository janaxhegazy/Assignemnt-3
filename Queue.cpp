//
//  Queue.cpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#include "Queue.hpp"
#include<iostream>
using namespace std;
template<class T>
Queue<T>::Queue()
{
    this->front = -1;
    this->rear = -1;
    this->count = 0;
    this->size = 10;
    this->arr = new T[size];
}
template<class T>
Queue<T>::Queue(int x)
{
    this->front = -1;
    this->rear = -1;
    this->count = 0;
    this->size = x;
    this->arr = new T[size];
}
template<class T>
Queue<T>::~Queue()
{
    delete[]this->arr;
}
template<class T>
bool Queue<T>::isEmpty() const
{
    if (this->getCount() == 0)
        return 1;
    else
        return 0;
}
template<class T>
bool Queue<T>::isFull() const
{
    if (this->getCount() == (this->getSize() - 1))
        return 1;
    else
        return 0;
}
template<class T>
T Queue<T>::pop()
{
    if (!this->isEmpty())
    {
        return this->arr[front++];
        this->front %= this->GetSize();
        this->count--;
    }
    else
        cout << "The queue is empty" << endl;
    return 0;
}
template<class T>
void Queue<T>::push(T temp)
{
    if (this->isEmpty())
    {
        this->front = 0;
        this->rear = 0;
        this->arr[0] = temp;
        this->count++;
    }
    if (!this->isFull())
    {
        this->arr[++rear%this->GetSize] = temp;
        this->rear %= this->GetSize();
        count++;
    }
    else
        cout << "The array full" << endl;
}
template<class T>
int Queue<T>::getCount() const
{
    return this->count;
}
template<class T>
int Queue<T>::getSize() const
{
    return this->size;
}
