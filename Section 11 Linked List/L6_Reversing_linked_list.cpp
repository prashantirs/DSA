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

void Display(struct Node *p){
    
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    
}

//Method 1 by making auxiliary array
void Reverse1(struct Node *p){
    //array in heap where count is length of linked list
    int * A=new int[Count(p)];
    int i=0;
    while(p!=NULL){
        A[i]=p->data;
        i++;
        p=p->next;
    }
    //now p at null and i beyond array
    p=first;
    i--;
    while(p!=NULL){
        p->data=A[i];
        i--;
        p=p->next;
    }
}

//method 2 by reversing link (best method) using sliding pointers r q  p
void Reverse2(struct Node *p){
    Node *r=NULL,*q=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    first=q;
}

//method 3 using recursion

void Reverse3(struct Node * q,struct Node *p){
    if(p!=NULL){
        Reverse3(p,p->next);
        p->next=q;
    }else{
        //when p reacheas null and q reaches at last node in linked list
        first=q;
    }

}


int main(){
    int A[]={10,20,30,40,50,80};
    Create(A,6);
    // Reverse1(first);
    // Reverse2(first);
    Reverse3(NULL,first);
    Display(first);
    return 0;
}