#include<iostream>
using namespace std;
class emp
{
private:
    int empid,ns;
    string name, department;
public:
    void read()
    {
        cout<<"\n\nEnter name of employee : ";
        cin>>name;
        cout<<"\nEnter Employee ID of employee : ";
        cin>>empid;
        cout<<"\nEnter department : ";
        cin>>department;
        cout<<"\nEnter Net Salary : ";
        cin>>ns;
    }
    void display()
    {
        cout<<"Employee ID = "<<empid;
        cout<<"\nName = "<<name;
        cout<<"\nDepartment = "<<department;
        cout<<"\nNET SALARY = "<<ns;
        cout<<"\n\n";
    }
};
int main()
{
    int i,n;
    emp obj[100];
    cout<<"Enter no of employees : ";
    cin>>n;
    cout<<"\n";
    for(i=0;i<n;i++)
    {
        obj[i].read();
    }
    cout<<"\n\t\tDETAILS\n\n";
    for(i=0;i<n;i++)
    {
        obj[i].display();
    }
    return 0;
}
