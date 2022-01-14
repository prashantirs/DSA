#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};


int main(){
    Rectangle r={10,5};
    Rectangle *p=&r; //Pointer p pointing to Structure r

    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
// p is pointer pointing to structure r of Rectangle kind
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    return 0;
}


//Create rectangle object in Heap
// #include<iostream>
// using namespace std;

// struct Rectangle
// {
//     int length;
//     int breadth;
// };

// int main(){
//     // Pointer Declration of structure
//     Rectangle *p;
//     // Creating Rectangle Structure in Heap where P is pointer pointing to Structure Rectangle in Heap
//     p=new Rectangle; //In Heap
//     p->length=15;
//     p->breadth=10;
//     cout<<p->length<<endl<<p->breadth<<endl;

//     delete p;
//     return 0;
// }