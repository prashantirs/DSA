#include<iostream>
using namespace std;

void fun(int *p,int n){
    p[0]=15;
};

int main(){
    int A[5]={4,8,9,7,6};
    fun(A,5);
    for(int i=0;i<5;i++){
    cout<<A[i]<<endl;
    };
    return 0;
}


// ******In heap********
// #include<iostream>
// using namespace std;
// int * fun(int n){
//     int *p;
//     p=new int[n];
//     p[0]=1;
//     p[1]=2;
//     p[2]=3;
//     p[3]=4;
//     p[4]=5;
//     return p;
// }
// int main(){
//     int *ptr;
//     ptr=fun(5);//fun(5) is call which task is to create a array in heap
//     for (int i = 0; i <5; i++)
//     {
//       cout<<ptr[i]<<endl;  
//     };
    
//     return 0;
// }   