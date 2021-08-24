#include <iostream>
using namespace std;
int num;
class employee
{
public:

    float currentSalary;
    string firstName, gender;
    unsigned short int experianceLevel;
    void emp_report();
};

int main()
{

    cout<<"Enter the number of employees: ";
    cin>>num;
    employee E[num];
    cin.ignore();
    for(int i=0; i<num; i++)
    {
        cout<<"Enter employee number "<<i+1<<" Name ";
        getline(cin, E[i].firstName);
        cout<<"Enter employee number "<<i+1<<" Gender ";
        cin>>E[i].gender;
        cout<<"Enter employee number "<<i+1<<" Salary ";
        cin>>E[i].currentSalary;
        cout<<"Enter employee number "<<i+1<<" Experience level ";
        cin>>E[i].experianceLevel;
        cin.ignore();
        cout<<"\n----------------------------------------------------\n";
    }
    cout<<"Number of employee| Name  | Gender | Salary | Experience level(per year)  |\n";
    for(int i=0; i<num; i++)
    {
        cout<<" \t "<<i+1<<"  |\t  ";
        E[i].emp_report();
        exit;
    }

    return 0;
}
void employee :: emp_report()
{

    cout<<firstName<<"  |  ";
    cout<<gender<<"  |  ";
    cout<<currentSalary<<"  |  ";
    cout<<experianceLevel<<"  |  \n";

}
