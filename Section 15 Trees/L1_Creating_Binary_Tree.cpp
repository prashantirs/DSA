#include<iostream>
//User created Header file
#include "Queue.h" 
using namespace std;
 
class Tree{
    public:
    Node * root;
    //Constructor
     Tree(){root==NULL;};
    void CreateTree();
    void Preorder(struct Node *p);
    void Inorder(struct Node *p);
    void Postorder(struct Node *p);

};

void Tree::CreateTree(){
    Node*p,*t;
    int x;
    Queue q(100); //from header file

    //Create Root
    root=new Node;
    cout<<"Enter Root Element ";
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);//push adrress of root in Queue named 'q'

    //do till Queue have adress if no any adrress left then stop
    while(!q.isEmpty()){
        p=q.dequeue();//take out adrress from Queue and take p to point there

        //For left child
        cout<<"Enter Left Child of "<<p->data<<" "; //Here p is root at starting
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t); //Push address of t in Queue array
        }

         //For right child
        cout<<"Enter right Child of "<<p->data<<" "; //Here p is root at starting
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t); //Push address of t in Queue array
        }
    }
}


    void Tree::Preorder(struct Node *p) {
        
        if(p!=NULL){
            cout<<p->data<<" ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    } 

    void Tree::Inorder(struct Node *p) {
        
        if(p!=NULL){
            Inorder(p->lchild);
            cout<<p->data<<" ";
            Inorder(p->rchild);
        }
    }

    void Tree::Postorder(struct Node *p) {
        
        if(p!=NULL){
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout<<p->data<<" ";
        }
       
    }

    

int main(){
    Tree t;
    t.CreateTree();
    // t.Preorder(root); it will not work because root is data member of class Tree so we have to use dot operator
    cout<<"Preorder:"; t.Preorder(t.root); cout<<endl;
    cout<<"Inorder:"; t.Inorder(t.root); cout<<endl;
    cout<<"Postorder:"; t.Postorder(t.root); 
    return 0;
}