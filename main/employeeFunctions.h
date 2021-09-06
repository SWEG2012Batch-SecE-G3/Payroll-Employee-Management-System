#include <iomanip>
#include<string.h>
const float salaryAdvPercent = 5, taxPercent = 15, pensionPercent = 50, overtimeConstant = 1.5;   //constant values for calculations
int n=0;    //used in sorting function
int* Index=new int[1];  //used in sorting function to hold sorted indices
/******************* Function Declaration *******************/

void sortEmpInfo(Employee employee[]);
void current_employee(Employee emp[]);
void insertEmployeeRecord(Employee employee[]);
void editEmployeeRecord(Employee employee[]);
void deleteEmployeeRecord(Employee employee[]);
void searchbyId(Employee lists[]);
void searchbyName(Employee lists[]);

/***********        Mieraf Jejew        ***************/
void current_employee(Employee emp[], int Index[])  //display information
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    system(displayTableScreenSize);
    cout<<"\t\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Current Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t******************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Salary"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employeeCounter; i++)
    {
        if(emp[i].age<65 && emp[i].isDeleted == false)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<emp[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<emp[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].department;
            cout <<emp[i].dOfEmployment<<"/"<<emp[i].mOfEmployment<<"/"<<setw(14)<<left<<emp[i].yOfEmployment;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.netPay;
            cout<<endl;

        }
    }
}

void sortEmpInfo(Employee employee[])   //sort function
{
    char* names[employeeCounter];
    char* Min= new char ('|');
    int temp,length,select;
    string fullname;

    //to enhance the performance
    if(employeeCounter==n)    //jumps the for loop to save memory and time if there is no change in the no of employees
        goto loop;
    else     //goes to the for loop to update the sorting algorithm
        n=employeeCounter;

    for(int i=0; i<n; i++)
    {
        length=sizeof(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        names[i] = new char[length + 1];
        fullname=(employee[i].fullName.firstName+employee[i].fullName.middleName+employee[i].fullName.lastName);
        fullname.copy(names[i],length);
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            if(strcmp(Min,names[i])>=0)
            {
                strcpy(Min,names[i]);
                temp=i;
            }
        }

        Min[0]='}';
        Index[k]=temp;
        names[temp][0]='|';

    }
loop:
    select = arrowMenu(sortMenu, 3);

    switch(select)
    {
    case 1: //sort by Name
        if(employeeCounter!=n)
        {
            for (int i = 0; i < employeeCounter; i++)
            {
                delete [] names[i];
            }
        }
        delete Min;
        current_employee(employee, Index);
        break;
    case 2: //sort by ID
        current_employee(employee);
        break;
    case 3: //back to previous
        return;
    }
}

/***********        Mikeyas Alemu        ***************/
void current_employee(Employee emp[])   //display information
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    system(displayTableScreenSize);
    cout<<"\t\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Current Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t******************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Salary"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employeeCounter; i++)
    {
        if(emp[i].age<65 && emp[i].isDeleted == false)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<emp[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<emp[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].department;
            cout <<emp[i].dOfEmployment<<"/"<<emp[i].mOfEmployment<<"/"<<setw(14)<<left<<emp[i].yOfEmployment;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.netPay;
            cout<<endl;

        }
    }
}

void former_Employees(Employee emp[])   //display former employee informations
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    cout<<"\n\t\t\t\t\t\t*****************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Former Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t*****************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Pension"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employeeCounter; i++)
    {
        if(emp[i].isDeleted == true)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.lastName;
            cout <<left<< setw(nameWidth) << setfill(separator)<<emp[i].age;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].address.city;
            cout<<left << setw(nameWidth) << setfill(separator)<<emp[i].address.phoneNo;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].address.poBox;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].department;
            cout <<emp[i].dOfEmployment<<"/"<<emp[i].mOfEmployment<<"/"<<setw(14)<<left<<emp[i].yOfEmployment;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].position;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.pension;
            cout<<endl;

        }
    }
}

