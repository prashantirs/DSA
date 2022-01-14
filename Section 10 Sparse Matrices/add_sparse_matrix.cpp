#include<iostream>
using namespace std;

class Element{
  public:
    int i;
    int j;
    int x;
};

class Sparse{
    private:
        int m;
        int n;
        int num;
        Element *e;
    public:
     Sparse(){
        this->m=2;
        this->n=2;
        this->num=2;
        e=new Element[this->num];
    }
    Sparse(int m,int n,int num){
        this->m=m;
        this->n=n;
        this->num=num;
        e=new Element[this->num];
    }
    ~Sparse(){
        delete [] e;
    }
    void Read(){
        cout<<"Enter all non zero values"<<endl;
        for(int i=0;i<num;i++){
            cin>>e[i].i>>e[i].j>>e[i].x ;
        }
    }

   
    void Display(){
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(e[k].i==i &&e[k].j==j){
                    cout<<e[k++].x<<" " ;
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
    friend Sparse *Add(Sparse *S1, Sparse *S2);

};

Sparse * Add(Sparse * S1,Sparse * S2){
        Sparse * Sum;
        if(S1->m!=S2->m || S1->n!=S2->n){
            return 0;
        }
        else{
            Sum=new Sparse ;
            Sum->m = S1->m;
            Sum->n = S1->n;
            Sum->e=new Element[S1->num + S2->num];
            int i,j,k ; 
            i=j=k=0;
            while(i<S1->num && j<S2->num){
                if(S1->e[i].i < S2->e[j].i){
                    Sum->e[k++]=S1->e[i++];
                }
                else if(S1->e[i].i > S2->e[j].i){
                    Sum->e[k++]=S1->e[j++];
                }
                else{
                    if(S1->e[i].j < S2->e[j].j){
                    Sum->e[k++]=S1->e[i++];
                } 
                 else if(S1->e[i].j > S2->e[j].j){
                    Sum->e[k++]=S1->e[j++];
                }
                else{
                    Sum->e[k]=S1->e[i];
                    Sum->e[k++].x = S1->e[i++].x + S2->e[j++].x;
                }
                }
            }

        }
        return Sum;

};
int main(){
    Sparse S1(3,3,3);
    Sparse S2(3,3,3);
    Sparse *S3;

    S1.Read();
    S1.Display();
    S2.Read();
    S2.Display();
    S3=Add(&S1,&S2);
    S3->Display();
    return 0;
}


