#include<iostream>
using namespace std;

//Defining Structure
struct Rectangle{
    int length;
    int breadth;
};

int main(){

    struct Rectangle r1={10,5}; //Initilazing a structure

    r1.length=50;

    cout<<r1.length<<endl;  
    cout<<r1.breadth<<endl;  
    return 0;
}