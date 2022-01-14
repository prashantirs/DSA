#include<iostream>
using namespace std;

int fun(int n){
    if(n>100){
        return n-10;
    }
    else{
       return fun(fun(n+11));
    }
}

int main(){
    int result;
    result=fun(95);
    cout<<result;
    return 0; 
}