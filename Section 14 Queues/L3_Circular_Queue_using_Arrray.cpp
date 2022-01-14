#include<iostream>
using namespace std;

//ADT of Queue
struct Queue{
    int size;
    int front;
    int rear;
    int * Q;
};

void Create(struct Queue *q,int length){
    q->size=length;
    q->front=q->rear=0;
    q->Q=new int[q->size]; //creating array Q is a pointer to that array in heap
}

//pass by value so get by dot operator
void Display(struct Queue q){
    cout<<"Queue is: ";
    int i=q.front+1;
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
        
    }while(i!=(q.rear+1)%q.size);
    cout<<endl;
}

int isFull(struct Queue q){
    if((q.rear+1)%q.size==q.front) return 1; //yes queue is full
    return 0; //else return false i.e 0
}

int isEmpty(struct Queue q){
    if(q.front==q.rear) return 1; //yes queue is empty
    return 0; //else return false i.e 0
}

void enqueue(struct Queue *q,int x){
    //check first os queue if full or not
    if(isFull(*q)) cout<<"Queue is Full"<<endl;
    else
    {
        q->rear=(q->rear+1)%q->size; //circular moving rear
        q->Q[q->rear]=x; //Q[rear]=x
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    //check queue is empty of not if not empty then delete
    if(isEmpty(*q)) cout<<"Queue is empty ";
    else
    {
    q->front=(q->front+1)%q->size;
    x=q->Q[q->front];
    }
    return x;
}

int main(){
    Queue q; //creating a queue of name 'q'
    int length;
    cout<<"Enter length of Queue you want to make ";
    cin>>length;    
    Create(&q,length);
    //Insert is know as her enqueue
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    Display(q);
    cout<<"Deleted element is "<<dequeue(&q)<<endl;
    Display(q);
    return 0;
}