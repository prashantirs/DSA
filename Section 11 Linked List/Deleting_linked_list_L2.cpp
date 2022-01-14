#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

 Node * first=new Node;

void Create(int A[],int n){

    Node * t,*last;

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

int Delete(struct Node *p,int key){
    int x=-1;
    Node *q=NULL;
//Checking for invalid index
    // if(key < 1 || key > count(p))
    if(key < 1 )
    return -1;

 if(key==1){
     q=first;
      x=first->data;
     first=first->next;
     delete p;
      return x;
     
 }
 else{
     for(int i=0;i<key-1;i++){
         q=p;
         p=p->next;
     }
    if(p){
        q->next=p->next;
         x=p->data;
        delete p;
    }
 }
         return x;
}

int main(){

    int A[]={10,20,30,40,50};
    Create(A,5);
    // Display(first);
    Delete(first,0);
    Display(first);
    return 0;
}