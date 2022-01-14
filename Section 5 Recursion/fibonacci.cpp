#include<iostream>
using namespace std;
//Using Normal Recursion

int fib(int n){
    if(n<=1)
    {
        return n;
    }else{
        return fib(n-2)+fib(n-1);
    }
};

int main(){
    cout<<fib(5);
    return 0;
}