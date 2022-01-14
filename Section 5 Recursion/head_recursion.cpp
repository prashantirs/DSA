#include<iostream>
using namespace std;

//In Head recursion our complete code run duning calling time as well as
//    returning time

void fun(int n){
    if(n>0){
        fun(n-1);
        cout<<n;
    }
};

int main(){
    int x=3;
    fun(x);
    return 0;
}