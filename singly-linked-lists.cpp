//singly-linked-lists.cpp

#include <iostream>
#include <process.h>

using namespace std;

struct Node   //creating data structure
{
    int inf;
    Node *next; // Self Referencing
} * start, *newptr, *save, *ptr;

Node *createnode(int info)
{
    ptr = new Node;     // Allocating memory for new Node
    ptr->inf = info;    // Adding info to new Node
    ptr->next = NULL;   // Next points to NULL(Node not linked yet)
    return ptr;

}

//function to insert node in beginning of list
void insert_beg(Node *np)
{
    if(start == NULL)
        start = np; //if list is empty, first element is passed Node
    
    else
    {
        save = start; //saving start in save OR save points to start
        start = np; //start points to np
        np->next = save;  //next node is save, ie, the prev start node saved in save pointer is shifted right, and np is the first node
    }
}

//function to display Nodes, starting from start Node
void Traversefrom(Node *np)
{
    while(np != NULL) //until np isn't NULL(np doesn't point to anything, ie, end of list)
    {
        cout<<np->inf<<" -> ";
        np = np->next;  //np pointing to next node in each iteration
    }
}

//driver code
int main()
{
    start = NULL; //list empty at start
    int infor;
    char ch;
    
    while (ch != '!')
    {
        //Recieving data for Node
        system("cls");
        cout << "\nEnter Info for new Node";
        cin >> infor;

        //Creating Node

        newptr = createnode(infor);
        if (newptr == NULL)
        {
            cout << "Overflow. Press Enter to exit...\n";
            system("pause");
            exit(1);
        }
        cout << "\nNode created successfully";

        //Inserting in Beginning

        cout << "\nInserting Node in beginning...\n";
        insert_beg(newptr);

        //Displaying

        cout << "\nCurrent list is:\n";
        Traversefrom(start);

        //Asking for new nodes

        cout << "Enter ! to exit, anything else to keep entering..." << endl;
        
        cin>>ch;
    }
}
