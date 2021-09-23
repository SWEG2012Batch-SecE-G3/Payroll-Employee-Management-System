void searchbyName()     //search by name
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
    for (int i{}; i<employee.size(); i++)
    {
        string fName=employee[i].fullName.firstName, mName=employee[i].fullName.middleName, lName=employee[i].fullName.lastName;
        for(int i = 0; i<fName.length(); i++)
            fName.at(i) = char(tolower(fName.at(i)));
        for(int i = 0; i<mName.length(); i++)
            mName.at(i) = char(tolower(mName.at(i)));
        for(int i = 0; i<lName.length(); i++)
            lName.at(i) = char(tolower(lName.at(i)));
        if(name1==fName && name2==mName && name3==lName)
        {
            current_employee(1,i);
            return;
        }
    }
    cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
}

void searchbyId()      //search by ID
{
    unsigned short int idNum;
    cout<<"ENTER THE ID OF EMPLOYEE YOU WANT TO FIND: "<<"\n";
    cin>>idNum;
    for (int i=0; i<employee.size(); i++)
    {
        if(employee[i].emp_Id==idNum)
        {
            current_employee(1, i);
            return;
        }
    }
    cout<<"\n"<<"EMPLOYEE NOT FOUND."<<"\n";
}
