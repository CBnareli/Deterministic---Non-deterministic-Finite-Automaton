#include <stdio.h>
#include <stdlib.h>
#include "ListEdge.h"
#include "Queue.h"


void CreateLE(graph *G)
/* Function: Creates a blank linked edge list.
    Returns: Zero pointer G
*/
{
	*G = NULL;
}

void InsertVertice(int item, graph *G, int name)
/* Accepts: An Item data item and the "name" of the node, a linked list of edges with G to
               points to the first node.
* Function: Inserts a node, containing the Item, at the beginning of the linked edge list
*/
{
    ListPointer TempPtr;
    TempPtr=(ListPointer)malloc(sizeof(struct korifi));
    TempPtr->ffinal=item;
    TempPtr->name=name;

    TempPtr->next=*G; //Connects the new node to the top of the list of vertices of G *
    TempPtr->edge=NULL; // The TempPtr edge list is empty
    *G=TempPtr; //The node shown by TempPtr is the new header of the list of vertices of G *
}

void InsertEdge(ListPointer p, int q, graph *G, char abc)
/* Accepts: The queue p and q head directed graph G and the letter to which "gets" this road / edge
                the graph
    Function: Inserts a node, containing abc, into the list of edges of head q and connects it to head / tail p
*/
{
    ListEdgePointer PredPtr;
    ListPointer CurrPtr=*G; //search head of current edge
    PredPtr=(ListEdgePointer)malloc(sizeof(struct akmi));

    while(TRUE)
    {
        if(CurrPtr->name==q)
        {
           PredPtr->vertice=CurrPtr; //connect to the q head the corresponding field
           break;
        }
        CurrPtr = CurrPtr->next;
    }
    PredPtr->ab=abc;

    /*Link to the beginning of the edge list*/
    PredPtr->next=p->edge;
    p->edge=PredPtr;
}

void Traverse(int index, graph G, int item)
/*Function: Crosses the linked list of vertices and updates it*/
{
    ListPointer CurrPtr;
    if (G==NULL)
        printf("EMPTY GRAPH\n");
    else
    {
        CurrPtr = G;
        while(TRUE)
        {
          if(CurrPtr->name==index)
          {
              CurrPtr->ffinal=item;
              break;
          }
          CurrPtr = CurrPtr->next;
        }


    }
}
