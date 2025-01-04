#include <iostream>
using namespace std;

// Soyut sınıf (Abstract class)
class Base {
protected: // Türeyen sınıflar erişebilir, dışarıdan erişim yok
    int protectedVar;

private: // Sadece bu sınıfta kullanılabilir
    int privateVar;

public:
    Base() : protectedVar(0), privateVar(0) {} // Varsayılan constructor
    virtual void display() const = 0;         // Pure virtual function (abstract class yapar)

    // Protected veya private değişkenlere erişim sağlayan public bir metot
    void setProtectedVar(int value) {
        protectedVar = value;
    }

    int getProtectedVar() const {
        return protectedVar;
    }
};

// Public kalıtım
class DerivedPublic : public Base {
public:
    void display() const override {
        cout << "DerivedPublic sınıfı, protectedVar: " << protectedVar << endl;
        // privateVar erişilemez: Hata verir
        // cout << "privateVar: " << privateVar << endl;
    }
};

// Protected kalıtım
class DerivedProtected : protected Base {
public:
    void display() const override {
        cout << "DerivedProtected sınıfı, protectedVar: " << protectedVar << endl;
        // privateVar erişilemez: Hata verir
        // cout << "privateVar: " << privateVar << endl;
    }

    // Public bir metot ile protectedVar'a erişim sağlanabilir
    void setProtected(int value) {
        setProtectedVar(value); // Base sınıfın public metodunu çağırmak serbest
    }
};

// Private kalıtım
class DerivedPrivate : private Base {
public:
    void display() const override {
        cout << "DerivedPrivate sınıfı, protectedVar: " << getProtectedVar() << endl;
        // privateVar erişilemez: Hata verir
        // cout << "privateVar: " << privateVar << endl;
    }

    void setProtected(int value) {
        setProtectedVar(value); // Base sınıfın public metodunu çağırmak serbest
    }
};

int main() {
    // Polimorfizm ile çalışma
    Base* obj1 = new DerivedPublic();
    obj1->setProtectedVar(10); // Public erişimle serbest
    obj1->display();

    DerivedPublic publicObj;
    publicObj.setProtectedVar(20); // Public erişimle serbest
    publicObj.display();

    DerivedProtected protectedObj;
    protectedObj.setProtected(30); // Public metoduyla dolaylı erişim serbest
    protectedObj.display();

    DerivedPrivate privateObj;
    privateObj.setProtected(40); // Public metoduyla dolaylı erişim serbest
    privateObj.display();

    // Base sınıfın public fonksiyonları DerivedProtected veya DerivedPrivate üzerinden çağrılamaz.
    // protectedObj.setProtectedVar(50); // Hata verir
    // privateObj.setProtectedVar(50);  // Hata verir

    delete obj1;

    return 0;
}
