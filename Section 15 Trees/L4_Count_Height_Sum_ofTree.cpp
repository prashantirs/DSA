#include <iostream>
//User created Header file
#include "Stack.h"
#include "Queue.h"
using namespace std;

class Tree
{
public:
    Node *root;
    //Constructor
    Tree() { root == NULL; };
    void CreateTree();
    void Preorder(struct Node *p);
    void Inorder(struct Node *p);
    void Postorder(struct Node *p);
    void Leveloder(struct Node *p);
    int CountNodes(struct Node *p);
    int SumofTree(struct Node *p);
    int Height(struct Node *root);
    int Leaf_of_Tree(struct Node *p);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100); //from header file

    //Create Root
    root = new Node;
    cout << "Enter Root Element ";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root); //push adrress of root in Queue named 'q'

    //do till Queue have adress if no any adrress left then stop
    while (!q.isEmpty())
    {
        p = q.dequeue(); //take out adrress from Queue and take p to point there

        //For left child
        cout << "Enter Left Child of " << p->data << " "; //Here p is root at starting
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t); //Push address of t in Queue array
        }

        //For right child
        cout << "Enter right Child of " << p->data << " "; //Here p is root at starting
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t); //Push address of t in Queue array
        }
    }
}

//Recursive Methods
void Tree::Preorder(struct Node *p)
{

    if (p != NULL)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(struct Node *p)
{

    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(struct Node *p)
{

    if (p != NULL)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Leveloder(struct Node *p)
{
    Queue q(100);
    cout << p->data;
    q.enqueue(p);
    //Check Queue is empty or not
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data;
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data;
            q.enqueue(p->rchild);
        }
    }
}

int Tree::CountNodes(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = CountNodes(p->lchild);
        y = CountNodes(p->rchild);
        return x + y + 1;
    }
    else
    {
        return 0;
    } //we can write directly return 0; no need of else
}
int Tree::SumofTree(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = CountNodes(p->lchild);
        y = CountNodes(p->rchild);
        return x + y + p->data;
    }
    else
    {
        return 0;
    } //we can write directly return 0; no need of else
}

//Height starting from 1
int Tree::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
    { 
        return -1;
    }
    else
    {
        x = CountNodes(root->lchild);
        y = CountNodes(root->rchild);
        //Extra condition from CountNodes
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    cout << "Total Nodes of tree is:" << t.CountNodes(t.root) << endl; //we have to write (t.root) as root is member function of t
    cout << "Sum of of tree is:" << t.SumofTree(t.root) << endl;
    cout << "Height of tree is:" << t.Height(t.root) << endl;
    return 0;
}