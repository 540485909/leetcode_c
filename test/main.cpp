#include <iostream>
using namespace std;

struct Base1
{
    int x;
    Base1(int x);
};

struct Base2
{
    int x;
    Base2(int x);
};

struct Derived:public Base1, public Base2
{
    int x;
    Derived(Base1& a, Base2& b);
};
Base1::Base1(int x){
	this->x = x;
}
Base2::Base2(int x){
	this->x = x;
}
Derived::Derived(Base1& a, Base2& b):Base1(a.x),Base2(b.x){
	this->x = Base1::x + Base2::x;//  derived class include all elements of all base class except construct class and destruct class
	// base classes has the same attribute we need class::attribute to access it
}
//请实现Base1，Base2, Derived的构造函数

int main()
{
	int x, y;
	cin >> x >> y;
	Base1 a(x);
	Base2 b(y);
	Derived d(a, b);
	cout << d.Base1::x << "+" << d.Base2::x << "=" << d.x << endl;
	return 0;
}
