#include<iostream>
using namespace std;
 
 void Insert(int A[],int n){
     int i=n; 
     int j,temp;
     temp=A[n]; 
     while(i>1 && temp>A[i/2]){
     
         A[i]=A[i/2];
         i=i/2;
     }
  
     A[i]=temp;
 }

void Swap(int *x,int* y){
    int i,temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int Delete(int A[],int n){
    //n is total size of heap
    int val=A[1]; //store value of root to be deleted
    int i=1;
    int j=2*i;
    A[1]=A[n];
    
    while(j<n-1){
        if(j<n-1 && A[j+1]>A[j])
        {
           j=j+1;
        }
 
        if(A[j]>A[i])
        {
            Swap(&A[j],&A[i]); //Swap child with parent
            i=j;
            j=2*j;
        }
        else break;
    } 

    A[n]=val; 
    return val;
}

void Display(int A[],int n){
    for(int i=1;i<=n;i++){
    cout<<A[i]<<" ";
   }
}
 

int main(){
 
   int A[]={0,10,20,45,60,70};//last element n=5
   for(int i=2;i<=5;i++)
   {
       Insert(A,i);
   }
    cout<<"Heap at starting is ";
    Display(A,5);

    for(int j=5;j>1;j--){
        Delete(A,j);
    }

   cout<<"\nSorted Heap is ";
   Display(A,5);
  
   
  
 return 0;
} 