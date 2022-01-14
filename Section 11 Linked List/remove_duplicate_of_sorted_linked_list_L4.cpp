#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
};

Node * first=new Node;

void Create(int A[],int n){
    
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        
    }
}

void Display(struct Node *p){
    
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    
}

void RemoveDuplicate(struct Node *p){
// p is traling pointer which is following q  and 'q' aage hai 'p' ke
    p=first;
    Node * q=p->next;
    while(q!=NULL){
        //if no duplicate element so move next 
        
        if(p->data!=q->data){
            p=q;   //move p to q
            q=q->next; //move q to next node of q
        }
        //if duplicate elements are found then delete q
        else{
             p->next=q->next;
             delete q;
             q=p->next;
        }
    }
}

int main(){
    int A[]={10,10,10,10,10,20,20,30,40,50};
    Create(A,10);
    RemoveDuplicate(first);
    Display(first);
    return 0;
}