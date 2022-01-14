#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
};

Node * first=NULL;

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


void Display(struct Node *p){
    
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    
}

int isLoop(struct Node * first){
    //Creating two pointer p which moves 1 time and q moves 2 time is circular then they will meet
    Node *p,*q;
    p=q=first;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL; //if q is not NULL then do q=q->next
    }while(p!=NULL && q!=NULL && p!=q);
    if(p==q) return 1;
    else return 0;
}



int main(){
    struct Node *t1,*t2;
    int A[]={10,20,30,40,50};
    Create(A,5);
    //Making circular loop
    t1=first->next->next; // it is pointing to 30
    t2=first->next->next->next->next; //pointing to 50
    t2->next=t1 ;//making loop

    if(isLoop(first)) cout<<"It is Loop";
    else cout<<"Not Loop";
    return 0;
} 