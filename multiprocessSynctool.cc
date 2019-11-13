#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
using namespace std;

vector<int> v;

struct Queue
{
    // Initialize front and rear
    int rear, front;
    
    // Circular Queue
    int size;
    int *arr;
    
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size-1) ||
        (rear == (front-1)%(size-1)))
    {
        printf("\nBuffer is Full");
        return;
    }
    
    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }
    
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
    
    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        printf("\nBuffer is Empty");
        return INT_MIN;
    }
    
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
    
    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in the Buffer are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
        
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

bool mutex_cn=1;
int full_semaphore=0,empty_semaphore=0;
//int x=0;
int ele=0;
int pro_x=0, con_x=0;
void producer(int buffer[],Queue &q);
void consumer(int buffer[],Queue &q);
int wait(int);
int signal(int);


int main(int argc, char ** argv)
{
    
    printf("\nEnter your buffer size:");
    scanf("%d",&empty_semaphore);
    int buffer[empty_semaphore];
    Queue q(empty_semaphore);

    printf("\n Buffer size is: %d", empty_semaphore);
    
    
    int n;

    while(1)
    {   printf("\n\n----------------------------------------------");
        printf("\n 1.Produce     2.Consume     3.Display        4.Exit \n Enter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:    if((mutex_cn==1)&&(empty_semaphore!=0))
                producer(buffer,q);
            else
                printf("Buffer is full!!");
                break;
            case 2:    if((mutex_cn==1)&&(full_semaphore!=0))
                consumer(buffer,q);
            else
                printf("Buffer is empty!!");
                break;
            case 3:
                q.displayQueue();
                break;
            case 4:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }
    
    return 0;
}

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return(++s);
}

void producer(int buffer[],Queue &q)
{
    mutex_cn=wait(mutex_cn);
    full_semaphore=signal(full_semaphore);
    empty_semaphore=wait(empty_semaphore);
    printf("\nEnter the element to produce:");
    scanf("%d",&ele);
    pro_x++;
    buffer[pro_x]=ele;
    q.enQueue(ele);
    q.displayQueue();

    printf("Producer produced the item %d",ele);
    //printf("\n\n----------------------------------------------");
    mutex_cn=signal(mutex_cn);
}

void consumer(int buffer[],Queue &q)
{
    mutex_cn=wait(mutex_cn);
    full_semaphore=wait(full_semaphore);
    empty_semaphore=signal(empty_semaphore);
    ele=buffer[con_x];
    printf("\nConsumer consumed item %d",q.deQueue());
    q.displayQueue();

    //printf("\n----------------------------------------------");
    con_x--;
    mutex_cn=signal(mutex_cn);
}