void payrolldisplay(Employee emp[])     //display payroll data
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    system(displayTableScreenSize);
    cout<<"\t\t\t\t\t\t**********************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Payroll Information ******"<<endl;
    cout<<"\t\t\t\t\t\t**********************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Tax";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Overtime";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Gross Pay";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Others";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Net Pay"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    for(int i=0; i<employeeCounter; i++)
    {
        if(emp[i].isDeleted == false)
        {
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].emp_Id ;
            cout  <<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.firstName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.middleName;
            cout<<left<< setw(nameWidth) << setfill(separator)<<emp[i].fullName.lastName;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].department;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.tax;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.overtime;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.grossPay;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.otherExpenses;
            cout <<left << setw(nameWidth) << setfill(separator)<<emp[i].payroll.netPay<<endl;
        }
    }
}

/***********        Nahom Getachew        ***************/
void employee_staticReport(Employee employee[])   //statistical report
{
    struct
    {
        int NoMale=0,NoFemale=0;
        int count_fixed=0,count_con=0, T_emp=0;
        int high=0,low = 0,middle=0,Tsalary=0;
        int admin=0,finance=0,humanSource=0,labor=0,security=0;
        int intermediate=0, mid_level=0, senior=0, experience=0;
    } info;

    for(int i=0; i<employeeCounter; i++)
    {
        if(employee[i].isDeleted == false)
        {
            if(employee[i].gender=='M' || employee[i].gender=='m')
                info.NoMale++;
            else if(employee[i].gender=='F' || employee[i].gender=='f')
                info.NoFemale++;

            if(employee[i].typeOfEmployee=="Fixed")
                info.count_fixed++;
            else if(employee[i].typeOfEmployee=="Contractual")
                info.count_con++;
            if(employee[i].payroll.grossPay>=10000)
                info.high++;
            else if(employee[i].payroll.grossPay>=5000 && employee[i].payroll.grossPay<10000)
                info.middle++;
            else if(employee[i].payroll.grossPay<5000)
                info.low++;
            info.Tsalary+=employee[i].payroll.grossPay;
            info.experience=employee[i].experienceYY.currentCompany+employee[i].experienceYY.formerCompany;
            if(info.experience>=1 && info.experience<=4)
                info.intermediate++;
            else if(info.experience>=5 && info.experience<=8)
                info.mid_level++;
            else if(info.experience>=9)
                info.senior++;


            if(employee[i].department == "Admin")
                info.admin++;
            else if(employee[i].department == "Finance")
                info.finance++;
            else if(employee[i].department == "HR")
                info.humanSource++;
            else if(employee[i].department == "Labor")
                info.labor++;
            else if(employee[i].department == "Security")
                info.security++;
        }

    }
    cout<<"\t\tStatistical Data"<<endl;
    cout<<"\t\t----------------"<<endl;
    cout<<"Male employees are: "<<info.NoMale<<endl;
    cout<<"Female employees: "<<info.NoFemale<<endl;
    cout<<"\n----------------------------------\n";
    cout<<"Fixed employees: "<<info.count_fixed<<endl;
    cout<<"Contractual employees: "<<info.count_con<<endl;
    cout<<"Total employees: "<<info.count_fixed+info.count_con<<endl;
    cout<<"\n----------------------------------\n";
    cout<<"High paid employees(>=10000): "<<info.high<<endl;
    cout<<"Medium paid employees(between 5000 - 10000): "<<info.middle<<endl;
    cout<<"Low paid Employees are: "<<info.low<<endl;
    cout<<"Total money paid to employees: "<<info.Tsalary<<endl;
    cout<<"\n-----------------------------------\n";
    cout<<"Relative starter at company(1-4 years): "<<info.intermediate<<endl;
    cout<<"Intermediate experience at company(5-8 years): "<<info.mid_level<<endl;
    cout<<"Senior experience at company(>9 years): "<<info.senior<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Number of employee in Administration Department: "<<info.admin<<endl;
    cout<<"Number of employee in Finance Department: "<<info.finance<<endl;
    cout<<"Number of employee in Human Resources Department: "<<info.humanSource<<endl;
    cout<<"Number of employee in Labor Department: "<<info.labor<<endl;
    cout<<"Number of employee in Security Department: "<<info.security<<endl;

}

