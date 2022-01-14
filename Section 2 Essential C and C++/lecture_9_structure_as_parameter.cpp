// **Call by Value******
#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};
void fun(struct Rectangle s){
    s.length=20;
    cout<<s.length<<endl<<s.breadth<<endl;
};

int main(){
    struct Rectangle r={10,5};
    fun(r);
    cout<<r.length<<endl<<r.breadth<<endl;    
    return 0;
}

// ********Call by refrence**************
// #include<iostream>
// using namespace std;

// struct Rectangle{
//     int length;
//     int breadth;
// };
// void fun(struct Rectangle &s){
//     s.length=20;
//     cout<<s.length<<endl<<s.breadth<<endl;
// };

// int main(){
//     struct Rectangle r={10,5};
//     fun(r);
//     cout<<r.length<<endl<<r.breadth<<endl;    
//     return 0;
// }

// // ****Call by address*******
// #include<iostream>
// using namespace std;

// struct Rectangle{
//     int length;
//     int breadth;
// };
// void fun(struct Rectangle *s){
//     s->length=20;
//     cout<<s->length<<endl<<s->breadth<<endl;
// };

// int main(){
//     struct Rectangle r={10,5};
//     fun(&r);
//     cout<<r.length<<endl<<r.breadth<<endl;    
//     return 0;
// }

// ******In Heap********
// #include<iostream>
// using namespace std;
// struct Rectangle
// {
//     int length;
//     int breadth;
// };
// struct Rectangle * fun(){
//     //Create a structure of Rectangle Kind in Heap
//     struct Rectangle *p;
//     p=new Rectangle;
//     p->length=50;
//     p->breadth=60;
//     return p;
    
// };
// int main(){
    
//     struct Rectangle * ptr=fun();
//     cout<<ptr->length<<endl<<ptr->breadth<<endl;
//     return 0;
// }