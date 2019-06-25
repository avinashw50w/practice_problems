#include<iostream>
using namespace std;
class Shape
{
public:
void setWidth(int w)
{
width = w;
}
void setHeight(int h)
{
height = h;
}
Shape()
{
cout<<"creating shape \n";
}
protected:
int width;
int height;
};
class Rectangle: public Shape
{
public:
Rectangle(int h,int w)
{
cout<<"creating rectangle with attributes \n";
height = h;
width = w;
}
int getArea()
{
return (width * height);
}
};
int main(void)
{

Rectangle square(5,5);
cout << "Total area: " << square.getArea() << endl;
return 0;
}
