#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

// Getting Height of tree
int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

// Creating new node
Node *createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Getting balance factor
int getBalanceFactor(Node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// for finding Max of two number
int max(int x, int y)
{
    return (x > y) ? x : y;
}

// For Right Rotation
Node *rightRotate(Node *root)
{
    Node *oldRoot = root->left;
    Node *T2 = oldRoot->right;

    oldRoot->right = root;
    root->left = T2;

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    oldRoot->height = max(getHeight(oldRoot->right), getHeight(oldRoot->left)) + 1;

    return oldRoot;
}

// For Left Rotation
Node *leftRotate(Node *root)
{
    Node *oldRoot = root->right;
    Node *T2 = oldRoot->left;

    oldRoot->left = root;
    root->right = T2;

    oldRoot->height = max(getHeight(oldRoot->right), getHeight(oldRoot->left)) + 1;
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    return oldRoot;
}

// AVL Insertion
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;

    int bf = getBalanceFactor(node);

    //LL type tree
    if (bf > 1 && data < node->left->data)
        return rightRotate(node);

    //RR type tree
    if (bf < -1 && data > node->right->data)
        return leftRotate(node);

    //LR type tree
    if (bf > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //RL type tree
    if (bf < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Finding min value node in tree
Node *minValueNode(Node *node)
{
    Node *curRoot = node;

    while (curRoot->left != NULL)
        curRoot = curRoot->left;

    return curRoot;
}

// AVL deletion
Node *deletenode(Node *root, int data)
{

    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deletenode(root->left, data);

    else if (data > root->data)
        root->right = deletenode(root->right, data);

    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deletenode(root->right,
                                     temp->data);
        }
    }

    // if there is only one node previously i.e. before deletion
    if (root == NULL)
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 &&
        getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (bf > 1 &&
        getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (bf < -1 &&
        getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (bf < -1 &&
        getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// For Preorder Traversal
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int nodes_insert, nodes_delete, value_insert, value_delete;

    cout << "AVL TREE" << endl;
    
    cout<<"\nInsertion"<<endl;
    cout << "Enter total number of nodes to be inserted: ";
    cin >> nodes_insert;

    for (int i = 0; i < nodes_insert; i++)
    {
        cout << "Enter Node Value: ";
        cin >> value_insert;
        root = insert(root, value_insert);
    }

    cout << "Inorder traversal: " << endl;
    preOrder(root);
    
    cout<<endl;

    cout<<"\nDeletion"<<endl;
    cout<<"Enter number of nodes to be deleted: ";
    cin>>nodes_delete;

    for (int i = 0; i < nodes_delete; i++)
    {
        cout << "Enter Node Value to delete: ";
        cin >> value_delete;
        root = deletenode(root, value_delete);
    }
    cout << "Preorder Traversal: " << endl;
    preOrder(root);
        
    return 0;
}