#include <iostream>
using namespace std;

template <typename T>
class ATM
{
private:
	T bakiye;
public:
	ATM(T baslangicBakiyesi):bakiye(baslangicBakiyesi){}

	void paraCek(T miktar)
	{
		// ve
		if (miktar > 0 && miktar <= bakiye)
		{
			bakiye -= miktar;	
			cout << miktar << " TL cekildi. Yeni Bakiye: " << bakiye << endl;
		}
		else
		{
			cout << "Hatali islem" << endl;
		}
	}

	void paraYatir(T miktar)
	{
		if (miktar > 0)
		{
			bakiye += miktar;
			cout << miktar << " TL eklendi. Yemi Bakiye: " << bakiye << endl;
		}
		else
		{
			cout << "Hatali islem..." << endl;
		}
	}

	void bakiyeSorgula()
	{
		cout << "Mevcut Bakiye: " << bakiye << " TL." << endl;
	}
};

int main()
{
	ATM<int> intATM(1000);
	intATM.paraCek(356);
	intATM.paraYatir(561);
	intATM.bakiyeSorgula();
	cout << "*******************" << endl;

	ATM<double> doubAtm(2300.54);

	doubAtm.paraCek(102.53);
	doubAtm.paraYatir(199.131);
	doubAtm.bakiyeSorgula();
}
