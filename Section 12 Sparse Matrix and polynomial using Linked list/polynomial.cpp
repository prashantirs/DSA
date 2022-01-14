#include<iostream>
#include <cmath>
using namespace std;

struct Node{
    int coeff;
    int exp;
    struct Node * next;
};

Node * poly=NULL;

void Create(){
    int num;
    cout<<"Enter no of elements ";
    cin>>num;
    cout<<"Enter coefficients and power";
    Node * t=NULL,*last=NULL;
    for(int i=0;i<num;i++){
        t=new Node;
        cin>>t->coeff>>t->exp;
        if(poly==NULL){
            poly=last=t;
        }else{

        t->next=NULL;
        last->next=t;
        last=t;
        }
    }

}

void Display(struct Node * p){
    while(p){
        cout<<p->coeff<<"x"<<p->exp;
        p=p->next;
        if(p) cout<<" + ";
    }
    cout<<endl;
}
long Eval(struct Node *p,int x){
    long sum=0;
    while(p){
        sum+=p->coeff*pow(x,p->exp);  //#include <cmath>  we have to add this header file
        p=p->next;
    }
    return sum;
}

int main(){
    Create();
    Display(poly);
    cout<<"Sum is "<<Eval(poly,1); 
    return 0;
}