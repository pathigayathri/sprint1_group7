
#include <iostream>
#include <string.h>
using namespace std;
class Emp
{
private:
int eid;
string name;
float salary;
string department;
string phonenumber;
string address;
public:
Emp() //Default constructor
{
eid = 00;
name = "NULL";
salary = 00;
department = "NULL";
phonenumber = "00";
address = "NULL";
}
Emp(int Id, string nm, float sal, string dept, string phone, string addr)//parameterized constructor
{
eid = Id;
name = nm;
salary = sal;
department = dept;
phonenumber = phone;
address = addr;
}
void display()
{
cout << "\n**";
cout << "\nEmployee Id : " << eid;
cout << "\nName : " << name;
cout << "\nSalary : " << salary;
cout << "\nDepartment : " << department;
cout << "\nPhonenumber : " << phonenumber;
cout << "\nAddress : " << address;
cout << "\n**";
}
int getid()
{
return eid;
}
string getname()
{
return name;
}
float getsalary()
{
return salary;
}
string getdepartment()
{
return department;
}
string getphonenumber()
{
return phonenumber;
}
string getaddress()
{
return address;
}
void setid(int Id)
{
this->eid = Id;
}
void setname(string nm)
{
this->name = nm;
}
void setsalary(float sal)
{
this->salary = sal;
}
void setdepartment(string dept)
{
this->department = dept;
}
void setaddress(string addr)
{
this->address = addr;
}
void setphonenumber(string phone)
{
this->phonenumber = phone;
}
}; // emp class end
class Node
{
Emp data;
Node *next;
public:
Node(Emp d) //parameterized constructor
{
data = d;
next = NULL;
}
Emp getdata()
{
return data;
}
Node *getnext()
{
return next;
}
void setdata(Emp d)
{
this->data = d;
}
void setnext(Node *n)
{
this->next = n;
}
}; // node class end
class Company
{
Node *start;
public:
Company() //constructor
{
start = NULL;
}
void addemp(Emp e)
{
Node *temp = new Node(e);
temp->setnext(start);
start = temp;
}
void deleteEmpById(int id)
{
if (start == NULL)
{
cout << "\nEmployee details are not available ";
return;
}
Node *p = start; // when node to be deleted first node
if (id == p->getdata().getid())
{
start = start->getnext();
p->getdata().display();
cout << "\nEMPLOYEE DETAILS DELETED SUCCESSFULLY";
cout << "\n -------------------------------------";
delete p;
return;
}
if (p->getnext() == NULL)
{
cout << "\nEmployee id not found ";
return;
}
while (p->getnext()!= NULL)
{
Emp e1 = p->getnext()->getdata();
if (id == e1.getid())
{
Node *q = p->getnext();
p->setnext(q->getnext());
q->getdata().display();
cout << "\nEMPLOYEE DETAILS DELETED SUCCESSFULLY";
delete q;
return;
}
p = p->getnext();
}
cout << "\nEmployee id not found";
}
void updateEmp(int id)
{
if (start == NULL)
{
cout << "\n Employee details are not available";
return;
}
Node *p = start;
while (p != NULL)
{
Emp e = p->getdata();
if (p->getdata().getid() == id)
{
Emp e = p->getdata();
char ans;
string name;
float sal;
string department;
string phonenumber;
string address;
cout << "\nDo you want change name : (Y/N)";
cin >> ans;
if (ans == 'Y' || ans == 'y')
{
cout << "\n Enter New Name : ";
cin.ignore();
getline (cin,name);
e.setname(name);
}
cout << "\nDo you want change Salary : (Y/N)";
cin >> ans;
if (ans == 'Y' || ans == 'y')
{
cout << "\n Enter new salary : ";
cin >> sal;
e.setsalary(sal);
}
cout << "\nDo you want change department : (Y/N)";
cin >> ans;
if (ans == 'Y' || ans == 'y')
{
cout << "\n Enter New department : ";
cin.ignore();
getline (cin,department);
e.setdepartment(department);
}
cout << "\nDo you want change phonenumber : (Y/N)";
cin >> ans;
if (ans == 'Y' || ans == 'y')
{
cout << "\n Enter New phonenumber : ";
cin >> phonenumber;
e.setphonenumber(phonenumber);
}
cout << "\nDo you want change Address : (Y/N)";
cin >> ans;
if (ans == 'Y' || ans == 'y')
{
cout << "\n Enter New Address : ";
cin.ignore();
getline (cin,address);
e.setaddress(address);
}
p->setdata(e);
return;
}
p = p->getnext();
}
cout << "\nRecord not Found ";
}
void searchEmpById(int id)
{
if (start == NULL)
{
cout << "\n Employee details are not available ";
return;
}
Node *p = start;
while (p != NULL)
{
Emp e1 = p->getdata();
if (e1.getid() == id)
{
cout << "\nEmployee Id found ";
e1.display();
return;
}
p = p->getnext();
}
cout << "\nEmployee Id not Found";
}
void DisplayallEmp()
{
if (start == NULL)
{
cout << "\n\n Employee details are not available ";
cout << "\n\n";
return;
}
Node *p = start;
while (p != NULL)
{
p->getdata().display();
p = p->getnext();
}
cout << "\n\n*EMPLOYEE DETAILS DISPLAYED SUCCESSFULLY*";
cout << "\n ------------------------------------------------";
}
}; // Company class End
int main()
{
string userName;
string userPassword;
int loginAttempt = 0;
while (loginAttempt < 10)
{
cout << "Please enter your user name: ";
cin >> userName;
cout << "Please enter your user password: ";
cin >> userPassword;
if (userName == "Divya" && userPassword == "Divya123")
{
cout << "Welcome Divya!\n";
break;
}
else if (userName == "Likhitha" && userPassword == "Likhitha123")
{
cout << "Welcome Likhitha!\n";
break;
}
else if (userName == "Gayathri" && userPassword == "Gayathri123")
{
cout << "Welcome Gayathri!\n";
break;
}
else if (userName == "Geethika" && userPassword == "Geethika123")
{
cout << "Welcome Geethika!\n";
break;
}
else
{
cout << "Invalid login attempt. Please try again.\n" << '\n';
loginAttempt++;
}
}
if (loginAttempt == 10)
{
cout << "Too many login attempts ! ";
return 0;
}
cout << "Thank you for logging in.\n";
cout << "\n\n***********************";
cout << "\n\n** WELCOME TO EMPLOYEE MANAGEMENT SYSTEM **";
cout << "\n\n***********************";
int choice;
int ch = 0;
Company Ems;
while (ch != 6)
{
cout << "\n\n~~~~~~~~~~~";
cout << "\n\t1.ADD EMPLOYEE DETAILS ";
cout << "\n\t2.DISPLAY EMPLOYEE DETAILS ";
cout << "\n\t3.SEARCH BY EMPLOYEE ID ";
cout << "\n\t4.DELETE BY EMPLOYEE ID ";
cout << "\n\t5.UPDATE EMPLOYEE DETAILS ";
cout << "\n\t6.EXIT ";
cout << "\n\n~~~~~~~~~~~";
cout << "\n\tENTER YOUR CHOICE -> ";
cin >> ch;
switch (ch)
{
case 1:
{
newrecord:
int id,eid;
string name;
float sal;
string department;
string phonenumber;
string address;
char ans;
cout << "\n Enter the ID : ";
cin >> id;
if(id == eid)
{
cout<<"employee id already exists"<<endl;
}
cout << "\n Enter the Name :";
cin.ignore();
getline (cin,name);
cout << "\n Enter the Salary : ";
cin >> sal;
cout << "\n Enter the Department : ";
cin.ignore();
getline (cin,department);
cout << "\n Enter the Phonenumber : ";
cin >> phonenumber;
int phone_length = phonenumber.length();
while (phone_length != 10){
cout << endl;
cout << " Enter a valid Phonenumber : ";
cin >> phonenumber;
phone_length = phonenumber.length();
}
cout << "\n Enter the Address : ";
cin.ignore();
getline (cin,address);
Emp e1(id, name, sal, department, phonenumber,address);
Ems.addemp(e1);
cout << "\n\n EMPLOYEE DETAILS ADDED SUCCESSFULLY ";
cout << "\n -----------------------------------";
cout<<"\ndo you want to add another record (Y/N)"<<endl;
cin>>ans;
if(ans == 'Y' || ans == 'y')
{
cout<<"enter the new record"<<endl;
goto newrecord;
}
}
break;
case 2:
Ems.DisplayallEmp();
break;
case 3:
{
int id;
cout << "\nEnter Id to search : ";
cin >> id;
Ems.searchEmpById(id);
}
break;
case 4:
{
int id;
cout << "\nEnter Id to Delete : ";
cin >> id;
Ems.deleteEmpById(id);
}
break;
case 5:
{
int id;
cout << "\nEnter Id for update : ";
cin >> id;
Ems.updateEmp(id);
}
break;
case 6:
{
cout << "\n!!!!!!!!!!!END OF PROGRAM!!!!!!!!!!!!";
}
break;
default:
cout << "\nInvalid choice :";
break;
}
}
}