void Financial_staticReport()
{

    struct
    {
        int tax01=0,tax02=0,tax03=0,tax04=0,tax05=0, tax;
        int pension01=0,pension02=0,pension03=0,pension04=0,pension05=0, pension;
        int other01=0,other02=0,other03=0,other04=0,other05=0, other_expense;

    } info;

    for(int i=0; i<employeeSize; i++)
    {
        info.tax=employee[i].initialSalary*0.15;
        info.pension=employee[i].initialSalary*0.20;
        info.other_expense=employee[i].initialSalary*0.10;
        if(info.tax>=600&&info.tax<1650)
            info.tax01++;
        else if(info.tax>=1651&&info.tax<3200)
            info.tax02++;
        else if(info.tax>=3201&&info.tax<5250)
            info.tax03++;
        else if(info.tax>=5251&&info.tax<7800)
            info.tax04++;
        else if(info.tax>=7801)
            info.tax05++;

        if(info.pension>=600&&info.pension<1650)
            info.pension01++;
        else if(info.pension>=1651&&info.pension<3200)
            info.pension02++;
        else if(info.pension>=3201&&info.pension<5250)
            info.pension03++;
        else if(info.pension>=5251&&info.pension<7800)
            info.pension04++;
        else if(info.pension>=7801)
            info.pension05++;

        if(info.other_expense>=600&&info.other_expense<1650)
            info.other01++;
        else if(info.other_expense>=1651&&info.other_expense<3200)
            info.other02++;
        else if(info.other_expense>=3201&&info.other_expense<5250)
            info.other03++;
        else if(info.other_expense>=5251&&info.other_expense<7800)
            info.other04++;
        else if(info.other_expense>=7801)
            info.other05++;


    }
    cout<<"Platinum level Tax pay amount: "<<info.tax05<<endl;
    cout<<"Gold level Tax pay amount: "<<info.tax04<<endl;
    cout<<"Silver level Tax pay amount: "<<info.tax03<<endl;
    cout<<"Bronze level Tax pay amount: "<<info.tax02<<endl;
    cout<<"Lower level Tax pay amount: "<<info.tax01<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Very High pension: "<<info.pension05<<endl;
    cout<<"High pension: "<<info.pension04<<endl;
    cout<<"Middle level pension: "<<info.pension03<<endl;
    cout<<"small amount pension: "<<info.pension02<<endl;
    cout<<"Very small amount pension: "<<info.pension01<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Very High for expenses: "<<info.other05<<endl;
    cout<<"High for expenses: "<<info.other04<<endl;
    cout<<"Middle for expenses: "<<info.other03<<endl;
    cout<<"Low expenses: "<<info.other02<<endl;
    cout<<"Very low expenses: "<<info.other01<<endl;
}
/***********        Nahom Habtamu        ***************/
void insertEmployeeRecord(Employee employee[])  //insert employee record
{
    int how;
    cout<<"How many employees are you going to insert: ";
    cin>>how;
    how = how + employeeCounter;
    for(int i = employeeCounter; i<how; i++)
    {
        cout<<"Employee Information"<<endl<<endl;
        cout<<"Full Name"<<endl;
        cout<<"First Name: ";
        cin>>employee[i].fullName.firstName;
        cout<<"Middle Name: ";
        cin>>employee[i].fullName.middleName;
        cout<<"Last Name: ";
        cin>>employee[i].fullName.lastName;
        cout<<"Gender(M or F): ";
        cin>>employee[i].gender;
        cout<<"Age: ";
        cin>>employee[i].age;
        cout<<"Address"<<endl;
        cout<<"Phone: ";
        cin>>employee[i].address.phoneNo;
        cout<<"Email: ";
        cin>>employee[i].address.email;
        cout<<"Country:  ";
        cin>>employee[i].address.country;
        cout<<"City: ";
        cin>>employee[i].address.city;
        cout<<"P.O. Box: ";
        cin>>employee[i].address.poBox;
        cout<<"Education Level: ";
        cin>>employee[i].eduLevel;
        cout<<"Job Department: ";
        cin>>employee[i].department;
        cout<<"Initial Salary: ";
        cin>>employee[i].initialSalary;
        cout<<"Employee Position: ";
        cin>>employee[i].position;
        cout<<"Date of Employment: ";
        cin>>employee[i].dOfEmployment>>employee[i].mOfEmployment>>employee[i].yOfEmployment;
        cout<<"Salary Payment Type: ";
        cin>>employee[i].typeOfEmployee;
        cin.ignore();
        cout<<"Work Experience at former company(in Years): ";
        cin>>employee[i].experienceYY.formerCompany;
        cout<<"Work Experience at current company(in Years): ";
        cin>>employee[i].experienceYY.currentCompany;
        employee[i].payroll.grossPay = ((employee[i].experienceYY.currentCompany/salaryAdvPercent) * (salaryAdvPercent/100) * employee[i].initialSalary) + employee[i].initialSalary;

        employee[i].isDeleted = false;
        cout<<"\nPayroll Information"<<endl<<endl;
        cout<<"Overtime (in hours): ";
        cin>>employee[i].payroll.overtime;
        cout<<"Other Expenses: ";
        cin>>employee[i].payroll.otherExpenses;
        employee[i].payroll.tax = (taxPercent/100) * employee[i].payroll.grossPay;
        if(employee[i].age >= 65)
            employee[i].payroll.pension = (pensionPercent/100) * employee[i].payroll.grossPay;
        else
            employee[i].payroll.pension = 0;
        employee[i].payroll.netPay = employee[i].payroll.grossPay + (employee[i].payroll.overtime * overtimeConstant) - (employee[i].payroll.otherExpenses + employee[i].payroll.tax);
        employee[i].emp_Id = employeeCounter + 1;
        employeeCounter++;
        cout<<"Employee added. Press ENTER to continue"<<endl;
        system("pause>0");
        system("cls");
    }
}
void editEmployeeRecord(Employee employee[])    //edit record
{
    int id, ch;
    cout<<"Enter the id you're going to edit: ";
    cin>>id;
    for(int i = 0; i<employeeCounter; i++)
    {
        if(id == employee[i].emp_Id && employee[i].isDeleted == false)
        {
            system("cls");
            ch = arrowMenu(editMenu, 4);
            if(ch == 1)     //edit full name
            {
                cout<<"\nEditing Full Name"<<endl;
                cout<<"First Name: ";
                cin>>employee[i].fullName.firstName;
                cout<<"Middle Name: ";
                cin>>employee[i].fullName.middleName;
                cout<<"Last Name: ";
                cin>>employee[i].fullName.lastName;
                cout<<"\nEditing Complete! Press ENTER to continue"<<endl;
                return;
            }
            else if(ch == 2)    //edit address
            {
                cout<<"\nEditing Address"<<endl;
                cout<<"Phone: ";
                cin>>employee[i].address.phoneNo;
                cout<<"Email: ";
                cin>>employee[i].address.email;
                cout<<"Country:  ";
                cin>>employee[i].address.country;
                cout<<"City: ";
                cin>>employee[i].address.city;
                cout<<"P.O. Box: ";
                cin>>employee[i].address.poBox;
                cout<<"\nEditing Completed! Press ENTER to continue"<<endl;
                return;
            }
            else if(ch == 3)    //edit department
            {
                cout<<"\nEditing Department"<<endl;
                cout<<"Job Department: ";
                cin>>employee[i].department;
                cout<<"Position: ";
                cin>>employee[i].position;
                cout<<"\nEditing Completed! Press ENTER to continue"<<endl;
                return;
            }
            else if(ch == 4)    //back to previous
                return;
        }
    }
    cout<<"Error! Employee NOT found!"<<endl;
}

