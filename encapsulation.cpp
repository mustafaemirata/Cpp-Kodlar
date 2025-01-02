#include <iostream>
#include <string>
using namespace std;

class Calisan
{
private:
    string isim;      
    int yas;           
    double maas;       

public:
    void setIsim(const string &isimGiris)
    {
        isim = isimGiris;
    }

    string getIsim() const
    {
        return isim;
    }

    void setYas(int yasGiris)
    {
        if (yasGiris > 0) 
        {
            yas = yasGiris;
        }
        else
        {
            cout << "Hatalı yaş girildi!" << endl;
        }
    }

    int getYas() const
    {
        return yas;
    }

    void setMaas(double maasGiris)
    {
        if (maasGiris > 0) 
        {
            maas = maasGiris;
        }
        else
        {
            cout << "Hatalı maaş girildi!" << endl;
        }
    }

    double getMaas() const
    {
        return maas;
    }

    void bilgileriGoster() const
    {
        cout << "Isim: " << isim << ", Yas: " << yas << ", Maas: " << maas << endl;
    }
};

int main()
{
    Calisan calisan1;

    calisan1.setIsim("Ahmet Yılmaz");
    calisan1.setYas(30);
    calisan1.setMaas(7500.0);

    calisan1.bilgileriGoster();

    calisan1.setYas(-5);  
    calisan1.setMaas(-100);

    calisan1.bilgileriGoster();

    return 0;
}
