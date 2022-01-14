#include<iostream>

//for cin and cout we use
using namespace std;

class Node{
    public:
    int data;
    Node * next;    
};

class Stack{
    private:
         Node *Top;
    public:
    //Constructor
        Stack(){
            Top=NULL;
        }      
     void Push(int x); 
     int Pop();
     void Display();  
};

 void Stack:: Push(int x){
     Node *t=new Node;
     //if t is not created means stack is full
     if(t==NULL){
         cout<<"Stack is Full";
     }else{
         t->data=x;
         t->next=Top;
         Top=t;
     }   
 }

 void Stack:: Display(){
     Node *p=Top;
     cout<<"Elements in Stack is: ";
     while(p){
         cout<<p->data<<" ";
         p=p->next;
     }
     cout<<endl;
 }

int Stack::Pop(){
    int x=-1;
    Node *p=Top;
    if(Top==NULL) cout<<"Stack is Empty";
    else{
        x=Top->data;
        Top=Top->next;
        delete p;
    }
    return x;

  }

int main(){
    //Object of stack i.e.  s1
    Stack s1;
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Display();
    cout<<"Pop Element is "<<s1.Pop()<<endl;
    s1.Display();
    return 0;
}