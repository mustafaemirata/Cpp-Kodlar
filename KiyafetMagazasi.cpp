#include <iostream>
using namespace std;

class Urun
{
protected:
	string urunAdi;
	double fiyat;

public:
	Urun(string adi, double fiyati) :urunAdi(adi), fiyat(fiyati)
	{
		cout << "Urun olusturuldu. " << urunAdi << ", Fiyati: " << fiyat << " TL" << endl;
	}

	void urunBilgisi()
	{
		cout << "Urun Adi: " << urunAdi << endl;
		cout << "Urun Fiyati: " << fiyat << endl;
	}
};

class Kiyafet : public Urun
{
private:
	string beden;
	string kategori;

public:
	Kiyafet(string adi, double fiyati, string bedeni, string kategorisi) :Urun(adi, fiyati), beden(bedeni), kategori(kategorisi)
	{
		cout << "Kiyafet detaylari eklendi: \n" << "Kategorisi: " << kategori << "\nBedeni: " << beden << endl;
	}

	void kiyafetBilgisi()
	{
		urunBilgisi();
		cout << "Kategori: " << kategori << endl;
		cout << "Fiyat: " << fiyat << endl;
	}
};

int main()
{
	Kiyafet kiyafet("Kot Pantolon", 1200.0,"M","Pantolon");
	cout << "\nKiyafet Bilgisi: " << endl;
	kiyafet.kiyafetBilgisi();
}