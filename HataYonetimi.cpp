#include <iostream>
using namespace std;

class Ornekler
{
public:
	double bolme(int a, int b)
	{
		try
		{
			if (a < 0 || b < 0) throw 5;
			if (b == 0) throw 1;
			else
			{
				return a / b;
			}
		}
		catch (int deger)
		{
			if (deger == 1)
			{
				cout << "0'a bolme hatasi." << endl;
				
			}
			if (deger == 5)
			{
				cout << "Lutfen negatif sayilari bolmeyiniz." << endl;
				
			}
		}
	}
};

int main()
{
	Ornekler ornek;
	ornek.bolme(-53, 0);
}