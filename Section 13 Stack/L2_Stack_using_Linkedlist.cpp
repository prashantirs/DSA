#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *Top=NULL; //global pointer

void push(int x){
    Node *t=new Node;
    //check stack is full or not
    if(t==NULL) cout<<"Stack is Full";
    else{
        t->data=x;
        t->next=Top;
        Top=t;
    }
}

//it will delete at element by rule LIFO Last In First Out
int Pop(){
    int x=-1;
    Node *p=Top;
    if(Top==NULL) cout<<"Stack is Empty"; //No elements are there

    else{
    x=Top->data;
    Top=Top->next;
    delete p;
    }
    return x;
}

void Display(){
    Node * p=Top;
    cout<<"Elements is Stack are: ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Peek(int pos){
     Node *p=Top;
    if(Top==NULL) return -1;
    else{
        for(int i=0;p!=NULL && i<pos-1;i++){
            p=p->next;
        }
    }
       if(p!=NULL) return p->data;
       else return -1;
}

int main(){
    push(10);
    push(20);
    push(30);
    cout<<"Peek is "<<Peek(5)<<endl;;
    Display();
    cout<<"Pop element is "<<Pop()<<endl;
    Display();
    cout<<"Peek is "<<Peek(1)<<endl;
    return 0;
}