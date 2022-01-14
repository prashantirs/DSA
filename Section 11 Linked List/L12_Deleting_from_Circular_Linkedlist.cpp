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
     void Delete(int POS);
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

void CircularLinkedlist::Delete(int POS){
    Node *p,*q;
    int x;
    if(POS<0 || POS>Length()) cout<<"Element is not their";
    else{
        if(POS==0){
            p=Head;
            while(p->next!=Head) p=p->next;
            if(p==Head){
                delete Head;
                Head=NULL;
            }else{
                p->next=Head->next;
                delete Head;
                Head=p->next;
            }
        }else{
            p=Head;
            for(int i=0;i<POS-2;i++){
              p=p->next;  
            }
            q=p->next;
            p->next=q->next;
            delete q;
        }
    }
}




int main(){
    int A[]={2,3,4,5,6};
    CircularLinkedlist l(A,5);
    l.Delete(4);
    l.Display();
    return 0;
}