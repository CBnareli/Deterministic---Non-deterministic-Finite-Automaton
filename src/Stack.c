/* IMPLEMENTATION LINKED STACK WITH POINTERS*/

#include <stdio.h>
#include <stdlib.h>
#include "ListEdge.h"

void CreateStack(StackPointer *Stack)
/* Function: Creates an empty linked stack.
    Returns: An empty linked stack.
*/
{
	*Stack = NULL;
}


void Push(StackPointer *Stack, ListEdgePointer Item)
/*
Function: Inserts Item at the top of the stack.*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}


void Pop(StackPointer *Stack, ListEdgePointer *Item)
/*
Function: Removes from the top of the stack,
             if the stack is not empty, the Item.
*/
{
    StackPointer TempPtr;

    if (Stack==NULL) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
