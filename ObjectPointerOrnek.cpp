#include <iostream>
using namespace std;

class Employee
{
	int empId;
	string empName;
	public:
	Employee(){}
	Employee(int id, string isim)
	{
		empId = id;
		empName = isim;
	}
	void display()
	{
		cout << "Isim: " << empName << endl;
		cout << "Id No: " << empId << endl;
	}
};

int main()
{
	Employee* obj = new Employee[2]{ Employee(101,"Mustafa"),Employee(202,"Eymen") };
	
	obj->display();
	//obj elemanınınn bir sonraki nesneye geçebilmesi için bu kullanılır.
	(++obj)->display();
	delete [] obj;
}
