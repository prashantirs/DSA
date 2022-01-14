#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array ar){
    for(int i=0;i<ar.length;i++){
        cout<<ar.A[i]<<" ";
    }
}

void Reverse(struct Array *ar){
    int i,j;
    int * B;
    B=new int[ar->length];
    for(i=ar->length-1,j=0; i>=0; i--,j++){
        B[j]=ar->A[i];
    }
    for(int i=0;i<ar->length;i++){
        ar->A[i]=B[i]; 
    }

}

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

void Reverse2(struct Array *ar){
    int i,j;
    for(i=0,j=ar->length-1 ; i<j;i++,j--){
            swap(&ar->A[i],&ar->A[j]);
    }
}

void Lshift(struct Array *ar){
    int i,j;
    for(i=0; i<ar->length; i++){
        ar->A[i]=ar->A[i+1];
    }
}
void Rshift(struct Array *ar){
    int i,j;
    for(i=ar->length;i>=0;i--){
        ar->A[i]=ar->A[i-1];
    }
}
//Left Rotate
void Rotate(struct Array *ar){
    int i,j;
    int x=ar->A[0];
    for(i=0; i<ar->length; i++){
        ar->A[i]=ar->A[i+1];
    }
    ar->A[ar->length-1]=x;
}

int main()
{
    struct Array ar={{2,3,4,5,6},10,5};
    Rotate(&ar); 
    Display(ar); 
    return 0;
}