#include<iostream>
#include<string.h>
using namespace std;
const unsigned short int employeeSize = 100, empCounter = 0;
struct Address
{
    string phoneNo, email, country, city, poBox;
};
struct Name
{
    string firstName, middleName="ddd", lastName="lll";
};
struct experienceYears
{
    unsigned short int formerCompany, currentCompany;
};
struct Payroll
{
    unsigned short int emp_Id;
    Name fullName;
};
struct Employee
{
    unsigned short int emp_Id;
    Name fullName;
    Address address;
    experienceYears experienceYY;
    string gender;
    unsigned short int age;     //>65 years old
    string eduLevel;
    string department;
    float initialSalary, currentSalary, pensionSupport;     //salary
    int dOfEmployment, mOfEmployment, yOfEmployment;     //date of employment
    string paymentType;     //hourly, weekly, monthly
    string typeOfEmployee;
    bool isDeleted;
} employee[employeeSize];
void sortEmpInfo();

int main()
{
    
   
            employee[0].fullName.firstName= "mieraf";
            employee[1].fullName.firstName= "mieraf";
            employee[1].fullName.middleName="jejaw";
            employee[2].fullName.firstName= "mikyas";
            employee[3].fullName.firstName= "zelamm";
            employee[4].fullName.firstName= "natani";
            employee[5].fullName.firstName= "sam";
            employee[5].fullName.middleName="amani";
            employee[6].fullName.firstName= "sam";
            employee[6].fullName.middleName="solemon";
    
    
    
    sortEmpInfo();
    
    return 0;
}
void sortEmpInfo() {
    
    int n=7;
    char* names[n];
    char* Min= new char ('|');
    int* index=new int[n],h,length;
    string fullname;
    
   
    for(int i=0; i<n; i++) {
        length=sizeof(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        names[i] = new char[length + 1];
        fullname=(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        fullname.copy(names[i],length);
    }

    for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                  if(strcmp(Min,names[i])>=0) {
                         strcpy(Min,names[i]);
                         h=i;
                    }
              }
    
        Min[0]='}';
        index[k]=h;       
        names[h][0]='|';
         
    }

    for(int i=0; i<n; i++)
        cout <<i+1<<") "<<employee[index[i]].fullName.firstName<<" "<<employee[index[i]].fullName.middleName<< endl;
        
    for (int i = 0; i < n; i++){
       delete [] names[i];
       delete [] index; 
    }
       delete Min;
}



