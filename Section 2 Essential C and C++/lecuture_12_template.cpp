#include <iostream>
using namespace std;

template<class T>
class Rectangle
{
private:
    T length;
    T breadth;

public:
    //We should Delcare first that we will use it
    //Constructor --> its is used to initalize our object made in main function i.e 'r'
    Rectangle(T l, T b);
    T area();
    T perimeter();
    void setLength(T l);
    void setBreadth(T b);
    T getLength();
    T getBreadth();
};

template<class T>
Rectangle<T>::Rectangle(T l, T b)
{
    length = l;
    breadth = b;
}
template<class T>
T Rectangle<T>::area()
{
    return length * breadth;
}

template <class T>
T Rectangle<T>::perimeter()
{
    return 2 * (length + breadth);
}

template <class T>
void Rectangle<T>::setLength(T l)
{
    length = l;
}
template <class T>
void Rectangle<T>::setBreadth(T b)
{
    breadth = b;
}
template<class T>
T Rectangle<T>::getLength()
{
    return length;
}
template <class T>
T Rectangle<T>::getBreadth()
{
    return breadth;
}

int main()
{
    Rectangle<int> r(10, 5);
    cout << "Area is " << r.area() << endl;
    cout << "Perimeter is " << r.perimeter() << endl;
    return 0;
}