#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *temp;
struct node *newnode;
struct node *currentnode;
struct node *nextnode;
struct node *prevnode;
int main()
{
    head = NULL;
    int size;
    cout << "Enter the size of Linked List: ";
    cin >> size;
    int i = 0;
    cout << "Enter data: ";
    while (i < size)
    {
        newnode = new struct node;
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }
    cout << "Linked List: " << endl;
    temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;
    cout << "Reversed Linked List: " << endl;

    // code to reverse
    prevnode = NULL;
    nextnode = head;
    currentnode = head;
    while (nextnode->next != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    nextnode->next = prevnode;
    head = nextnode;
    // printing the link list
    temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}