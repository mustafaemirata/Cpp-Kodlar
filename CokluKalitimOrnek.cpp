#include <iostream>
using namespace std;

class a
{
	int x;
public:
	int f1()
	{
		return x = 10;
	}
};

class b
{
	int y;
public:
	int f2()
	{
		return y = 310;
	}
};

class c : public a, public b
{
	int z;
public:
	int f3()
	{
		return z = 17;
	}
};

int main()
{
	c nesne;
	cout << "f1 sonucu: " << nesne.f1() << endl;
	cout << "f2 sonucu: " << nesne.f2() << endl;
	cout << "f3 sonucu: " << nesne.f3() << endl;

}
