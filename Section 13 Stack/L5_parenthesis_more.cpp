#include<iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
};

Node *Top=NULL; //global pointer

void Push(char x){
    Node *t=new Node;
    //check stack is full or not
    if(t==NULL) cout<<"Stack is Full";
    else{
        t->data=x;
        t->next=Top;
        Top=t;
    }
}

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
    if(Top==NULL) return 1;
    else return 0;
}

char topElement(){
    
    if(Top==NULL) return false;
    else{
        return Top->data;
    }
}

int isBalanced(char *exp){

    for(int i=0;exp[i]!='\0';i++){
        char x;
        if(exp[i]=='(' ||exp[i]=='{'||exp[i]=='[') Push(exp[i]);
        else if(exp[i]==')' ||exp[i]=='}'||exp[i]==']'){
            //first check stack got empty or not agar empty hogya toh aage ka pop mtlb delete nhi kr payega
            if(isEmpty()) return 0;

            int a=0;
            if(exp[i] == ')') a = topElement()+1;

            if(exp[i] == ']') a = topElement()+2;

            if(exp[i] == '}') a = topElement()+2;

            if(exp[i] == a) Pop();
           
        }
    }
    return isEmpty()?1:0;
}

int main(){
   char  * exp=(char*)"[{(a+b}*(c+d))]";
   if(isBalanced(exp)){
       cout<<"This Expression "<<exp<<endl<<"Paranthesis are matching";
   }
   else{
       cout<<"This Expression "<<exp<<endl<<"Paranthesis are not matching";
   }
  
    return 0;
}