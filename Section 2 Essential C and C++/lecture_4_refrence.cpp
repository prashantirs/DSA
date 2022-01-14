#include<iostream>
using namespace std;

int main(){
    int a=10;
    int &r=a;
    cout<<a<<endl<<r<<endl;   
    return 0;
}

// ****(r) and (a) are same****
// Refrence is like a nickname

// Declaration of refference
// int & r;

// initializing a reference
// int & r=a;