#include <iostream>
using namespace std;

int pointerGonder(int *a, int *b)
{
    *a += 1; 
    *b += 2; 
    return *a + *b;
}

int referanGOnder(int &a, int &b)
{
    a *= 2; 
    b *= 3; 
    return a + b;
}

int valueGonder(int a, int b)
{
    a -= 1; 
    b -= 2; 
    return a + b;
}

int sadeDeneme(int x, int y)
{
    x -= 4;
    y -= 7;
    return x + y;
}
int main(void)
{
    int x = 5, y = 10;
    int deger1 = 98, deger2 = 55;

    cout << "Başlangıç değerleri: x = " << x << ", y = " << y << endl;
    cout << "Pointer ile çağrı sonucu: " << pointerGonder(&x, &y) << endl;
    cout << "Pointer sonrası: x  = " << x << ", y = " << y << endl;

    cout << "Referans ile çağrı sonucu: " << referanGOnder(x, y) << endl;
    cout << "Referans sonrası: x = " << x << ", y = " << y << endl;

    cout << "Değer ile çağrı sonucu: " << valueGonder(x, y) << endl;
    cout << "Değer sonrası: x = " << x << ", y = " << y << endl;

    cout << "-*************************************" << endl;
    cout << "Sade Deneme çağrı sonucu: " << sadeDeneme(deger1, deger2) << endl;
    cout << "Saded deneme fonksiyonu sonrası deger1 değeri: " << deger1 << ", deger2 değeri: " << deger2 << endl;

    return 0;
}
