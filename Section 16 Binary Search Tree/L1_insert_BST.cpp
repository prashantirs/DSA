#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root = NULL;

void Insert(struct Node *p, int key)
{

    Node *r = NULL; //r is tail pointer which is following p

    //creating first element root (if root is null)
    if (p == NULL)
    {
        Node *t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        root = t;
        return;
    }
    while (p != NULL)
    {
        r = p;
        if (key > p->data)
            p = p->rchild;
        else if (key < p->data)
        {
            p = p->lchild; //move to left
        }
        else
            return;
    }
    //Now p points at null and r point at insert location
    Node *t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (key < r->data)
        r->lchild = t;
    else
        r->rchild = t;
}

//Inorder Traversal give sorted binary tree
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

//Searching
//It will return a pointer pointer to a node
Node *Search(struct Node *, int key)
{
    Node *p = root; //taking pointer p to root
    while (p != NULL)
    {
        if (key == p->data)
            return p; //Element found
        else if (key < p->data)
        {
            p = p->lchild;
        }
        else
            p = p->rchild;
    }
    return NULL; //if element not found
}
int main()
{   Node * temp;
    Insert(root, 10);
    Insert(root, 30);
    Insert(root, 20);
    Inorder(root);
    temp=Search(root,40);
    if(temp) cout<<"\nElement "<<temp->data<<" is present";
    else cout<<"\nElement not present";
    return 0;
}