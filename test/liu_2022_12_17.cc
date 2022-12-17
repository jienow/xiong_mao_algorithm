#include<iostream>
using namespace std;
class base
{
public:
	int a;
protected:
	int b;
private:
	int c;
	static int count;
public:
	base(int _a, int _b, int _c)
	{
		a = _a;
		b = _b;
		c = _c;
		cout << "constructing base" << endl;
		count++;
	}
	~base()
	{
		cout << "destructing base" << endl;
		count--;
	}
	void print()
	{
		cout << "a=" << a << endl << "b=" << b << endl << "c=" << c << endl;
	}
	static int statistic()
	{
		return count;
	}
};
int base::count = 0;

class derived1 :public base
{
public:
	derived1(int x1, int x2, int x3, int x4) :base(x1, x2, x3)
	{
		d1 = x4;
		cout << "constructing derived1" << endl;
	}
	~derived1()
	{
		cout << "destructing derived1" << endl;
	}

private:
	int d1;
};

class derived2 :protected base
{
public:
	derived2(int x1, int x2, int x3, int x4) :base(x1, x2, x3)
	{
		d2 = x4;
		cout << "constructing derived2" << endl;
	}
	~derived2()
	{
		cout << "destructing derived2" << endl;
	}

private:
	int d2;
};
class derived3 :private base
{
public:
	derived3(int x1, int x2, int x3, int x4) :base(x1, x2, x3)
	{
		d3 = x4;
		cout << "constructing derived3" << endl;
	}
	~derived3()
	{
		cout << "destructing derived3" << endl;
	}

private:
	int d3;
};


int main()
{
	base a1(1, 2, 3);
	a1.statistic();
	a1.print();
	derived1 a2(4, 5, 6, 7);
	a2.statistic();//公有继承方式下，基类的公有成员变为
	//派生类的公有成员，保护成员变为派生类的保护成员，私有成员不可被继承
	a2.print();
	derived2 a3(8, 9, 10, 11);
	/*a3.statistic();
	a3.print();保护继承方式下，基类的公有成员与
	保护成员变为派生类的保护成员，基类的所有成员均不可访问，私有成员不可被继承*/
	derived3 a4(12, 13, 14, 15);
	/*a4.statistic();
	a4.print();私有继承方式下，基类的公有成员与保护成员变为
	派生类的私有成员，基类的所有成员均不可访问，私有成员不可被继承*/

	system("pause");
	return 0;
}