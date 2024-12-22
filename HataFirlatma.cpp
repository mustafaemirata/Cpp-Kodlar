#include <iostream>
using namespace std;
class Sinif
{
public: 
	int sayi1;
	int sayi2;
	int hesapla()
	{
		if (sayi2 == 0)
		{
			throw "Hatali islem yaptiniz: 0'a bolme islemi";
		}
		return sayi1 / sayi2;
	}
 };

int main()
{
	try
	{
		Sinif nes;
		nes.sayi1 = 10;
		nes.sayi2 = 0;
		cout << "Bolum: " << nes.hesapla() << endl;
	}
	catch(const char ex)
	{
		cout << ex << endl;
	}
}