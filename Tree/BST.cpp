#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

void insert(Node *rootN, int val)
{
    Node *newNode = new Node(val), *temp = rootN;

    while (true)
    {
        if (temp->data >= val)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }
}

void pre_order(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    cout << n->data << " ";
    pre_order(n->left);
    pre_order(n->right);
}

void in_order(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    in_order(n->left);
    cout << n->data << " ";
    in_order(n->right);
}

void post_order(Node *n)
{
    if (n == NULL)
    {
        return;
    }
    post_order(n->left);
    post_order(n->right);
    cout << n->data << " ";
}

int main()
{
    cout << endl;
    Node *root = new Node(50);

    // insert(root, 50);
    insert(root, 70);
    insert(root, 40);
    insert(root, 20);
    insert(root, 30);
    insert(root, 35);
    insert(root, 45);
    insert(root, 60);
    insert(root, 90);

    pre_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
    post_order(root);
    cout << endl;

    return 0;
}