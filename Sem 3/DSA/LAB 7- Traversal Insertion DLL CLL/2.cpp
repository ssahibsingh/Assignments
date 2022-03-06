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

void create_node()
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
            temp = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
            head->prev = temp;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
            temp = newnode;
        }
        temp->next = head;
        head->prev = temp;
        create_node();
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
    while (temp->next != head)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << " " << temp->data;
}

void delete_beg()
{
    cout << "\nDeletion Successfully" << endl;
    temp = head;
    head = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->next = head;
    free(temp);
}

void delete_position()
{
    int pos;
    int k = 1;
    cout << "Enter the Position: ";
    cin >> pos;
    temp = head;
    if (pos == 1)
    {
        delete_beg();
        return;
    }
    else {
    while (k < pos)
    {
        temp = temp->next;
        k++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    cout << "Element Deleted Successfully!" << endl;
    }
}


void delete_end()
{
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->prev->next = head;
    head->prev = temp->prev;
    free(temp);
    cout << "Deletion From End Successfully" << endl;
}

void insert_beg()
{
    temp = head;
    int data;
    cout << "Enter the Value to be Inserted: ";
    cin >> data;
    node *newnode = new node(data);
    head = newnode;
    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    temp->prev = newnode;
    newnode->next = temp;
    cout << "Insertion at Beginning Successfully" << endl;
}

void insert_position()
{
    temp = head;
    int pos;
    int value;
    int k = 1;
    cout << "Enter the Position: ";
    cin >> pos;
    cout << "Enter Data :";
    cin >> value;

    while (k < pos - 1)
    {
        temp = temp->next;
        k++;
    }
    node *newnode = new node(value);

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;

    cout << "Insertion Successfull!" << endl;
}

void insert_end()
{
    temp = head;
    int data;
    cout << "Enter the Value to be Inserted : ";
    cin >> data;
    node *newnode = new node(data);
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    head->prev = newnode;

    cout << "Insertion Successfull!" << endl;
}

main()
{
    cout << "\nSelect an Operation:\n"<< endl;
    cout << "1. Create a Linked List" << endl
         << "2. Display Linked List" << endl
         << "3. Delete from Beginning" << endl
         << "4. Delete from specific Position" << endl
         << "5. Delete from End" << endl
         << "6. Insert at Beginning" << endl
         << "7. Insert at End" << endl
         << "8. Insert at specific Position" << endl;

    int ch;
    cout << "\nEnter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        create_node();
        main();
    }
    break;
    case 2:
    {
        display();
        main();
    }
    case 3:
    {
        delete_beg();
        main();
    }
    case 4:
    {
        delete_position();
        main();
    }
    case 5:
    {
        delete_end();
        main();
    }
    case 6:
    {
        insert_beg();
        main();
    }

    case 7:
    {
        insert_end();
        main();
    }
    case 8:
    {
        insert_position();
        main();
    }
    default:
    {
        cout << "INVALID !!!" << endl;
        main();
    }
    break;
    }
}