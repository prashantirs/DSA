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

int Delete(struct Node *p,int POS){
        int x;
    if(POS<1 || POS>Length(first)) return -1;
    if(POS==1){
        first=first->next;
         x=p->data;
        delete p;
        if(first) first->prev=NULL;
         
    }else{
        for(int i=0;i<POS-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next) //Means if P next exit means it is not NULL then do go in if loop
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        delete p;
    }
       return x;
}


int main(){
    int A[]={2,3,4,5,6};
    Create(A,5);
    Delete(first,2);
    Display(first);
    return 0;
}