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

    Node *r = NULL; 

 
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
            p = p->lchild;
        }
        else
            return;
    }
   
    Node *t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (key < r->data)
        r->lchild = t;
    else
        r->rchild = t;
}


void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node* Inorder_Predecessor(struct Node *p){
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}
Node* Inorder_Successor(struct Node *p){
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}

int Height(struct Node *p){
  int x;
    int y;
    if (p == NULL){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
Node * Delete(struct Node*p,int key){
    //search for key
    Node*q=NULL;
    if(p==NULL) return NULL;
    if (p->lchild == NULL && p->rchild == NULL && p->data==key){
        if (p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(key< p->data) Delete(p->lchild,key);
    else if(key> p->data) Delete(p->rchild,key);

    else //means key is found then delete
    {
        if (Height(p->lchild) > Height(p->rchild)){
            q=Inorder_Predecessor(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }else{
             q=Inorder_Successor(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
   
}

int main()
{   
    Insert(root, 10);
    Insert(root, 30);
    Insert(root, 20);
    Inorder(root);
    cout<<"\n";
    Delete(root,30);
    Inorder(root);

    return 0;
}