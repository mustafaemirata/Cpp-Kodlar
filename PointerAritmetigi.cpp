#include <iostream>
using namespace std;
int main()
{

	int arr[7] = { 2,6,99,654,-1,84,0 };
	cout << arr << endl;
	int* ptr;
	ptr = arr;
	cout << ptr << endl;
	//Dizinin ilk değerini yazdırır.
	cout << *ptr << endl;
	//Dizinin ikinci değerini yazdırır.
	cout << *(ptr + 1) << endl;

	//Her elemanı yazdırır.
	for (int i = 0; i < 7; i++)
	{
		cout << "*ptr" << endl;
		ptr++;
	}

}

