#include<iostream>
using namespace std;

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;

}*first=NULL;

void Create(int A[],int n){
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    cout<<endl;
    return len;
}

void Reverse(struct Node *p){
    Node * temp;
    while(p){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev; //now p->next is p->prev as values as swaped
    if(p!=NULL && p->next==NULL) first=p;
    }

}



int main(){
    int A[]={2,3,4,5,6};
    Create(A,5);
    Reverse(first);
    Display(first);
    return 0;
}