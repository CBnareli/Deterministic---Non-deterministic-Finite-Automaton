/*Author:
*Chrysa Bounareli
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ListEdge.h"
#include"Queue.h"

void CopyFile(FILE *infile, graph *G, int transition);
void Removee(graph G, char x, ListPointer* komvos, int num);
int menu(void);

int main(void){

    CreateLE(&G);

    //reading file
    FILE *infile;
    char *namefile;
    namefile = (char *)malloc(233 * sizeof(char)); //233, max name for a file

    printf("Enter a filename: ");
    scanf("%s",namefile);

    infile=fopen(namefile,"r");
    if(infile==NULL)
    {
        printf("Cannot open file");
        return 0;
    }


    /*manufacture automato*/
    int num,i,start,sum[2],j;
    boolean b;
    b=FALSE;
    fscanf(infile,"%d %d %d %d %d",&num, &start,&sum[0], &j, &sum[1]);
    for(i=1; i<=num; i++) /*making vertice*/
    {
        if (i!=start && b==FALSE)
        {
            InsertVertice(0,&G,i);
        }
        if (i==start)
        {
            b=TRUE;
        }
        if (b==TRUE && i!=num)
        {
            InsertVertice(0,&G,i+1);
        }
        if (i==num)
        {
           InsertVertice(0,&G, start);
        }
    }

    //2.3o step
    int z=10;
    for(i=0; i<sum[0]; i++)
    {
        Traverse(j%z,G,1); //i separate the names of the final states and put them in these nodes 1
        j=j/z;


    }

    //2.4o step
    ListPointer CurPtr;
    CurPtr=G;
    int q;
    //i reset the sumab$ for each head
    while(CurPtr!=NULL)
    {
        for (q=0; q<3; q++)
        {
            CurPtr->sumab$[q]=0;
        }
      CurPtr=CurPtr->next;
    }

    CopyFile(&*infile,&G,sum[1]);

    do{
    //4.1 step
    CurPtr=G;
    QueueType Queue;
    CreateQ(&Queue);
    i=1;
    boolean flag;//auxiliary
    flag=TRUE;
    char c;

    printf("MENU:\n");
    printf("ENTER: \n1.'a' or 'b' and create the word would you prefer \n2. ':' for exit\n");
    printf("----------------------------------\n");

    while(TRUE)
    {
       if (CurPtr->sumab$[2]!=0) //chooses whether to move by e-transition, if exist
       {
           Removee(G,$,&CurPtr,rand()%(CurPtr->sumab$[2]+1));
       }

       printf("Enter the %d character from the word: ", i);
       scanf("%s",&c);
       fflush(stdin);
       while(c!='a' && c!='b' && c!=':')
       {
           printf("The word is not acceptable with this char.\n");
           printf("Enter another char or enter ':' . ");
           scanf("%s",&c);
           fflush(stdin);
       }
       i++;
       if(c==':') break; // for exit

       if(c=='a')
       {
           if(CurPtr->sumab$[0]==1)
            Removee(G,c,&CurPtr,0);
           else if (CurPtr->sumab$[0]==0)
           {
               printf("The word is NOT acceptable");
               flag=FALSE;
               break;
           }
           else
            Removee(G,c,&CurPtr,rand()%CurPtr->sumab$[0]); //randomly selects which edge to follow if the movements are more than 1
       }
       else if (c=='b')
       {
           if(CurPtr->sumab$[1]==1)
            Removee(G,c,&CurPtr,0);
           else if (CurPtr->sumab$[1]==0)
           {
               printf("The word is NOT acceptable"); //if pressed letter for which there is no corresponding edge, the program hangs
               flag=FALSE;                           // so the word is unacceptable
               break;
           }
           else
            Removee(G,c,&CurPtr,rand()%CurPtr->sumab$[1]);
       }
       //if this node is associated with others with the blank word
       if (CurPtr->sumab$[2]!=0) //chooses whether to move by e-transition
       {
           Removee(G,$,&CurPtr,rand()%(CurPtr->sumab$[2]+1));
       }

    }

    //5o step
    if(flag)
    {
        if (CurPtr->ffinal==1)
            printf("The word is acceptable");
        else
            printf("The word is NOT acceptable");
    }
    }while(menu()!=2);


    return 0;
}

void CopyFile(FILE *infile, graph *G, int transition)
/*adding edges (transitions), and creating stacks to keep transitions made with the same letter*/
{
    int buffer[2];
    char numoftransition;
    int i;

    for(i=0; i<transition; i++)
    {
        ListPointer CurrPtr=*G;
        fscanf(infile,"%d %c %d", &buffer[0], &numoftransition, &buffer[1]);
        while(TRUE)
        {
            if(CurrPtr->name==buffer[0])
            {
                InsertEdge(CurrPtr,buffer[1],&*G,numoftransition);
                if(numoftransition=='a')
                {
                    CurrPtr->sumab$[0]++;
                    Push(&CurrPtr->sa,CurrPtr->edge);
                }
                else if (numoftransition=='b')
                {
                    CurrPtr->sumab$[1]++;
                    Push(&CurrPtr->sb,CurrPtr->edge);
                }
                else
                {
                    CurrPtr->sumab$[2]++;
                    Push(&CurrPtr->s$,CurrPtr->edge);
                }
                break;
            }
            CurrPtr = CurrPtr->next;
        }

    }

}

void Removee(graph G, char x, ListPointer* komvos, int num)
{
    ListEdgePointer tempedge;
    ListPointer temp;
    StackPointer tempStack;
    CreateStack(&tempStack);
    temp=*komvos;
    tempedge=temp->edge; //for the case of a blank word that gives rand () 0
    boolean flag;//auxiliary
    flag=FALSE;

    int i;

    if(x=='a')
    {
        for(i=0; i<num+1; i++) //num + 1 since rand passes values from 0 to (% movement) -1,
        {                      // while we want to operate on values from 1 to movements
            Pop(&temp->sa, &tempedge);
            Push(&tempStack, tempedge);
            flag=TRUE;
        }
    }
    else if (x=='b')
    {
        for(i=0; i<num+1; i++)
        {
            Pop(&temp->sb, &tempedge);
            Push(&tempStack, tempedge);
            flag=TRUE;
        }
    }
    else
    {
        for(i=0; i<num; i++) //we want to operate on values from 0 to movements
        {
            Pop(&temp->s$, &tempedge);
            Push(&tempStack, tempedge);
            flag=TRUE;
        }
    }

    if(flag)//change value only when it actually moves
    {
        *komvos=tempedge->vertice;
    }

     //to keep the stack unaffected
     if(x=='a')
    {
        for(i=0; i<num+1; i++)
        {
            Pop(&tempStack, &tempedge);
            Push(&temp->sa, tempedge);
        }
    }
    else if(x=='b')
    {
        for(i=0; i<num+1; i++)
        {
            Pop(&tempStack, &tempedge);
            Push(&temp->sb, tempedge);
        }
    }
    else
    {
        for(i=0; i<num; i++)
        {
            Pop(&tempStack, &tempedge);
            Push(&temp->s$, tempedge);
        }
    }
}

int menu(void)
{
    int choice;
    printf("\n\n-for INSERT PRESS 1\n");
    printf("-for EXIT PRESS 2\n");
    do
    {
        scanf("%d",&choice);
    }while(choice!=1 && choice!=2);

    if(choice==2)
        printf("\nAnyway, Have a nice day\n\n");

    return choice;

}


