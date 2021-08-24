#include <iostream>
#include <iomanip>
using namespace std;
unsigned short int emp_Id;
string firstName, middleName, lastName;     //full name
string phoneNo, email, country, city, poBox;    //address
string gender;
unsigned short int age;
string eduLevel;
string department;
float initialSalary, currentSalary;     //salary
int dOfEmployment, mOfEmployment, yOfEmployment;     //date of employment
string paymentType;     //hourly, weekly, monthly
unsigned short int experianceLevel;     //measured in years
string typeOfEmployee;      //fixed or contractual

//Payroll Details
float paymentPer;
float overtimeHours;
float grossPay;
float tax;
float pension;
float netPay;

unsigned numEmployee{};

struct employee{
    string firstName, middleName, lastName;
    unsigned short int emp_Id;
};

void searchbyName(employee lists[]){
    string name1,name2,name3;
    cout<<"ENTER THE NAME OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>name1>>name2>>name3;
    int num=0;
    for (int i{}; i<numEmployee; i++){
    if(name1==lists[i].firstName||name2==lists[i].middleName||name3==lists[i].lastName) {
            num++;
    }
    }

    if(num==0)
    {
        cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
    }
    else
    {
        cout<<"\n"<<"EMPLOYEE FOUND."<<"\n";
    }
}

void searchbyId(employee lists[]){
    unsigned short int idNum;
    cout<<"ENTER THE ID OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>idNum;
    int num=0;
    for (int i{}; i<numEmployee; i++){
    if(lists[i].emp_Id==idNum){
            num++;
    }
    }

    if(num==0)
    {
        cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
    }
    else
    {
        cout<<"\n"<<"EMPLOYEE FOUND."<<"\n";
    }
}

int main(){
    unsigned employeeNum=0;
    cout<<"ENTER THE NUMBER OF EMPLOYEES: ";
    cin>>employeeNum;
    numEmployee=employeeNum;
    employee persons[employeeNum]={"Namus","Shukra","Hulkero",01};
    cout<<"\n"<<setw(12)<<":::::SEARCH MENU:::::"<<setw(12)<<"\n";
    cout<<"\n"<<setw(12)<<"CHOOSE SEARCHING METHODS"<<setw(12)<<"\n";
    int choice;
    cout<<"1.SEARCH BY NAME."<<"\n";
    cout<<"2.SEARCH BY ID."<<"\n";
    cin>>choice;
    switch (choice){
    case 1:searchbyName(persons);
        break;

    case 2:searchbyId(persons);
        break;

    default:
        cout<<"INVALID CHOICE."<<"\n";
        break;
    }
    return 0;
}
