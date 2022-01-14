#include<iostream>
using namespace std;

class Element {
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
    Sparse(int m,int n,int num){
        this->m=m;
        this->n=n;
        this->num=num;
        e=new Element [this->num];
    }
    ~Sparse(){
        delete [] e;
    }
    void Read(){
        cout<<"Enter Non Zero Value";
        for(int i=0;i<num;i++){
            cin>>e[i].i>>e[i].j>>e[i].x;
        }
    }
    void Display(){
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(e[k].i==i && e[k].j==j){
                    cout<<e[k].x<<" ";
                    k++;
                   
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
    }
};

int main(){
    Sparse S1(3,3,3);
    S1.Read(); 
    S1.Display();
    return 0;
}



