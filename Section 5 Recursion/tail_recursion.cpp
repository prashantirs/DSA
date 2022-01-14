#include<iostream>
using namespace std;

//In tail recursion our complete code run duning calling time

void fun(int n){
    if(n>0){
        cout<<n;
        fun(n-1);
    }
};

int main(){
    fun(3);
    return 0;
}