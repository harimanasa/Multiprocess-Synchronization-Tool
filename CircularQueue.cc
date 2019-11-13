#include <iostream>
#include <vector>
#include <stdlib.h>
#include "CircularQueue.h"

using namespace std;


const int DEFAULT_BAD = INT_MIN;
CircularQueue::CircularQueue() //Default Constructor
    {
        size = 0;
        elems.resize(10); //Default size if nothing specified
        first = last = -1;
    }
    
CircularQueue::CircularQueue(int s) //Parameterized Constructor
    {
        size = s;
        elems.resize(size);
        first = last = -1;
    }


/* Produce elements in Circular Queue */
bool CircularQueue::enQueue(int value)
{
    bool result=false;
    
    if ((first < 0)&&(last < 0)) /* Insert First Element */
    {
        first++;
        last++;
        if(elems[last]!=value)
        {
            elems[last] = value;
        }
        result=true;
        
    }
    
    else if (((first == 0) && (last == size-1)) || (last == ((first-1)%(size-1))))
    {
        cerr<<"\n Buffer is Full"<<endl;
        return result;
    }

    else
    {   if (last == size-1 && first != 0)
        {
            last=0; //last set back to one after full cycle
        }
    else{
        last++;
        }
        if(elems[last]!=value)
        {
            elems[last] = value;
        }
        result=true;
    }
    return result;
}

// Consume elements from Circular Queue
int CircularQueue::deQueue()
{
    if (first < 0)
    {
        cerr<<"\n Buffer is Empty"<<endl;
        return DEFAULT_BAD;
    }
    
    int deleted = elems[first];
    
    elems[first] = -1; //Reset it back to -1
    
    if (first == last)
    {
        last = first = -1;
    }
    else if (first == size-1)
    {
        first = 0;
    }
    else
    {
        first++;
    }
    
    return deleted;
}

// Display elements filled in the Queue.
void CircularQueue::displayQueue()
{
    if (first < 0)
    {
        cerr<<"\n Queue is Empty !!! ";
        return;
    }
    cout<<"\n Elements in the Buffer are: ";
    
    if (first <= last)
    {
        for (int i = first; i <= last; i++)
            cout<<elems[i]<<" ";
    }
    else
    {
        for (int i = first; i < size; i++)
            cout<<elems[i]<<" ";

        for (int i = 0; i <= last; i++)
            cout<<elems[i]<<" ";
    }
    cout<<endl;
}
