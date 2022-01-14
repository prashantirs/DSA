#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};
void initalize(struct Rectangle *p, int l, int b)
{
    p->length = l;
    p->breadth = b;
};

int area(struct Rectangle r)
{
    int c;
    return c = r.length * r.breadth;
};

int main()
{
    Rectangle r = {0, 0};
    cout << "Enter the Length and breadth";
    cin >> r.length >> r.breadth;
    initalize(&r, r.length, r.breadth);
    int ar = area(r);
    cout << ar;
    return 0;
}