//
//  Queue.hpp
//  assignment 3
//
//  Created by jana hegazy on 25/03/2023.
//

#ifndef Queue_hpp
#define Queue_hpp

template<class T>
class Queue//circular queue
{
private:
    int front;//the index of the front element in the queue
    int rear;//the index of the rear element in the queue
    int count;//the number of elements  in the queue
    T* arr;//the array of the queue
    int size;//the size of the queue(will be used to decide the max size of the queue

public:
    Queue() ;//default constructor that sets the size of the queue to 10
    Queue(int);//initial value constructor that sets the size of the queue to the integer input
    ~Queue();//destructor for the queue
    bool isEmpty() const;//function that checks if the queue is empty
    bool isFull() const;//functiont that checks if a queue is full
    void push(T);//function that pushes an element to the queue
    T pop();//functions that returns the front of the queue and sets the front to front +1
    int getCount() const;//returns the current number of elements in the queue
    int getSize() const;//returns the size of the queue
};

#endif /* Queue_hpp */
