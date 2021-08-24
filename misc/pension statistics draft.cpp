#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter The number of\nemployee or pension employee(retired): " ;
    cin>>n;
    unsigned short int age[n];
    string firstName[n], middleName, lastName;
//    int retur;
//    retur:
for(int i=0; i<n; i++)
{
    cout<<"Enter the employee Name: ";
    cin>>firstName[i];
    cout<<"Enter the employee age: ";
    cin>>age[i];
    if(age[i]>=60)
    {
        cout<<firstName[i]<<" is a pension employee(retired)\n ";
    }
    else
        cout<<firstName[i]<<" is regular employee\n";
}
//        goto retur;

    return 0;
}

