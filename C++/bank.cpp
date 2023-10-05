#include <iostream>
#include<stdlib.h>
using namespace std;
class Bank
{
private:
    string name;
    long accnumber;
    long amount = 0;
    long tot = 0;
public:
    void setvalue()
    {
        cout <<"\nEnter name:";
        cin>>name;
        cout << "\nEnter Account number:";
        cin >> accnumber;
        cout << "\nEnter Balance:";
        cin >> tot;
    }
    void deposit()
    {
        cout << "\nEnter amount to be Deposited = ";
        cin >> amount;
        tot = tot + amount;
    }
    void showbal()
    {
        cout << "\nTotal balance is : " << tot;
    }
    void withdrawl()
    {
        int a, avai_balance;
        cout << "\nEnter amount to withdraw = ";
        cin >> a;
        avai_balance = tot - a;
        cout << "\nAvailable Balance : " << avai_balance;
    }
};
int main()
{
    Bank b;

    int choice;
    do {
        cout << "\t\t\n MENU\n\n";
        cout << "\t1. Enter name, Account number, Balance\n";
        cout << "\t2. Deposit Money\n";
        cout << "\t3. Show Total balance\n";
        cout << "\t4. Withdraw Money\n";
        cout << "\t-1. Exit\n";
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.deposit();
            break;
        case 3:
            b.showbal();
            break;
        case 4:
            b.withdrawl();
            break;
        }
    }while(choice!=-1);
}
