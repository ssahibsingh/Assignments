#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        prev = next = NULL;
    }
};

node *head = NULL;
node *temp;

void insert_node()
{
    int value;
    cout << "Enter Element ('00' for no value): ";
    cin >> value;

    if (value != 00)
    {
        node *newnode = new node(value);

        if (head == NULL)
        {
            head = newnode;

            newnode->prev = NULL;
            newnode->next = NULL;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
            temp = newnode;
        }
        insert_node();
    }
    else
    {
        return;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "\nLinked List is Empty!!" << endl;
        return;
    }
    temp = head;
    cout << endl;
    while (temp->next != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << " " << temp->data;
    cout << endl;
}

void delete_beg()
{
    cout << "\nDeletion From Beginning " << endl;

    temp = head;
    head = temp->next;
    temp->next->prev = NULL;
    free(temp);
}

main()
{
    cout << "\nOperations: \n"
         << endl;
    cout << " 1.Display" << endl
         << " 2.Deletion From Beginning " << endl
         << " 3.Insert " << endl
         << " 4.Exit" << endl;

    int ch;
    cout << "\nEnter Your Choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        display();
        main();
    }
    break;

    case 2:
    {
        delete_beg();
        main();
    }
    case 3:
    {
        insert_node();
        main();
    }
    case 4:
    {
        break;
    }
    default:
    {
        cout << "Invalid Input" << endl;
        main();
    }
    break;
    }
}