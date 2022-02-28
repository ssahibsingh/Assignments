#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *temp;
struct Node *newnode;

int main()
{
    int i = 0;
    int size;

    cout << "Enter Size of Linked List: ";
    cin >> size;

    cout << "Enter Elements of Linked List: ";

    while (i < size)
    {
        newnode = new struct Node;
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            temp = newnode;
            head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }

    //Traversal in a Linked List
    temp = head;
    cout << "Linked List: ";

    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;

    // Insertion at Beginning
    newnode = new struct Node;
    cout << "Enter data to be Inserted at the Beginning: ";
    cin >> newnode->data;
    newnode->next = head;
    head = newnode;
    temp = head;
    cout << "Linked List (After Insertion): ";
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}