
/* CircularQueue_h */

#ifndef CircularQueue_h
#define CircularQueue_h

#include <iostream>
#include <vector>
using namespace std;

struct CircularQueue
{
    int first, last;
    int size;
    vector<int> elems;

    
    CircularQueue();
    CircularQueue(int s);
    
    bool enQueue(int value);
    int deQueue();
    void displayQueue();
};

#endif /* CircularQueue_h */
