  // *******Array Created in Heap**********

// #include <iostream>
// using namespace std;

// int main()
// {
//     //Making memory in Heap through pointer P
//     int *p;
//     p = new int[5]; //It create an array of 5 integer in Heap
//     p[0]=4;
//     p[1]=58;
//     p[2]=7;
//     p[3]=89;
//     p[4]=47;
//     for(int i=0;i<5;i++){
//         cout<<p[i]<<endl;
//     }
//     delete[] p; //We shloud always free the memory in Heap that we created
//     return 0;
// }


  // *******Array Created in Stack**********
#include<iostream>
using namespace std;

int main(){
  
    int A[5]={6,5,7,8,14};
    int *p;//Pointer Delecration
    p=A; //we did not have to write &A for array as A itself is an address
    for (int i = 0; i < 5; i++)
    {
        //Here Pointer--> p will act as name of array i.e--> A
        cout<<A[i]<<endl;
        cout<<p[i]<<endl;
    }
    
    return 0;
}


// ****Size of a pointer is independent of its data type like int, float,double*******

// #include<iostream>
// using namespace std;

// struct Reactangle{
//     int length;
//     int breadth;
// };

// int main(){
//     int *p1;
//     char *p2;
//     float *p3;
//     double *p4;
//     struct Reactangle *p5;

//     cout<<sizeof(p1)<<endl;
//     cout<<sizeof(p2)<<endl;
//     cout<<sizeof(p3)<<endl;
//     cout<<sizeof(p4)<<endl;
//     cout<<sizeof(p5)<<endl;

//     return 0;
// }