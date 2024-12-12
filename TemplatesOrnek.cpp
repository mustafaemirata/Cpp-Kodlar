#include <iostream>
using namespace std;
template<typename T>
T topla(T a, T b)
{
	return a + b;
}
// şablon fonksiyonu bir fonksiyon değildir.
// Fonksiyon üretme planıdır. Farklı metotlar oluşturmak yerine bu yöntem kullanılır.
int main()
{
	cout << topla(3, 4) << endl;
	cout << topla(13.64, 98.23) << endl;
	cout << topla(34.2f, 54.8f) << endl;
}
