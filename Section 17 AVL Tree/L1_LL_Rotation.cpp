#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int height; //it will store height of each node
    struct Node *rchild;
};

int NodeHeight(struct Node *p);
int BalanceFactor(struct Node *p);
struct Node *LLRotation(struct Node *p);
struct Node *RRRotation(struct Node *p);
struct Node *LRRotation(struct Node *p);
struct Node *RLRotation(struct Node *p);


struct Node *root = NULL; //Globally access

//Recursive Binary Search Tree Insert
Node *RInsert(struct Node *p, int key)
{
    Node *t; //t is a pointer pinting to a Node structure

    //If root is null at starting
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1; //I am taking height from 1
        t->lchild = t->rchild = NULL;
        return t;
    }

    //if there any node and p pointing to root
    //check if the inserting value is already present then dont do any thing and return
    if (key == p->data)
        return NULL;

    else if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else
    {
        p->rchild = RInsert(p->rchild, key);
    }
    //updating height
    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == 1)
        return RLRotation(p);
    return p;
}

int NodeHeight(struct Node *p)
{
    int hl, hr; //hl is Height of left sub tree & hr is Height of right sub tree

    // Short Code of above using ternary operator
     hl=p && p->lchild?p->lchild->height:0;
     hr=p && p->rchild?p->rchild->height:0;

     return hl>hr?hl+1:hr+1;

    //Long Code
    // if (p != NULL && p->lchild != NULL)
    // {
    //     hl = p->lchild->height;
    // }
    // else
    //     hl = 0;

    // if (p != NULL && p->rchild != NULL)
    // {
    //     hr = p->rchild->height;
    // }
    // else
    //     hr = 0;

    // if (hl > hr)
    //     return hl + 1; //if height of left sub tree is more
    // else
    //     return hr + 1; //if height of right sub tree is more

}

int BalanceFactor(struct Node *p)
{
    //hl is Height of left sub tree & hr is Height of right sub tree
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;
    return plr;
}

Node *RRRotation(struct Node *p)
{
     struct Node *pr = p->rchild;
    struct Node *plr = pr->lchild;

    pr->lchild = p;
    p->rchild = plr;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->rchild = prl->lchild;
    p->lchild = prl->rchild;

    prl->lchild = pr;
    prl->rchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;
    return prl;
}

int main()
{

    root = RInsert(root, 20);
    RInsert(root, 10);
    RInsert(root, 30);

    return 0;
}