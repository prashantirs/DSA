#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array ar){
    int i;
    for(i=0;i<ar.length;i++){
        cout<<ar.A[i]<<" ";
    }
};

int main(){
    struct Array ar={{2,3,4,5,6},10,5};
    Display(ar);
    return 0;
}