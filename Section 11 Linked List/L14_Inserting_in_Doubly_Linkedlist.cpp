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

void Insert(struct Node *p,int POS,int x){
    if(POS<0 || POS>Length(first)) return; //It will exit from Insert Function

    if(POS==0){
        Node * t=new Node;
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }else{
        for(int i=0;i<POS-1;i++){
            p=p->next;
        }
        Node *t=new Node; 
        t->data=x;
        t->next=p->next;
        t->prev=p;
    // if P next exist means not NULL then 
        if(p->next){p->next->prev=t;}

        p->next=t;    
    }

}

int main(){
    int A[]={2,3,4,5,6};
    Create(A,5);
    Insert(first,5,100);
    Display(first);
    return 0;
}