//Using :Loops

#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array ar)
{
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.A[i] << " ";
    }
};

int BinarySeacrh(struct Array ar, int key)
{
    int l, h, mid;
    l = 0;
    h = ar.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == ar.A[mid])
        {
            return mid;
        }
        else if (key < ar.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    struct Array ar = {{2, 3, 4, 5, 6}, 10, 5};
    cout << BinarySeacrh(ar, 6)<<endl;
    Display(ar);
    return 0;
}


//Using :Recursion

// #include <iostream>
// using namespace std;

// struct Array
// {
//     int A[10];
//     int size;
//     int length;
// };

// void Display(struct Array ar)
// {
//     for (int i = 0; i < ar.length; i++)
//     {
//         cout << ar.A[i] << " ";
//     }
// };

// int BinarySearch( int a[], int l,int h,int key)
// {
//     int mid;
//     if(l<=h){
//         mid=(l+h)/2;
//         if(key==a[mid]){
//             return mid;
//         }
//         else if(key<a[mid]){
//             return BinarySearch(a,l,mid-1,key);
//         }
//         else{
//             return BinarySearch(a,mid+1,h,key);
//         }
//     }
//     return -1;
    
// };

// int main()
// {
//     struct Array ar = {{2, 3, 4, 5, 6}, 10, 5};
//     cout << BinarySearch(ar.A, 0, ar.length-1 ,4)<<endl;
//     Display(ar);
//     return 0;
// }
