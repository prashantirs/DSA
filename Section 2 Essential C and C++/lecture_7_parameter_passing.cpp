// ******Pass by Value********

#include<iostream>
using namespace std;
 
int add(int a,int b){
    int c;
    c=a+b;
    return c;
 }

int main(){
    int sum;
    sum=add(10,5);
    cout<<"Addition is "<<sum;
    return 0;
}

//*****Pass by address*********

#include<iostream>
using namespace std;

void swap(int * x,int* y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}

int main(){
    int a=10,b=20;
    swap(&a,&b);
    return 0;
}

// ****Pass by refrence*******
#include<iostream>
using namespace std;

void swap(int & x,int & y){
    int temp;
    temp=x;
    x=y;
    y=temp;

}

int main(){
    int a=10,b=20;
    swap(a,b);
    return 0;
}