#include <iostream>
using namespace std;

int globalVar = 10;

void display() {
    int localVar = 20;

    cout << "Yerel değişken (localVar): " << localVar << endl;
    cout << "Global değişken (globalVar): " << globalVar << endl;
}

int main() {
    cout << "Global değişken (main içi): " << globalVar << endl;

    display();

 

    return 0;
}
