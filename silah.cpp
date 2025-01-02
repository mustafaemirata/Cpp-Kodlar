#include <iostream>
using namespace std;

class Silah
{
    public:
    string isim;
    int mermiKapasitesi;
    string renk;

    virtual void atesEt()
    {
        cout<<"pis pis"<<endl;
    }
};

class Ak47 : public Silah
{
    public:
        bool seriTek;
        int kayisUzunlugu;
        bool durbun;



    void atesEt()
    {
        cout<<"bom bom bom"<<endl;
    }
};

class Pistol: public Silah
{
    public:
        
        int kurmaKolUzunlugu;

    void atesEt()
    {
        cout<<"bam bam bam"<<endl;
    }
};

class M1 : public Silah
{
    public:
        bool seriTek;
        int kayisUzunlugu;
        int kurmaPozisyonu;

    void atesEt()
    {
        cout<<"bum bum bum"<<endl;
    }
};

void ates(Silah *silah)
{
    silah->atesEt();
}

int main()
{
    Ak47 ak47;
    Pistol pistol;
    M1 m1;

    ates(&ak47);
    ates(&pistol);
    ates(&m1);

    return 0;
}