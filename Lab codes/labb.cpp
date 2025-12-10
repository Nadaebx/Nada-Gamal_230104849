#include <iostream>
using namespace std;
class Node
{
    public :
    int data;
    Node *left, *right;
    Node(int value)
    {
        data=value;
        left = right =NULL;
    }


class BST
{
    public :
    Node *root;
    BST()
    {
        root = NULL;
    }

    Node* insert(Node* r, int item)
    {
        if (r == NULL)
        {
            Node*newNode = new Node(item);
            r= newNode;
        }
        else if (item <= r->data)
        {
            r->left = insert(r->left, item);
        }
        else
        {
            r->right = insert(r->right,item);
        }
        return r;
    }
    void insert (int item)
    {
        root = insert(root ,item);
    }
    void preorder(Node* r)
    {
        if (r == NULL)
        return;
        {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
        void inorder(Node* r)
        {
        if (r == NULL)
        return;
        
            inorder(r->left);
            cout << r->data << "\t";
            inorder(r->right);
        }

        void postorder(Node* r)
        {


    }
};};