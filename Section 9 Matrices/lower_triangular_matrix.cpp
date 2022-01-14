#include<iostream>
using namespace std;
class LowerTri{
    private:
    int n;
    int * A;
    public:
   
    LowerTri(int n){
        this->n=n;
        A=new int[n*(n+1)/2];
    }
    ~LowerTri(){
        delete []A;
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void Display();
};

void LowerTri::set(int i,int j,int x){
    
    if(i>=j){
    int index=((i*(i-1))/2)+(j-1);
    A[index]=x; 
    } 
}
void LowerTri::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j) {
                int index=((i*(i-1))/2)+(j-1);
            cout<<A[index]<<" ";
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}


int main(){
    LowerTri Lt(4);
    Lt.set(1,1,9);
    Lt.set(2,1,7);
    Lt.set(2,2,5);
    Lt.set(3,1,1);
    Lt.set(3,2,5);
    Lt.set(3,3,8);
    Lt.set(4,1,9);
    Lt.set(4,2,2);
    Lt.set(4,3,8);
    Lt.set(4,4,3);
    Lt.Display();
    return 0;
}