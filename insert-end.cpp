#include <iostream>
#include <process.h>

using namespace std;

struct Node
{
    int inf;
    Node *next; // Self Referencing
} * start, *newptr, *save, *ptr, *rear;

Node *createnode(int info)
{
    ptr = new Node;     // Allocating memory for new Node
    ptr->inf = info;    // Adding info to new Node
    ptr->next = NULL;   // Next points to NULL(Node not linked yet)
    return ptr;

}

void insert_beg(Node *np)
{
    if(start == NULL)
        start = np;
    
    else
    {
        save = start;
        start = np;
        np->next = save;
    }
}

void insert_rear(Node *np)
{
    if(start == NULL)
        start = rear = np;
    
    else
    {
        save = rear;
        rear = np;
        save->next = rear;
    }
}

void Traversefrom(Node *np)
{
    while(np != NULL)
    {
        cout<<np->inf<<" -> ";
        np = np->next;
    }
}

int main()
{
    start = rear = NULL;
    int infor;
    char ch,begend;
    
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

        cout << "\nInserting Node in beg(b) or end(e)...\n";
        cin>>begend;
        if(begend == 'b')
            insert_beg(newptr);
        else if(begend == 'e')
            insert_rear(newptr);
        
        //Displaying

        cout << "\nCurrent list is:\n";
        Traversefrom(start);

        //Asking for new nodes

        cout << "Enter ! to exit, anything else to keep entering..." << endl;
        
        cin>>ch;
    }
}