#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
};

Node * first=new Node;

void Create(int A[],int n){
    
    Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
        
    }
}

//Checking linked list is sorted or not
// ----->Here we take x=previous node data and compare with next node data
//if next node data is more than previous then yes it is sorted
int isSorted(struct Node *p){
    int x=-65536; //Min integer in 4 bytes


    while(p!=NULL){
        //Checking for false condition
        if((p->data)<x){
            return 0; //false    it will come out from while loop & function will end by returning 0 value
        }
        else{
            x=p->data;
            p=p->next;
        }
    }
        return 1; //true  means list is sorted
}

int main(){
    int A[]={10,20,30,40,50};
    Create(A,5);
    // cout<<isSorted(first);
    //if(1) means true
    if(isSorted(first)){
        cout<<"Linked list is Sorted";
    }else{
        cout<<"Linked list is not Sorted";
    }
    return 0;
}