#include <iostream>
#include <process.h>

using namespace std;

struct Node
{
    int info;
    Node *next;
} *start = NULL, *newptr, *ptr, *temp;

Node *makenode(int n)
{
    ptr = new Node;
    ptr->info = n;
    ptr->next = NULL;
    return ptr;
}

void insertB(Node *np)
{
    if (start == NULL)
        start = np;
    else
    {
        temp = start;
        start = np;
        np->next = temp;
    }
}

void travfrom(Node *np)
{
    while (np != NULL)
    {
        cout << np->info << " -> ";
        np = np->next;
    }
}

void DelNode()
{
    ptr = start;
    start = start->next;
    delete ptr;
}

using namespace std;

int main()
{
    int inf;
    char ch;
    system("cls");
    while (ch != '!')
    {
        if (ch != 'D')
        {
            system("cls");
            cout << "Enter info for new node.\n";
            cin >> inf;

            newptr = makenode(inf);
            if (newptr == NULL)
            {
                cout << "Overflow.";
                system("pause");
                exit(1);
            }
            insertB(newptr);
            cout << "List: ";
            travfrom(start);
        }
        else
        {
            DelNode();
            ch = 'g';
            cout << "List: ";
            travfrom(start);
        }
        cout<<"Press D to delete beginning Node, ! to exit.\n";
        cin>>ch;
    }

    return 0;
}