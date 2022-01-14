#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

class CircularLinkedlist{
    private:
    Node * Head;
    public:
     CircularLinkedlist(int *A,int n);
     Node* getHead(){ return Head; }
     ~CircularLinkedlist();

     void Display();
     void RecursiveDisplay( Node * h);

};

CircularLinkedlist::CircularLinkedlist(int *A,int n){
    Node *t,*last;
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

void CircularLinkedlist::Display(){
    Node *p;
    p=Head;
    do{
        cout << p->data << " ";
        p=p->next;
    }while(p!=Head);
    cout<<endl;
}

 void CircularLinkedlist::RecursiveDisplay( Node * p){
     static int flag=0;

     if(p!=Head || flag==0){
         flag=1;
         cout<<p->data<<" ";
         RecursiveDisplay(p->next);
     }
     flag=0;
 }



CircularLinkedlist::~CircularLinkedlist() {
    Node* p = Head;
    while (p->next != Head){
        p = p->next;
    }
 
    while (p != Head){
        p->next = Head->next;
        delete Head;
        Head = p->next;
    }
 
    if (p == Head){
        delete Head;
        Head = nullptr;
    }
 
}


int main(){
    int A[]={2,3,4,5,6};
    CircularLinkedlist l(A,5);
    l.Display();

    Node* h = l.getHead();
    l.RecursiveDisplay(h);
    return 0;
}