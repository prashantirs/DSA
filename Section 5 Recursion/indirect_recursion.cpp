#include<iostream>
using namespace std;
//In Indirect Recursion one function calling another function in a form of a circle


void funB(int);//Function declaration

void funA(int n){
    if(n>0){
        cout<<n<<" ";
        funB(n-1);
    }
};

void funB(int n){
    if(n>1){
        cout<<n<<" ";
        funA(n/2);
    }
};

int main(){
    int x=20;
    funA(x);
    return 0;
}