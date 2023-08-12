#include "Student.hpp"
#include "globleFile.hpp"
#include <fstream>
#include <string>
#include "OrderFile.hpp"
#include <vector>

Student::Student()
{
}
Student::Student(int stu_Id,string stu_name,string stu_password)
{
    this->stu_Id=stu_Id;
    this->name=stu_name;
    this->password=stu_password;
    this->Computervector();
}
void Student::operMenu() 
{
    cout<<"Welcome! Student: "<<this->name<<endl;
    cout<<"\t\t ---------------------------------------------\n"<<endl;
    cout<<"\t\t |            1.Apply a reservation          |\n"<<endl;
    cout<<"\t\t |                                           |\n"<<endl;
    cout<<"\t\t |            2.Show my reservation          |\n"<<endl;
    /*cout<<"\t\t |                                      |\n"<<endl;
    cout<<"\t\t |            3.Check all my order      |\n"<<endl;*/
    cout<<"\t\t |                                           |\n"<<endl;
    cout<<"\t\t |            3.Cancle my reservation        |\n"<<endl;
    cout<<"\t\t |                                           |\n"<<endl; 
    cout<<"\t\t |            0.Logout                       |\n"<<endl;
    cout<<"\t\t ---------------------------------------------\n"<<endl;
    cout<<"Please tap your choice..."<<endl;
    }
void Student::applyOrder()
{
    cout<<"the opening times of the computer_room is: "<<endl;
    cout<<"1.Monday"<<endl;
    cout<<"2.Tusday"<<endl;
    cout<<"3.Wednesday"<<endl;
    cout<<"4.Thursday"<<endl;
    cout<<"5.Friday"<<endl;
    cout<<"Please choose one day to apply..."<<endl;
    
    char choose1;
    string day;
    string interval; 
    while(true)
    {
     cin >> choose1;
     switch(choose1)
        {
            case'1':
              day="Monday";
              break;
            case'2':
              day="Tuesday";
              break;
            case'3':
              day="Wednesday";
              break;            
            case'4':
              day="Thursday";
              break;
            case'5':
              day="Friday";
              break;
            default:
              cout<<"Wrong!Please reselect..."<<endl;
              return;
             }
        break;
    }
        
     cout<< "Please choose a time-interval:"<<endl;
     cout<<"1.Forenoon"<<endl;
     cout<<"2.Afternoon"<<endl;
     
     char choose;
     while(true)
     {
      cin >> choose;   
      if(choose=='1')
          {interval="Forenoon";
              break;}
       if(choose=='2')
          {
            interval="Afternoon";
            break;}
      cout << "Wrong!Please reselect..."<<endl;   } 
      
      cout<<"Computer_number in 1st room: "<<vCompu[0].max_num<<endl;
      cout<<"Computer_number in 2nd room: "<<vCompu[1].max_num<<endl;
      cout<<"Computer_number in 3th room: "<<vCompu[2].max_num<<endl;
       cout<<"\n"<<endl;
      cout<<"Please choose one computer room..."<<endl;
      cout<<"1.Room 1"<<endl;
      cout<<"2.Room 2"<<endl;
      cout<<"3.Room 3"<<endl;
     char ch_room;
     int id=0;
     while(true)
     {
      cin >> ch_room;   
      if(ch_room=='1')
          {  id = 1;
              break;}
      if(ch_room=='2')
          {  id = 2;
              break;}
      if(ch_room=='3')
          {  id = 1;
              break;}
      cout << "Wrong!Please reselect..."<<endl;   }
    
    cout<<"Book successfully! Processing..."<<endl;
    ofstream ofs;
    string status="Processing";
    ofs.open(ORDER_FILE,ios::app);
    ofs <<"Day:"<<day<<" ";
    ofs <<"Time_Interval:"<<interval<<" ";
    ofs <<"Stu_ID:"<<stu_Id<<" ";
    ofs <<"Name:"<<name<<" ";
    ofs <<"Room_ID:"<<id<<" ";
    ofs <<"Status:"<<status<<" ";
    ofs.close();
    system("pause");
    system("cls");
    }
void Student::showOrder()
{
    OrderFile of;
    if(of.order_size==0)
    {
    cout<<"No reservation record!"<<endl;
    system("pause");
    system("cls");
    return;
    }
   //cout<<of.order_size<<endl;
   
    for(int i = 0; i < of.order_size ; i++)
    {//cout<<of.m_orderData[i]["Stu_ID"]<<endl;
     if(this->stu_Id==atoi(of.m_orderData[i]["Stu_ID"].c_str())){
            cout<<"Stu_ID:"<<of.m_orderData[i]["Stu_ID"]<<"  "<<"Name:"<<of.m_orderData[i]["Name"]
            <<"  "<<"Reservation_Day:"<<of.m_orderData[i]["Day"]<<"  "    
            <<"Reservation_Time:"<<of.m_orderData[i]["Time_Interval"]<<"  "
            <<"Room_ID:"<<of.m_orderData[i]["Room_ID"]<<"  "
            <<"Status:"<<of.m_orderData[i]["Status"]<<endl;
   } 
   }
system("pause");
system("cls");
}
void Student::cancelOrder()
{
    OrderFile of;
    vector<int> v;
    if(of.order_size==0){
        cout<<"There isn't your reservation record."<<endl;
        system("pause");
        system("pls");
        return;}
    // cout<<of.order_size<<endl; 
cout<<"You have these reservations in process or being accepted:"<<endl;  
cout<<"\n"<<endl;  
    for (int i=0;i<of.order_size;i++)
        { if(atoi(of.m_orderData[i]["Stu_ID"].c_str())==this->stu_Id)
            { 
                v.push_back(i);
                if(of.m_orderData[i]["Status"]=="Processing" || of.m_orderData[i]["Status"]=="Accepted")
                {   
                    cout<<i+1<<"."<<"Day:"<<of.m_orderData[i]["Day"]<<" "<<"Time: "<<of.m_orderData[i]["Time_Interval"]
                <<" "<<"Room:"<<of.m_orderData[i]["Room_ID"]<<" "<<"Status:"<<of.m_orderData[i]["Status"]<<endl;
        }}
            }
      
    cout<<"\n"<<"Please select one Reservation to cancel...(Input 0: return back)"<<endl;
 
    int select=0;
    while(true)
        { 
            cin >> select;
     if(select>=0 && select<=v.size())
            { if(select==0)
              {break;}
              else 
              {  of.m_orderData[v[select-1]]["Status"]="Cancelled";
                 of.updateOrder();
                 cout<<"Cancle successfully!"<<endl;
            }
                 system("pause");
                 system("cls");
                 break;
                 }  
        cout<<"Input Wrongly! Please try again."<<endl;    
                }

    }
        
void Student::Computervector()
{
   ifstream ifs;
   ifs.open(COMPUTER_FILE,ios::in);
   Computer c;
   if(!ifs.is_open())
   { cout<<"fails at opening the file !"<<endl;
    return;  }
   while(ifs >> c.room_id && ifs >> c.max_num)
        {
         vCompu.push_back(c);
        }
    ifs.close();    
   }
