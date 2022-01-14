#include <iostream>
using namespace std;

// :: Scope resolution operator
class Rectangle
{
private:
    int length;
    int breadth;

public:
    //We should Delcare first that we will use it
    //Constructor --> its is used to initalize our object made in main function i.e 'r'
    Rectangle(int l, int b);
    int area();
    int perimeter();
    void setLength(int l);
    void setBreadth(int b);
    int getLength();
    int getBreadth();
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}
void Rectangle::setLength(int l)
{
    length = l;
}
void Rectangle::setBreadth(int b)
{
    breadth = b;
}
int Rectangle::getLength()
{
    return length;
}
int Rectangle::getBreadth()
{
    return breadth;
}

int main()
{
    Rectangle r(10, 5);
    cout << "Area is " << r.area() << endl;
    cout << "Perimeter is " << r.perimeter() << endl;
    return 0;
}