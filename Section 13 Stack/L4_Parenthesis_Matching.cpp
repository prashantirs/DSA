#include<iostream>
#include<cstring>
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

int isBalanced(char *exp){

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(') Push(exp[i]);
        else if(exp[i]==')'){
            //first check stack got empty or not agar empty hogya toh aage ka pop mtlb delete nhi kr payega
            if(isEmpty()) return 0;
            else Pop();
        }
    }
    return isEmpty()?1:0;
}

int main(){
   char  * exp=(char*)"((a+b)*(c+d))";
   cout<<strlen(exp)<<endl; //#include<cstring>
   if(isBalanced(exp)){
       cout<<"This Expression "<<exp<<endl<<"Paranthesis are matching";
   }
   else{
       cout<<"This Expression "<<exp<<endl<<"Paranthesis are not matching";
   }
  
    return 0;
}