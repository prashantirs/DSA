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

void insert(struct Array *ar,int index,int x){
    int i;
    for(i=ar->length;i>index;i--){
        ar->A[i] = ar->A[i-1]; //A[i]=A[i-1];
    }
    ar->A[index]=x;
    ar->length++;
};

int main(){
    struct Array ar={{2,3,4,5,6},10,5};
    insert(&ar,3,15);
    Display(ar);
    return 0;
}