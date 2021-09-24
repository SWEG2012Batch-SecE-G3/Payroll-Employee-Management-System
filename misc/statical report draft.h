#include <iomanip>
#include<string.h>
int initial=0;
const float salaryAdvPercent = 5, taxPercent = 15, pensionPercent = 25, overtimeConstant = 1.5, otherExp = 20;   //constant values for calculations
int holdCounter=0;    //hold the last employee number
int* Index=new int[employee.size()];  //used in sorting function to hold sorted indices
/***********        Nahom Getachew        ***************/
void employee_staticReport()   //statistical report
{
    struct
    {
        int NoMale = 0, NoFemale = 0;
        int count_fixed = 0, count_con = 0, totalEmp = 0;
        int high = 0, low = 0, middle = 0, totalSalary = 0;
        int admin = 0, finance = 0, humanSource = 0, labor = 0, security = 0;
        int starter = 0, mid_level = 0, senior = 0, experience = 0;
    } info;

    for(int i=0; i<employee.size(); i++)
    {
        if(employee[i].isDeleted == false)
        {
            //gender
            if(employee[i].gender=='M' || employee[i].gender=='m')
                info.NoMale++;
            else if(employee[i].gender=='F' || employee[i].gender=='f')
                info.NoFemale++;
            info.totalEmp++;
            //type of employee
            if(employee[i].typeOfEmployee=="Fixed")
                info.count_fixed++;
            else if(employee[i].typeOfEmployee=="Contractual")
                info.count_con++;
            //payment level
            if(employee[i].payroll.grossPay >= 10000)
                info.high++;
            else if(employee[i].payroll.grossPay >= 5000 && employee[i].payroll.grossPay<10000)
                info.middle++;
            else if(employee[i].payroll.grossPay < 5000)
                info.low++;
            info.totalSalary += employee[i].payroll.grossPay;
            //experience level
            info.experience = employee[i].experienceYY.currentCompany + employee[i].experienceYY.formerCompany;
            if(info.experience>=1 && info.experience<=4)
                info.starter++;
            else if(info.experience>=5 && info.experience<=8)
                info.mid_level++;
            else if(info.experience>=9)
                info.senior++;
            //department
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
    cout<<"******************************************"<<endl;
    cout<<"****** Employee Statistical Report ******"<<endl;
    cout<<"******************************************"<<endl<<endl;
    cout<<"Male employees: "<<info.NoMale<<endl;
    cout<<"Female employees: "<<info.NoFemale<<endl;
    cout<<"Total employees: "<<info.totalEmp<<endl;
    cout<<"\n----------------------------------\n";
    cout<<"Fixed employees: "<<info.count_fixed<<endl;
    cout<<"Contractual employees: "<<info.count_con<<endl;
    cout<<"\n----------------------------------\n";
    cout<<"Low paid Employees are(<5000 ETB): "<<info.low<<endl;
    cout<<"Medium paid employees(5000-9999 ETB): "<<info.middle<<endl;
    cout<<"High paid employees(>=10000 ETB): "<<info.high<<endl;
    cout<<"Total money paid to employees: "<<info.totalSalary<<endl;
    cout<<"\n-----------------------------------\n";
    cout<<"Relative Starter at company(1-4 years): "<<info.starter<<endl;
    cout<<"Intermediate experience at company(5-8 years): "<<info.mid_level<<endl;
    cout<<"Senior experience at company(>9 years): "<<info.senior<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Number of employee in Administration Department: "<<info.admin<<endl;
    cout<<"Number of employee in Finance Department: "<<info.finance<<endl;
    cout<<"Number of employee in Human Resources Department: "<<info.humanSource<<endl;
    cout<<"Number of employee in Labor Department: "<<info.labor<<endl;
    cout<<"Number of employee in Security Department: "<<info.security<<endl;
    return;
}

void financial_staticReport()
{

    struct
    {
        int bronze=0, gold=0, platinum=0, tax;
        int lowPen=0, medPen=0, highPen=0, pension=0;
        int lowSpend=0, medSpend=0, highSpend=0, other_expense=0;

    } info;

    for(int i=0; i<employee.size(); i++)
    {
        info.tax= employee[i].payroll.tax;
        info.pension = employee[i].payroll.pension;
        info.other_expense = employee[i].payroll.otherExpenses;

        if(info.tax >= 100 && info.tax < 2000)
            info.bronze++;
        else if(info.tax >= 2000 && info.tax < 5000)
            info.gold++;
        else if(info.tax >= 5000)
            info.platinum++;

        if(info.pension >= 100 && info.pension < 4000)
            info.lowPen++;
        else if(info.pension >= 4000 && info.pension < 7000)
            info.medPen++;
        else if(info.pension >= 7000)
            info.highPen++;

        if(info.other_expense >= 600 && info.other_expense < 3000)
            info.lowSpend++;
        else if(info.other_expense >= 3000 && info.other_expense < 8000)
            info.medSpend++;
        else if(info.other_expense >= 8000)
            info.highSpend++;

    }
    cout<<"******************************************"<<endl;
    cout<<"\t****** Financial Report ******"<<endl;
    cout<<"******************************************"<<endl<<endl;
    cout<<"Bronze Tax payers(100-1999 ETB): "<<info.bronze<<endl;
    cout<<"Gold Tax payers(2000-4999 ETB): "<<info.gold<<endl;
    cout<<"Platinum Tax payers(>=5000 ETB): "<<info.platinum<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Low amount pensioners(100-3999 ETB): "<<info.lowPen<<endl;
    cout<<"Medium amount pensioners(4000-6999 ETB): "<<info.medPen<<endl;
    cout<<"High amount pensioners(>=7000 ETB): "<<info.highPen<<endl;
    cout<<"\n------------------------------------------------------\n";
    cout<<"Low spenders(600-2999 ETB): "<<info.lowSpend<<endl;
    cout<<"Medium spenders(3000-7999 ETB): "<<info.medSpend<<endl;
    cout<<"High spenders(>=8000 ETB): "<<info.highSpend<<endl;
}
