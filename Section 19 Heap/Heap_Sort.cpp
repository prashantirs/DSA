#include<iostream>
using namespace std;
 
 void Insert(int A[],int n){
     int i=n; 
     int j,temp;
     temp=A[n]; 
     while(i>1 && temp>A[i/2]){
     
         A[i]=A[i/2];
         i=i/2;//Move i to parent i.e. (i/2)
     }
     //now copy the element(in temp) where i is pointing 
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
    //Only root is deleted means first element in array of Max Heap

    int val=A[1]; //store value of root to be deleted
    int i=1;
    int j=2*i;//j is Left child
              //j+1 is right child
    A[1]=A[n];//copy last element of array to root i.e. at first    (n pointing at last of array)     
    
    while(j<n-1){
        if(j<n-1 && A[j+1]>A[j])
        {
           j=j+1;//j ko greater pe le aao 
        }
        //j for child and i for parent
        if(A[j]>A[i])//if child is greater then swap as always parent is bigger
        {
            Swap(&A[j],&A[i]); //Swap child with parent
            i=j;
            j=2*j;
        }
        else break;
    } 

    A[n]=val; //at last position it will store value to be deleted--->Sorted Heap
    return val;//A[1]
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
    Display(A,5);//5 is size of heap n=5

   cout<<"\nDeleted Element is "<<Delete(A,5)<<endl;
   Display(A,5);
   cout<<"\nDeleted Element is "<<Delete(A,4)<<endl;
   Display(A,5);
   cout<<"\nDeleted Element is "<<Delete(A,3)<<endl;
   Display(A,5);
   cout<<"\nDeleted Element is "<<Delete(A,2)<<endl;
   Display(A,5);
   cout<<"\nDeleted Element is "<<Delete(A,1)<<endl;
   cout<<"Sorted Heap is ";
   Display(A,5);
  
   
  
 return 0;
} 