#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

struct Node *front=NULL,*rear=NULL;

// Insert Function 
void enqueue(int x){
    Node *t;
    t=new Node;
    //check Queue is full or not
    if(t==NULL) cout<<"Queue is full ";
    else
    {
        t->data=x;
        t->next=NULL;
        //check is it is first node or not
        if(front==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    //check queue is empty or not
    if(front==NULL) cout<<"Queue is empty ";
    else
    {
        Node *p=front;
        x=front->data;
        front=front->next;
        delete p;
    }
    
    return x;
}

void Display(){
    Node *p=front; //creating a pointer p and taking it point on front node i.e first node of Queue
    cout<<"Oueue is: ";
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    Display();
    cout<<"Deleted Element is "<<dequeue()<<endl;
    Display();
    return 0;
}