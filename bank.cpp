#include <iostream>
#include <string>
#include <stdexcept> // Hata yönetimi için gerekli
using namespace std;

// Soyut sınıf
class BankAccount
{
protected:
    string accountHolderName; // Hesap sahibinin adı
    double balance;           // Bakiye

public:
    BankAccount(string name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {}

    // Saf sanal fonksiyon
    virtual void showAccountDetails() = 0;

    double getBalance() const { return balance; }

    virtual void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument("Yatırılacak miktar pozitif olmalıdır.");
        }
        balance += amount;
        cout << "Yatırılan miktar: " << amount << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw runtime_error("Yetersiz bakiye!");
        }
        balance -= amount;
        cout << "Çekilen miktar: " << amount << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(string name, double initialBalance, double rate)
        : BankAccount(name, initialBalance), interestRate(rate) {}

    void showAccountDetails() override
    {
        cout << "Vadeli Hesap Sahibi: " << accountHolderName << endl;
        cout << "Bakiye: " << balance << endl;
        cout << "Faiz Oranı: " << interestRate << "%" << endl;
    }

    void applyInterest()
    {
        balance += balance * (interestRate / 100);
        cout << "Faiz uygulandı. Yeni bakiye: " << balance << endl;
    }
};

class CurrentAccount : public BankAccount
{
public:
    CurrentAccount(string name, double initialBalance)
        : BankAccount(name, initialBalance) {}

    void showAccountDetails() override
    {
        cout << "Vadesiz Hesap Sahibi: " << accountHolderName << endl;
        cout << "Bakiye: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            throw runtime_error("Vadesiz hesaplarda overdraft izin verilmez!");
        }
        balance -= amount;
        cout << "Vadesiz hesaptan çekilen miktar: " << amount << endl;
    }
};

int main()
{
    try
    {
        SavingsAccount savings("Alice", 5000, 3.5);
        savings.showAccountDetails();
        savings.deposit(2000);
        savings.applyInterest();
        savings.withdraw(1000);
        cout << "Vadeli Hesap Bakiye: " << savings.getBalance() << endl;
        cout << "---------------------------------" << endl;

        CurrentAccount current("Bob", 3000);
        current.showAccountDetails();
        current.deposit(1500);
        current.withdraw(4000);
        cout << "Vadesiz Hesap Bakiye: " << current.getBalance() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Hata: " << e.what() << endl;
    }

    return 0;
}
