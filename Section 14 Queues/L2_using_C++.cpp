#include<iostream>
using namespace std;

//ADT of Queue


class Queue{
    private:
    int size;
    int front;
    int rear;
    int * Q;

    public:
     Queue(int length);
     ~Queue();
    void Display();
    int isFull();
    int isEmpty();
    void enqueue(int x);
    int dequeue();
};

Queue:: Queue(int length){
    size=length;
    front=rear=-1;
    Q=new int[size]; //creating array Q is a pointer to that array in heap
}
Queue::~Queue() {
    delete [] Q;
}

//pass by value so get by dot operator
void Queue::Display(){
    cout<<"Queue is: ";
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int Queue::isFull(){
    if(rear==size-1) return 1; //yes queue is full
    return 0; //else return false i.e 0
}

int Queue::isEmpty(){
    if(front==rear) return 1; //yes queue is empty
    return 0; //else return false i.e 0
}



void Queue::enqueue(int x){
    //check first os queue if full or not
    if(isFull()) cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        Q[rear]=x; //Q[rear]=x
    }
}

int Queue:: dequeue(){
    int x=-1;
    //check queue is empty of not if not empty then delete
    if(isEmpty()) cout<<"Queue is empty ";
    else
    {
    front++;
    x=Q[front];
    }
    return x;
}

int main(){
 
    int length;
    cout<<"Enter length of Queue you want to make ";
    cin>>length;    
    Queue q(length); //creating a queue of name 'q'
    //Insert is know as her enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    cout<<"Deleted element is "<<q.dequeue()<<endl;
    q.Display();
    return 0;
}