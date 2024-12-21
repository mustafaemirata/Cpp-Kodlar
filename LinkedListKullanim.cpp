#include <iostream>
using namespace std;
struct Node
{
	int data; 
	Node* next;

};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList():head(nullptr){}
	void ekle(int value)
	{
		Node* newNode = new Node{ value, nullptr };
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void sil(int value)
	{
		if (head == nullptr)
		{
			cout << "Liste boş!" << endl;
			return;
		}
		if (head->data == value)
		{
			Node* sil = head;
			head = head->next;
			delete sil;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr && temp->next->data != value)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			cout << "Değer bulunamadı..." << endl;
			return;
		}
		Node* sil = temp->next;
		temp->next = temp->next->next;
		delete sil;
	}

	void yaz()
	{
		if (head == nullptr)
		{
			cout << "Liste bos." << endl;
			return;

		}
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
	~LinkedList()
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	
	}
};

int main()
{
	LinkedList list;
	list.ekle(10);
	list.ekle(80);
	list.ekle(175);
	list.ekle(991);
	cout << "Liste: " << endl;
	list.sil(80);
	list.yaz();
}