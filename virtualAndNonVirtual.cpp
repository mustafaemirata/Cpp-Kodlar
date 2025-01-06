#include <iostream>
using namespace std;

class BaseV
{
    public:
    virtual void show()
    {
        cout << "Base class show() fonksiyonu yazıldı." << endl;
    }
};

class DerivedV : public BaseV
{
   void show() override {
       cout<< "Derived class show() fonksiyonu." << endl;
    }
};

//          Virtual tanımlamazsak ne olur?           //

class Base
{
    public:
    void show()
    {
        cout << "Virtualsiz base show() fonksiyonu." << endl;
    }
};

class Derived: public Base
{
    public:
    void show()  
    {
       cout<< "Virtualsiz Derived class show() fonksiyonu." <<endl;
    }
};

int main() 
{
    cout << "virtual tanımlandığında: " << endl;
    BaseV *obj = new DerivedV();
    obj->show();
    cout<<"----------"<<endl;
    Base *obje = new Derived();
    obje->show();
    Derived *der = new Derived();
    der->show();
}