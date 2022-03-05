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
struct Node *prevnode;
int main()
{
    head = NULL;
    int size;
    cout << "Enter the size of Linked List: ";
    cin >> size;
    int i = 0;
    cout << "Enter data : ";
    ;
    while (i < size)
    {
        newnode = new struct Node;
        cin >> newnode->data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }
    cout << "Linked List : " << endl;
    temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;
    temp = head;

    head = temp->next;
    free(temp);
    cout << "Linked List after Deletion: " << endl;
    temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}