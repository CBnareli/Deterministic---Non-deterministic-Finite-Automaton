// Filename ListEdge.h

typedef enum{
    a,b,$ //$ special symbol, indicates the empty word
}alphabet;

typedef struct korifi *ListPointer;
typedef struct akmi *ListEdgePointer;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	ListEdgePointer Data;
    StackPointer Next;
} StackNode;

struct korifi{
    StackPointer s$; //stack filled with the states associated with the respective node with the blank word
    StackPointer sa; //stack nodes that you can go by entering a
    StackPointer sb; //stack nodes that you can go by entering b
    int sumab$[3]; //how many transfers are available for each alphabet
    int ffinal;
    int name; //name of node
    ListPointer next; // next node of linked list of vertice
    ListEdgePointer edge; //pointer of list of edge
};

struct akmi{
    char ab; //by inserting which character "came" to this edge
    ListPointer vertice; //to whom head node terminates the edge
    ListEdgePointer next; //Next edge list node
};

typedef ListPointer graph;
graph G;


void CreateLE(graph *G);
void InsertVertice(int item, graph *G, int name);
void InsertEdge(ListPointer p, int q, graph *G, char abc);
void Traverse(int index, graph G, int item);

//for stack

void CreateStack(StackPointer *Stack);
void Push(StackPointer *Stack, ListEdgePointer Item);
void Pop(StackPointer *Stack, ListEdgePointer *Item);
