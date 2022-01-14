#include<iostream>
#include"Queue.h"
using namespace std;

//using array

struct Stack{
    int size;
    int top; 
    Node** S;
};

void StackCreate(struct Stack *st){
    cout<<"Enter size of stack";
    cin>>st->size;
    st->S=new Node*[st->size];
    st->top=-1;

}


void Push(struct Stack *st,Node * x){
    //first check stack is full or not
    if(st->top==st->size-1) cout<<"Stack OverFlow from elements "<<x<<endl;
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

 long int Pop(struct Stack *st){
    struct Node *x=NULL;
    //check stack is empty or not
    if(st->top==-1) cout<<"Stack Underflow"<<endl;
    else{
        x=st->S[st->top];
        st->top--;
    }
    return  (long int)x;
}


int isEmptyStack(struct Stack st){
    if(st.top==-1) return 1;//yes it is empty
    else return 0; //means flase
}
int isFullStack(struct Stack st){
    if(st.top==st.size-1) return 1;//yes it is full
    else return 0; //means stack is not full
}

Node * stackTop(struct Stack st){
   if(st.top==-1) return 0; //means stack is empty
   else{
       return st.S[st.top];
   }
}
