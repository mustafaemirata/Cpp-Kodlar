#include <iostream>
using namespace std;

template <class T>
class StackNode
{
public:
    T data;
    StackNode<T>* sonra;
    StackNode(T value) : data(value), sonra(nullptr) {}
};

template <class T>
class Stack
{
private:
    StackNode<T>* top;

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (top)
        {
            pop();
        }
    }

    void push(T value)
    {
        StackNode<T>* newNode = new StackNode<T>(value);
        newNode->sonra = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack boş.\n";
            return;
        }
        StackNode<T>* temp = top;
        top = top->sonra;
        delete temp;
    }

    void listele()
    {
        if (isEmpty())
        {
            cout << "Stack boş.\n";
            return;
        }
        StackNode<T>* current = top;
        while (current)
        {
            cout << current->data << endl;
            current = current->sonra;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main()
{
    Stack<int>sayiStack;
    sayiStack.push(120);
    sayiStack.push(40);
    sayiStack.push(77);
    sayiStack.push(2);
    sayiStack.push(16);

    cout << "************************\n";
    sayiStack.listele();

    sayiStack.pop();
    cout << "************************\n";
    sayiStack.listele();

    Stack<char> karakterStack;
    karakterStack.push('e');
    karakterStack.push('m');
    karakterStack.push('i');
    karakterStack.push('r');

    cout << "************************\n";
    karakterStack.listele();

    karakterStack.pop();
    cout << "************************\n";
    karakterStack.listele();
    cout << "************************\n";

    return 0;
}
    