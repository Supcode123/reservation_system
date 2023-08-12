#include <iostream>
#include "globleFile.hpp"
#include <string>
#include "identity.h"
#include <fstream>
#include "Student.hpp"
#include "Teacher.hpp"
#include "Manager.hpp"

using namespace std;

void managerMenu(Identity* & manager)
{
    while(true)
    {
    manager -> operMenu();
    Manager *M = (Manager*)manager;
    char select;
    cin >> select;
    switch(select)
    {
    case'1':
       // cout <<"add a new account" << endl;
        M -> addaccount();
        break;
    case'2':
        //cout << "show accounts" <<endl;
        M -> showPerson();
        break;
    case'3':
     //cout << "check computers" <<endl;
        M -> showComputer();
        break;
    case'4':
      //cout << "clear order-record" <<endl;
        M -> clearRecord();
        break;
    case'0':
       delete manager;
       cout << "Logout successfully !" <<endl;
       system("pause");
       system("cls");
       return;
    default:
      cout << "Wrong! Please reselect" <<endl;
      system("pause");
      }     
    }
    }
    
void TeacherMenu(Identity* &teacher )
{ 
  char select;
   while(true)
       {
       teacher->operMenu(); 
       Teacher *T =(Teacher*)teacher; 
       cin >> select;
       switch(select)
        {
            case'1':
                T->showallOrder();
                break;
            case'2':
                 T->auditOrder();
                 break;
            case'0':
                 delete teacher;
                 cout << "Logout successfully !" <<endl;
                 system("pause");
                 system("cls");
                 return;
            default:
                 cout << "Wrong! Please reselect..." <<endl;
                 system("pause");        
       }
           } } 

void StudentMenu(Identity * &student)
{
while(true)
{ student ->operMenu();
  Student *S = (Student*)student;
  char select;
  cin >> select;
  switch(select)
  { 
    case'1':
        //cout<<"Apply an order"<<endl;
        S->applyOrder();
        break;
    case'2':
        //cout<<"Check my order"<<endl;
        S->showOrder(); 
        break;
   /* case'3':
        cout<<"Check all my order"<<endl;
        S->showallOrder();
        break;*/
    case'3':
        //cout<<"Cancle my corder"<<endl;
        S->cancelOrder();
        break;
    case'0':
        delete student;
        cout << "Logout successfully !" <<endl;
        system("pause");
        system("cls");
        return;
    default:
        cout << "Wrong! Please reselect..." <<endl;
        system("pause");
  }
    }
    }    

void LogIn(string filename,int choice)
{
   Identity * person = NULL;
   
   ifstream ifs;
   ifs.open(filename,ios::in);
   if (!ifs.is_open())
       {
       cout<<"The File do not exit!"<<endl;
       ifs.close();
       return; 
       }
       
    int id = 0;
    string name;
    string password;
    
    if(choice == 1 || choice == 2)
        {
            cout<<"please input your id"<<endl;
            cin >> id;
        }
   
    cout<<"please input your name"<<endl;
    cin >> name;
    cout<<"please input your password"<<endl;
    cin >> password;
    
    
    if (choice == 1)
    {// varification for login of student_identity
    int ifs_id;
    string ifs_name;
    string ifs_password;
    while(ifs >> ifs_id && ifs >> ifs_name && ifs >> ifs_password)
    {
    if(id == ifs_id && name == ifs_name && password == ifs_password)
    { cout << "Welcome.Login for student successfully!" << endl;
      system("pause");
      system("cls");
      person = new Student(id,name,password);
      StudentMenu(person);
      return;    
    }
        }  
        }
    else if (choice == 2)
    {// varification for login of teacher_identity
     int ifs_id;
     string ifs_name;
     string ifs_password;
     while(ifs >> ifs_id && ifs >> ifs_name && ifs >> ifs_password){
        if(ifs_id == id && ifs_name == name && ifs_password == password){
            cout << "Welcome.Login for teacher successfully!" << endl;
            system("pause");
            system("cls");
        
    person = new Teacher(id,name,password);
    TeacherMenu(person);  
    return;    
 }}
   }
    else if (choice == 3)
    {// varification for login of manager identity
    
     string ifs_name;
     string ifs_password;
     while( ifs >> ifs_name && ifs >> ifs_password){
        if( ifs_name == name && ifs_password == password)
            {
            cout << "Welcome.Login for Admintor successfully!" << endl;
            system("pause");
            system("cls");
        
    person = new Manager(name,password);
    managerMenu(person);
    
     return;    }}
    }   
    cout<<"Varification of Login fails! Please ty again"<<endl;    
    
    system("pause");
    system("cls");
    return;
}
 

       
int main()
{ 
    char select ;
    while(true){    
    cout<<"==================================================================="
    <<endl;
	cout<<"                      Welcome to Reservation System                "
    <<endl;
    cout<<"==================================================================="
    <<endl;
    cout<<"\t\t -----------------------------------------------\n"<<endl;
    cout<<"\t\t |                                             |\n"<<endl;
    cout<<"\t\t |            1.Student Presentative           |\n"<<endl;
    cout<<"\t\t |                                             |\n"<<endl;
    cout<<"\t\t |            2.Teacher                        |\n"<<endl;
    cout<<"\t\t |                                             |\n"<<endl;
    cout<<"\t\t |            3.Manager                        |\n"<<endl;
    cout<<"\t\t |                                             |\n"<<endl;
    cout<<"\t\t |            0.Exit                           |\n"<<endl;
    cout<<"\t\t |                                             |\n"<<endl;   
    cout<<"\t\t -----------------------------------------------\n"<<endl;
    cout<<"Please tap your identity..."<<endl;
    
    cin >> select; 
    switch(select)   {
    case '1':   //Student
       LogIn(STUDENT_FILE,1);
       break;
    case '2':   //Teacher
       LogIn(TEACHER_FILE,2);
       break;
    case '3':   //Manager
       LogIn(ADMIN_FILE,3); 
       break;
    case '0':   //Exit
       cout<<"Thanks for using, see you !"<<endl;
       system("pause");
       break;
    default:
       cout<<"Wrong!! Please reselect."<<endl;
       system("pause");   
       system("cls");
       break;
    }
}    
system("pause");
	return 0;
}
