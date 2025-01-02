#include <iostream>
using namespace std;

class Sekil
{
    protected:
    int konum=-23;
public:
    virtual void ciz() = 0;
    virtual void hareket() 
    {
        cout<<"Sekil hareket etti."<<endl;
    }

    virtual int konumGetir() 
    {
        return konum;
    }
   

    void konumAyarla(int konum)
    {
        this->konum = konum;
    }

};

class cizimMetodu
{
public:
    void sekilCiz(Sekil *sekil)
    {
        cout << "Cizim Metodu" << endl;
        sekil->ciz();
    }
    
}; // <-- Burada noktalı virgül olmalı

class Kare : public Sekil
{
public:
    void ciz()
    {
        cout << "Kare Cizildi" << endl;
    }
    void hareket()
    {
        konum+=10;
        cout << "Kare yeni konumunda:"<<konum << endl;
    }
};

int main()
{
    Kare kare;
    cizimMetodu modul;

    modul.sekilCiz(&kare);
    kare.hareket();
    return 0;
}
