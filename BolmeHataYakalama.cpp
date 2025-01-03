#include <iostream>
using namespace std;
int main()
{
	int pay = 5;
	int payda = 0;

	try
	{
		if (payda == 0)
		{
			throw payda;
		}
		else
		{
			int sonuc = pay / payda;
			cout << "Sonuc: " << sonuc << endl;
		}
	
	}
	catch (int hata)
	{
		cout << "Sifira bolme hatasi!" << endl;
	}
}