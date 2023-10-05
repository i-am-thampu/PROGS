#include<iostream>
using namespace std;
class book
{
private:
    string bk_name,auth_name;
    float price;

public:

    void data()
    {
        cout<<"\n\nBOOK NAME : ";
        cin>>bk_name;
        cout<<"\nAUTHOR NAME : ";
        cin>>auth_name;
        cout<<"\nBOOK PRICE : ";
        cin>>price;
    }
    void display()
    {

        cout<<"BOOK NAME    ";

        cout<<"AUTHOR NAME    ";

        cout<<"BOOK PRICE";
        cout<<"\n========================================";
        cout<<"\n";
        cout<<bk_name<<"\t\t"<<auth_name<<"\t\t"<<price;

    }

}B[100];

int main()
{
    int n,i;
    cout<<"ENTER TOTAL NO OF BOOKS : ";
    cin>>n;

    for(i=1;i<=n;i++)
    {
        B[i].data();
    }
    cout<<"\n\t\tDETAILS\n\n";
    for(i=1;i<=n;i++)
    {
        B[i].display();
    }
}
