#include<iostream>
#include<cstring>
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

int isOperand(char x){
    if(x =='+' || x =='-' || x =='*' || x =='/' ){
        return 0; //means its operator
    }else{
        return 1 ; //yes it is operand
    }
}

int Precedence(char x){
     if(x =='+' || x =='-' ) return 1;
     else if( x =='*' || x =='/' ) return 2; //Highest precedence
     return 0;
}

//it take  character type array using pointer 
int Eval(char *postfix){
    int x1,x2,res;
    for(int i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=Pop(); //top elment
            x1=Pop(); //below top element
            switch (postfix[i])
            {
            case '+': res=x1+x2; push(res) ; break;
            case '-': res=x1-x2; push(res) ; break;
            case '*': res=x1*x2; push(res) ; break;
            case '/': res=x1/x2; push(res) ; break;    
            }
        }
    }
    return Pop(); //it will show result of our expression
}

int main(){
    char * postfix=(char*)"35*62/+4-"; // its infix is 3*5+6/2-4
    // cout<<strlen(postfix)<<endl;
    cout<<Eval(postfix)<<endl;
    
    return 0;
}