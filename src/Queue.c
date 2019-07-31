                        /*IMPLEMENTATION LINKED QUEUE WITH POINTERS*/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void CreateQ(QueueType *Queue)
/* Function: Creates an empty queue linked.
    Returns: An empty queue connected
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Pet: A linked queue.
    Function: Checks whether the linked queue is empty.
    Returns: True if the queue is empty, false otherwise
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Accepts: An linked queue and an item.
    Function: Adds Item to the end of the Queue.
    Returns: The modified queue
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Accepts: A linked queue and an item.
    Function: Removes the Item from the top of the linked queue,
                 if not empty.
    Returns: Item and the modified linked queue.
    Output: Empty queue message if the queue is empty
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}



