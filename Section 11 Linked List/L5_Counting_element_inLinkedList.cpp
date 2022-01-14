#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
};

Node * first=new Node;

int Count(struct Node *p){
   int length=0;
    while(p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}
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




int main(){
    int A[]={10,20,30,40,50};
    Create(A,5);
    cout<<Count(first);
    return 0;
}