#include <iostream>
using namespace std;

class BSTnode
{
public:
    int data;
    BSTnode *left;
    BSTnode *right;

    BSTnode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Tree insertion and creation
BSTnode *createBST(BSTnode *root, int value)
{

    if (root == NULL)
    {
        root = new BSTnode(value);
    }
    if (root->data > value)
    {
        root->left = createBST(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = createBST(root->right, value);
    }

    return root;
}

void inordertraversal(BSTnode *root) // inorder traversal is in ascending order for BST
{
    if (root == NULL)
    {
        return;
    }
    inordertraversal(root->left);
    cout << root->data<<" ";
    inordertraversal(root->right);
}

int rightsucc(BSTnode *root)
{
    BSTnode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

// Deletion of nodes with two child
BSTnode *deleteBSTnode(BSTnode *root, int value)
{

    if (root->data > value)
    {
        root->left = deleteBSTnode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deleteBSTnode(root->right, value);
    }
    else
    {
        BSTnode *temp = root;

        if (temp->left == NULL && temp->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (temp->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        if (temp->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        int succesor = rightsucc(root->right);
        root->data = succesor;
        deleteBSTnode(root->right, succesor);
    }

    return root;
}

main()
{
    BSTnode *root = NULL;

    int n;
    cout << "Enter (n) Initial Number of Nodes Value: ";
    cin >> n;

    cout << "Enter Values: ";
    while (n--)
    {
        int value;
        cin >> value;
        root = createBST(root, value);
    }

    cout << "Root: " << root->data << endl;

    // Insertion
    cout << "\nEnter value to Insert: ";
    int val;
    cin >> val;
    createBST(root, val);
    inordertraversal(root);

    // Deletion
    cout << "\nEnter value to Delete: ";
    int val1;
    cin >> val1;
    deleteBSTnode(root, val1);
    inordertraversal(root);
}