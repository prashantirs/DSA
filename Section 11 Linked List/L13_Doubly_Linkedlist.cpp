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
    return len;
}

int main(){
    int A[]={2,3,4,5,6};
    Create(A,5);
    Display(first);
    cout<<Length(first);
    return 0;
}