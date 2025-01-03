#include <iostream>
using namespace std;

class HavaSavunmasi
{
private:
	string isim;
	int yapimYili;

public:

	HavaSavunmasi(string isim, int yil): isim(isim),yapimYili(yil){}
	virtual void ses() = 0;

	virtual void bilgiVer()
	{
		cout << "Sistemin ismi= " << isim << endl;
		cout << "Sistemin yapim yili= " << yapimYili << endl;
	}


	virtual ~HavaSavunmasi() 
	{
		cout << "HavaSavunmasi yikici cagirildi." << endl;
	}
};

class Ucak : public HavaSavunmasi
{
public:
	Ucak(string isim, int yapimYili):HavaSavunmasi(isim, yapimYili){}
	void bilgiVer() 
	{
		cout << "Ucak Bilgisi:" << endl;
		HavaSavunmasi::bilgiVer(); 
	}
	~Ucak()
	{
		cout << "Ucak destructor cagirildi." << endl;
	}

	void ses() override
	{
		cout << "Ucak sesi: Vuuuu!" << endl;
	}
};

int main()
{
	Ucak ucak1("KIZIL ELMA", 2011);
	ucak1.ses();
	ucak1.bilgiVer();

}