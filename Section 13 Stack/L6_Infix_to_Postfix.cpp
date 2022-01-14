#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    char data;
    struct Node *next;
};

Node *Top=NULL; //global pointer

void push(char x){
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
char Pop(){
    char x=-1;
    Node *p=Top;
    if(Top==NULL) cout<<"Stack is Empty"; //No elements are there

    else{
    x=Top->data;
    Top=Top->next;
    delete p;
    }
    return x;
}

int isEmpty(){
    if(Top==NULL) return 1;//yes it is empty
    else return 0; //means flase
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

char * Convert(char * infix){
    int i=0,j=0;
    //creating a new array in heap for postfix
    char* postfix=new char[strlen(infix)+2];
    while(infix[i]!='\0'){
        if(isOperand(infix[i]))
        { //if a,b,c,d the send to postfix array
            postfix[j]=infix[i];
            j++;i++; 
        }
        else
        { //if it is operator(+,-,*,/) then push to stack and check next infix(i.e. move i++)
            if(Precedence(infix[i])>Precedence(Top->data))
            {
                //if precedence of operator is more then only push to stack
                push(infix[i++]);
            }
            else
            {
                //if precedence is low then pop element from stack and send to postfix array
                postfix[j++]=Pop();
            }
            
        }
    }
    while(!isEmpty()){
        postfix[j++]=Pop();
    }
    postfix[j]='\0' ;
    return postfix;
}

int main(){
    push('#');
    char *infix=(char *)"a+b*c-d/e";
    cout<<"Length of infix is "<<strlen(infix)<<endl;
    char *postfix=Convert(infix);
    cout<<postfix<<endl;
    cout<<"Length of postfix is "<<strlen(postfix)<<endl;
    return 0;
}