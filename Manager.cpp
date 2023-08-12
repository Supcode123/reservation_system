#include "Manager.hpp"
#include <fstream>
#include <string>
#include "globleFile.hpp"


Manager::Manager()
{
}
Manager::Manager(string name, string password)
{
   this->name=name;
   this->password=password;
  
   this->InitVector();
   this->Comvector();
   cout<<"\n"<<endl;
}

bool Manager::checkRepeat(int id ,int type)
{ 
if (type == 1)
 { 
 for (vector<Student>::iterator it=vStu.begin();it != vStu.end();it++ )
    {
      if(id == it->stu_Id)
        {return true;}
    } }
if(type == 2)
{ for(vector<Teacher>::iterator it=vTea.begin();it!=vTea.end();it++ )
     {if(id == it->te_ID)
         {return true;}
}} 
return false;}

void Manager::operMenu()
{  
    
	cout<<"Welcome! Admin: "<<this->name<<endl;

    cout<<"\t\t -----------------------------------------\n"<<endl;
    cout<<"\t\t |            1.Add new account          |\n"<<endl;
    cout<<"\t\t |                                       |\n"<<endl;
    cout<<"\t\t |            2.Show accounts            |\n"<<endl;
    cout<<"\t\t |                                       |\n"<<endl;
    cout<<"\t\t |            3.Show computers           |\n"<<endl;
    cout<<"\t\t |                                       |\n"<<endl;
    cout<<"\t\t |            4.Clear order-record       |\n"<<endl;
    cout<<"\t\t |                                       |\n"<<endl; 
    cout<<"\t\t |            0.Logout                   |\n"<<endl;
    cout<<"\t\t -----------------------------------------\n"<<endl;
    cout<<"Please tap your choice..."<<endl;
}

void Manager::addaccount()
{
    cout << "Please select indentity of the account to be added: "<<endl;
    cout<<"\t\t -----------------------------------------\n"<<endl;
    cout<<"\t\t           1. student account"<<endl;
    cout<<"\t\t                                          \n"<<endl; 
    cout<<"\t\t           2. teacher account"<<endl;
    cout<<"\t\t -----------------------------------------\n"<<endl;
    int id = 0;
    
    string name;
    string psw;
    string Filename;
    ofstream ofs;
    
    
    int select=0;
    cin >> select;
    if  (select==1 || select==2)
{ 
    if  (select==1)        
    { 
        while(true)                        // avoid the repeated account
        { 
            cout << "Please input the id number..."<<endl;    
            cin >> id;
            if (checkRepeat(id,select)){
            cout<<"The account exists already! Please try again."<<endl; 
            }
            else
                {break;}
     }
      cout << "Please input the name of student"<<endl;
      cin >> name;
      cout << "Please input the password of student"<<endl;
      cin >> psw;
      Filename = STUDENT_FILE ;
    }
    else if(select==2)
    {    while(true)
        { 
            cout << "Please input the id number..."<<endl;    
            cin >> id;
            if (checkRepeat(id,select)){
            cout<<"The account exists already! Please try again."<<endl; 
            }
            else
                {break;}
     }                                                                 // avoid the repeated account
            cout << "Please input the name of teacher"<<endl;
            cin >> name;
            cout << "Please input the password of teacher"<<endl;
            cin >> psw;
            Filename = TEACHER_FILE ;
            } 
     }
    else
        { cout << "Wrong! Please try again. "<<endl;
          system("pause");
          return;
        }   
    ofs.open(Filename,ios::out | ios::app);
    ofs << id <<" "<<name<<" "<<psw<<endl;
    cout<<"add successfully!"<<endl;
    system("pause");
    system("pls");
    ofs.close();
    InitVector();
    
    }
    
void printStudent(Student & s)
{ cout << "ID:" << s.stu_Id <<" "<< "Name:" << s.name << 
" "<<"Password:" << s.password << endl;
    }
void printTeacher(Teacher & t)
{ cout << "ID:" << t.te_ID<<" "<< "Name:" << t.name << 
" "<<"Password:" << t.password  << endl;
    }
    
void Manager::showPerson()
{
    cout <<"Please select indentity of the account to check...: "<<endl;
    cout<<"\t\t -----------------------------------------\n"<<endl;
    cout<<"\t\t           1. student account"               <<endl;
    cout<<"\t\t                                          \n"<<endl; 
    cout<<"\t\t           2. teacher account"               <<endl;
    cout<<"\t\t -----------------------------------------\n"<<endl;
char select;
while(true){
cin >> select;
if(select=='1')
    { cout<<"the informations of students: "<<endl;
        for_each(vStu.begin(),vStu.end(),printStudent);
      break;  }
else if (select=='2')
    {cout<<"the informations of teachers: "<<endl;
        for_each(vTea.begin(),vTea.end(),printTeacher);
     break;   }
else        
{cout<<"Wrong! Please try again."<<endl;
break;}
system("pause");
system("pls");
}}

 void Manager::showComputer()
{ cout << "computer information :"<<endl;     
 for (vector<Computer>::iterator it=vCom.begin();it!=vCom.end();it++)
{
  cout << "Room_ID:"<<it->room_id<<" "<<"Computer number:"<<it->max_num<<endl;  }  
system("pause");
system("cls");
}

void Manager::clearRecord()
{ 
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    cout<<"clear successfully"<<endl;
    system("pause");
    system("cls");
}

void Manager::Comvector()
{
ifstream ifs;
ifs.open(COMPUTER_FILE,ios::in);
if(!ifs.is_open())
    {
        cout <<"fails at opening computer file !" << endl;  
     return;} 
Computer c;
while(ifs>>c.room_id && ifs >> c.max_num)
{ vCom.push_back(c);}
cout << "the number of computer room is :"<<vCom.size()<<endl;
ifs.close(); 
}

void Manager::InitVector()
{
    vStu.clear();
    vTea.clear();
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);    
    if(!ifs.is_open())
    {
   cout<<"fails at opening the file !"<<endl; 
   return;     }
   
   Student s;
   while(ifs >> s.stu_Id && ifs >> s.name && ifs >> s.password)
   {
       vStu.push_back(s);            
    }
    cout << "Student_number is :"<<vStu.size()<<endl;
   ifs.close();
   
   ifs.open(TEACHER_FILE, ios::in);
   if(!ifs.is_open()) 
   {
   cout<<"fails at opening the file !"<<endl; 
   return; 
    }
   Teacher t;
   while(ifs >> t.te_ID && ifs >> t.name && ifs >> t.password)
 { vTea.push_back(t);
     }
   cout << "Teacher_number is :"<<vTea.size()<<endl;  
   ifs.close(); 
}