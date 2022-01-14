#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
};

int LinearSearch(struct Array *ar, int key)
{
    for (int i = 0; i < ar->length; i++)
    {
        if (key == ar->A[i])
        {
            swap(&ar->A[i],&ar->A[i-1]);
            return (i-1);
        }
    }
    return -1 ;
}; 

void Display(struct Array ar)
{
    int i;
    for (i = 0; i < ar.length; i++)
    {
        cout << ar.A[i] << " ";
    }
}

int main()
{
    struct Array ar = {{2, 3, 4, 5, 6}, 10, 5};
    cout<<LinearSearch(&ar, 5)<<endl;  
    Display(ar);
    return 0;
}