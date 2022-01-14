#include<iostream>
using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array ar){
    for(int i=0;i<ar.length;i++){
        cout<<ar.A[i]<<" ";
    }
};

int get(struct Array ar,int index){

    if(index>=0 && index<ar.length){
    return ar.A[index];
    }
    return -1;
};

void set(struct Array *ar,int index,int x){
    if(index>=0 && index<ar->length){
    ar->A[index]=x;
    }
};  

int sum(struct Array ar){
    int Total=0;
    for(int i=0; i<ar.length; i++){
        Total=Total+ar.A[i];
    }
    return Total;
};

float avg(struct Array ar){
    return (float)sum(ar)/ar.length;
};

int Max(struct Array ar){
    int max=ar.A[0];
    for(int i=1;i<ar.length;i++){
        if(ar.A[i]>max){
            max=ar.A[i];
        }
    }
    return max;
}
int Min(struct Array ar){
    int min=ar.A[0];
    for(int i=1;i<ar.length;i++){
        if(ar.A[i]<min){
            min=ar.A[i];
        }
    }
    return min;
}

int main(){
    struct Array ar={{2,3,40,5,6},10,5};
    
    // cout<<get(ar,1)<<endl;
    // set(&ar,4,10);
    // cout<<Max(ar)<<endl;
    // cout<<Min(ar)<<endl;
    // cout<<sum(ar)<<endl;
    // cout<<avg(ar)<<endl;
    Display(ar);
    return 0;
}