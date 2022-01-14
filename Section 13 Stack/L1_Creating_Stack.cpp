#include<iostream>
using namespace std;

//using array

struct Stack{
    int size;
    int top;
    int * S;
};

void Create(struct Stack *st){
    cout<<"Enter size of stack";
    cin>>st->size;
    st->S=new int[st->size];
    st->top=-1;

}

void Display(struct Stack st){
    cout<<"Elements in stack are : ";
    for(int i=st.top;i>=0;i--){
        cout<<st.S[i]<<" ";
    }
}

void Push(struct Stack *st,int x){
    //first check stack is full or not
    if(st->top==st->size-1) cout<<"Stack OverFlow from elements "<<x<<endl;
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int Pop(struct Stack *st,int POS){
    int x=-1;
    //check stack is empty or not
    if(st->top==-1) cout<<"Stack Underflow"<<endl;
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int stackTop(struct Stack st){
   if(st.top==-1) return -1; //means stack is empty
   else{
       return st.S[st.top];
   }
}
int isEmpty(struct Stack st){
    if(st.top==-1) return 1;//yes it is empty
    else return 0; //means flase
}
int isFull(struct Stack st){
    if(st.top==st.size-1) return 1;//yes it is full
    else return 0; //means stack is not full
}

int main(){
    Stack st;
    Create(&st);
    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);
    cout<<"Stack top is "<<stackTop(st)<<endl;
    if(isEmpty(st)) cout<<"Stack is Empty"<<endl;
    else cout<<"Stack is Not Empty"<<endl;

    if(isFull(st)) cout<<"Stack is Full"<<endl;
    else cout<<"Stack is Not Full"<<endl;
    
 
    Display(st);
    return 0; 
}