void deleteEmployeeRecord(Employee employee[])  //delete record
{
    int id;
    cout<<"Id: ";
    cin>>id;
    for(int i = 0; i<employeeCounter; i++)
    {
        if(id == employee[i].emp_Id && employee[i].isDeleted == false)
        {
            employee[i].isDeleted = true;
            cout<<"Record Deleted"<<endl;
            return;
        }
    }
    cout<<"No employee found!"<<endl;
}

/***********        Namus Shukra        ***************/
void current_employee(Employee emp)     //display information
{
    int nameWidth = 16, numWidth = 16;
    char separator = ' ';
    system(displayTableScreenSize);
    cout<<"\t\t\t\t\t\t******************************************"<<endl;
    cout<<"\t\t\t\t\t\t****** Current Employee Information ******"<<endl;
    cout<<"\t\t\t\t\t\t******************************************"<<endl<<endl;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"ID" ;
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"First Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Middle Name";
    cout<<left<< setw(nameWidth) << setfill(separator)<<"Last Name";
    cout <<left<< setw(nameWidth) << setfill(separator)<<"Age";
    cout  <<left<< setw(nameWidth) << setfill(separator)<<"City";
    cout<<left << setw(nameWidth) << setfill(separator)<<"Phone";
    cout <<left << setw(nameWidth) << setfill(separator)<<"PO Box";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Department";
    cout <<left << setw(nameWidth+2) << setfill(separator)<<"Date";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Position";
    cout <<left << setw(nameWidth) << setfill(separator)<<"Salary"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
    if(emp.age<65 && emp.isDeleted == false)
    {
        cout  <<left<< setw(nameWidth) << setfill(separator)<<emp.emp_Id ;
        cout  <<left<< setw(nameWidth) << setfill(separator)<<emp.fullName.firstName;
        cout<<left<< setw(nameWidth) << setfill(separator)<<emp.fullName.middleName;
        cout<<left<< setw(nameWidth) << setfill(separator)<<emp.fullName.lastName;
        cout <<left<< setw(nameWidth) << setfill(separator)<<emp.age;
        cout  <<left<< setw(nameWidth) << setfill(separator)<<emp.address.city;
        cout<<left << setw(nameWidth) << setfill(separator)<<emp.address.phoneNo;
        cout <<left << setw(nameWidth) << setfill(separator)<<emp.address.poBox;
        cout <<left << setw(nameWidth) << setfill(separator)<<emp.department;
        cout <<emp.dOfEmployment<<"/"<<emp.mOfEmployment<<"/"<<setw(14)<<left<<emp.yOfEmployment;
        cout <<left << setw(nameWidth) << setfill(separator)<<emp.position;
        cout <<left << setw(nameWidth) << setfill(separator)<<emp.payroll.netPay;
        cout<<endl;

    }
}

