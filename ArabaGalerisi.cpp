#include <iostream>
using namespace std;
int a = 100;


class Car
{
protected : 
	string sasiNumara;
protected:
	double fiyat;
public:
	string marka;

	void setSasiNo(const string& sasi)
	{
		sasiNumara = sasi;
	}

	void setFiyat(double p)
	{
		fiyat = p;
	}

	void setMarka(const string& brand)
	{
		marka = brand;
	}
	
	void printCarInfo() const
	{
		cout << "Marka: " << marka << ", Şasi Numarası: " << sasiNumara << ", Fiyat: " << fiyat << endl;
	}
};
class CarDealer : public Car
{
private:
	string galeriAdi;
	int stokArabaSayisi;

public:
	void setGaleriIsim(const string& name)
	{
		galeriAdi = name;
	}

	void stokAraba(int stock)
	{
		stokArabaSayisi = stock;
	}
	void printDealerInfo() const
	{
		cout << "Galerici İsmi: " << galeriAdi << endl;
		cout << "Stoktaki Araba Sayısı: " << stokArabaSayisi << endl;
		cout << "Satışta Araba: " << marka << ", Fiyat: " << fiyat << endl;
	}

	double getFiyat()
	{
		return fiyat;
	}
	string getSasi() const
	{
		return sasiNumara;
	}
	

};


int main()
{
	Car car;
	CarDealer cd; 
	car.setMarka("Toyota");
	cd.setSasiNo("1HGCM82633A123456");
	cd.setFiyat(25000);
	cd.setGaleriIsim("Oto Galeri");
	cd.stokAraba(5);

	cd.printCarInfo();
	cd.printDealerInfo();
	cout << "Araba Sasi No: " << cd.getSasi();



	

}

