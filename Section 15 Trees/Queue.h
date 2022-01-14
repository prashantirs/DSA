#ifndef Queue_h //avoid multiple include
#define Queue_h

#include<iostream>
using namespace std;

//ADT of Queue
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
    private:
    int size;
    int front;
    int rear;
    Node ** Q;

    public:
     Queue(int length);

    void Display();
    int isFull();
    int isEmpty();
    void enqueue(Node * x);
    Node* dequeue();
};

Queue:: Queue(int length){
    size=length;
    front=rear=-1;
    Q=new Node*[size]; //creating array Q is a pointer to that array in heap
}




int Queue::isFull(){
    if(rear==size-1) return 1; //yes queue is full
    return 0; //else return false i.e 0
}

int Queue::isEmpty(){
    if(front==rear) return 1; //yes queue is empty
    return 0; //else return false i.e 0
}



void Queue::enqueue(Node * x){
    //check first os queue if full or not
    if(isFull()) cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        Q[rear]=x; //Q[rear]=x
    }
}

Node * Queue:: dequeue(){
    Node* x=NULL;
    //check queue is empty of not if not empty then delete
    if(isEmpty()) cout<<"Queue is empty ";
    else
    {
    front++;
    x=Q[front];
    }
    return x;
}

#endif