void searchbyName(Employee lists[])     //search by name
{
    string name1,name2,name3;
    cout<<"ENTER THE FULL NAME OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cout<<"First Name: ";
    cin>>name1;
    cout<<"Middle Name: ";
    cin>>name2;
    cout<<"Last Name: ";
    cin>>name3;
    for(int i = 0; i<name1.length(); i++)
        name1.at(i) = char(tolower(name1.at(i)));
    for(int i = 0; i<name2.length(); i++)
        name2.at(i) = char(tolower(name2.at(i)));
    for(int i = 0; i<name3.length(); i++)
        name3.at(i) = char(tolower(name3.at(i)));
    for (int i{}; i<employeeCounter; i++)
    {
        string fName=lists[i].fullName.firstName, mName=lists[i].fullName.middleName, lName=lists[i].fullName.lastName;
        for(int i = 0; i<fName.length(); i++)
            fName.at(i) = char(tolower(fName.at(i)));
        for(int i = 0; i<mName.length(); i++)
            mName.at(i) = char(tolower(mName.at(i)));
        for(int i = 0; i<lName.length(); i++)
            lName.at(i) = char(tolower(lName.at(i)));
        if(name1==fName && name2==mName && name3==lName)
        {
            current_employee(lists[i]);
            return;
        }
    }
    cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
}

void searchbyId(Employee lists[])      //search by ID
{
    unsigned short int idNum;
    cout<<"ENTER THE ID OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>idNum;
    for (int i=0; i<employeeCounter; i++)
    {
        if(lists[i].emp_Id==idNum)
        {
            current_employee(lists[i]);
            return;
        }
    }
    cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
}
