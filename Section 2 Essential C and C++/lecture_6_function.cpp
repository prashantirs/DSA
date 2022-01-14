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