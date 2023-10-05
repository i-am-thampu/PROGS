#include<iostream>
using namespace std;
class stud
{
private:
    int roll,m1,m2,m3,m4,m5;
    string name;
public:
        void read()
        {
            cout<<"\nEnter name : ";
            cin>>name;
            cout<<"Enter Roll no : ";
            cin>>roll;
            cout<<"Enter Marks of 1st Subject : ";
            cin>>m1;
            cout<<"Enter Marks of 2nd Subject : ";
            cin>>m2;
            cout<<"Enter Marks of 3rd Subject : ";
            cin>>m3;
            cout<<"Enter Marks of 4th Subject : ";
            cin>>m4;
            cout<<"Enter Marks of 5th Subject : ";
            cin>>m5;
        }
        void display()
        {
            cout<<"\nRoll no = "<<roll;
            cout<<"\nName = "<<name;
            cout<<"\nTotal Marks = "<<m1+m2+m3+m4+m5;
            cout<<"\n**********************************************\n";
        }
};
int main()
{
    int n,i;
    stud obj[100];
    cout<<"Enter no of students : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        obj[i].read();
    }
    for(i=0;i<n;i++)
    {
        obj[i].display();
    }
    return 0;
}
