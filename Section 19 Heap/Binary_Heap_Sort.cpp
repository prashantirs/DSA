#include<iostream>
using namespace std;
 
 void Insert(int A[],int n){
     int i=n; //for Insert(A,2) n=2
     int j,temp;
     temp=A[n]; //temp=A[2] i.e. temp=20
     while(i>1 && temp>A[i/2]){
         //parent is A[i/2]
         //left child is 2*i
         //right child is 2*i + 1
         A[i]=A[i/2];
         i=i/2;//Move i to parent i.e. (i/2)
     }
     //now copy the element(in temp) where i is pointing 

     A[i]=temp;
 }

 

int main(){
 
   int A[]={0,10,20,45,60,70};
   //assume 0,10 is already present in Heap
   Insert(A,2);//We are sending 2nd index of array A[] i.e. 20 // after this this will become 0,10,20 but it is for max heap then it become 0,20,10 
   
   Insert(A,3); //45  // 0,20,10,45 then it become 0,45,10,20 

   Insert(A,4);//60
   Insert(A,5);//70
   
  
 return 0;
}