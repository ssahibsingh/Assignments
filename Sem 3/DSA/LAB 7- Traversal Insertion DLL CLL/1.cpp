#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        prev = next = NULL;
    }
};

Node *head = NULL;
Node *temp;

void create_node()
{
    int value;
    cout << "Enter Element ('00' for no value): ";
    cin >> value;

    if (value != 00)
    {
        Node *newnode = new Node(value);

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
        create_node();
    }
    return;
}

void display()
{
    if (head == NULL)
    {
        cout << "\nLinked List is Empty!!" << endl;
        return;
    }
    temp = head;
    while (temp->next != NULL)
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
    temp->next->prev = NULL;
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
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    cout << "Deletion From End Successfully" << endl;
}

void insert_beg()
{
    temp = head;
    int data;
    cout << "Enter the Value to be Inserted: ";
    cin >> data;
    Node *newnode = new Node(data);
    head = newnode;
    temp->prev = newnode;
    newnode->prev = NULL;
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
    Node *newnode = new Node(value);

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
    Node *newnode = new Node(data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;

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
    case 2:
    {
        display();
        main();
    }
    break;

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
        cout << "Invalid Choice!" << endl;
        main();
    }
    break;
    }
}