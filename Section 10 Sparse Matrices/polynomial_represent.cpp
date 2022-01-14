#include<iostream>
using namespace std;

class Term{
    public:
        int coeff;
        int exp;
};
class Poly{
    private:
    int n; //Non Zero terms
    Term * t;
    public:
        Poly(){
          n=0;
        }   
        void Read(){
             cout<<"Enter the number of Non Zero terms"<<endl;
                cin>>this->n;
             t=new Term[this->n]; 
            cout<<"Enter coefficient and exponent"<<endl;
            for(int i=0;i<n;i++){
                cin>>t[i].coeff>>t[i].exp;
            }
        }
        void Display(){
            for(int i=0;i<n;i++){
                cout<<t[i].coeff<<"x"<<t[i].exp<<"+" ; 
            } 
            cout<<endl;
        }
        friend Poly *Add(Poly *P1, Poly *P2);
};

Poly * Add(Poly * P1,Poly * P2){
    Poly * Sum;
    Sum=new Poly[P1->n +P2->n] ;
    int i,j,k;
    i=j=k=0;
    while(i<P1->n && j< P2->n){
        if(P1->t[i].exp >P2->t[j].exp){ 
            Sum->t[k++]=P1->t[i++] ;
        }
        else if(P1->t[i].exp < P2->t[j].exp){
            Sum->t[k++]=P2->t[j++] ;
        }
        else{
            Sum->t[k].exp=P1->t[i].exp;
            Sum->t[k++].coeff=P1->t[i++].exp + P2->t[j++].coeff;

        }
    }

    return Sum;
};
int main(){
    Poly P1,P2;
    Poly *P3; 
    P1.Read();
    P1.Display();
    P2.Read();
    P2.Display();
    P3=Add(&P1, &P2);
    P3->Display();
    return 0;
}