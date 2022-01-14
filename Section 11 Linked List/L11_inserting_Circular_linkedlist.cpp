#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

class CircularLinkedlist{
    private:
    Node * Head;
    public:
     CircularLinkedlist(int *A,int n);

     void Display();
     void Insert(int POS, int x);
     int Length();
  

};

CircularLinkedlist::CircularLinkedlist(int *A,int n){
    Node *t,*last;
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

void CircularLinkedlist::Display(){
    Node *p;
    p=Head;
    do{
        cout << p->data << " ";
        p=p->next;
    }while(p!=Head);
    cout<<endl;
}

int CircularLinkedlist:: Length(){
    int len=0;
    Node *p=Head;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}

void CircularLinkedlist::Insert(int POS, int x){
    Node *t,*p;
    if(POS<0 || POS>Length() ){
        return; //if this execute it will completely return from Insert Function
    }
    else{
            if(POS==0){
                t=new Node;
                t->data=x;
                if(Head==NULL)
                {
                    Head=t;
                    Head->next=Head;
                }else{
                    p=Head;
                    while(p->next!=Head){
                        p=p->next; //stop at last node
                    }
                        p->next=t;
                        t->next=Head;
                        Head=t;
                    
                }
            }
            else{
                t=new Node;
                p=Head;
                for(int i=0;i<POS-1;i++){
                    p=p->next;
                }
                t->data=x;
                t->next=p->next;
                p->next=t;

                
            }
    }
}



int main(){
    int A[]={2,3,4,5,6};
    CircularLinkedlist l(A,5);
    l.Insert(0,10);
    l.Display();
    return 0;
}