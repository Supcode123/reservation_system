#include "Teacher.hpp"
#include "OrderFile.hpp"
#include <vector>
//#include "globleFile.hpp"

Teacher::Teacher()
{
}
Teacher::Teacher(int te_ID, string te_name, string te_password)
{
    this->te_ID=te_ID;
    this->name=te_name;
    this->password=te_password;
}
void Teacher::operMenu()
{   cout<<"Welcome! Teacher: "<<this->name<<endl;
    cout<<"\t\t ---------------------------------------------\n"<<endl;
    cout<<"\t\t |            1.Show all the orders          |\n"<<endl;
    cout<<"\t\t |                                           |\n"<<endl;
    cout<<"\t\t |            2.Audit the order              |\n"<<endl;
    cout<<"\t\t |                                           |\n"<<endl;
    cout<<"\t\t |            0.Logout                       |\n"<<endl;
    cout<<"\t\t ---------------------------------------------\n"<<endl;
    cout<<"Please tap your choice..."<<endl;
    }
    
void Teacher::showallOrder()
{ 
   OrderFile of;
   if(of.order_size==0)
       {
       cout<<"No reservation record!"<<endl;
       system("pause");
       system("cls");
       return; }
   cout<<"\n"<<"All of reservations are:"<<endl;
   for(int i=0; i<of.order_size; i++)
       {
           cout<<i+1<<"."<<"Stu_ID:"<<of.m_orderData[i]["Stu_ID"]<<" "<<"Name:"<<of.m_orderData[i]["Name"]<<
           " "<<"Room_ID:"<<of.m_orderData[i]["Room_ID"]<<" "<<"Day:"<<of.m_orderData[i]["Day"]<<
           " "<<"Time:"<<of.m_orderData[i]["Time_Interval"]<<" "<<"Status:"<<of.m_orderData[i]["Status"]<<endl;
  }
  cout<<"\n"<<endl;
 }
void Teacher::auditOrder()
{
OrderFile of;
if(of.order_size==0)
    {  cout<<"No reservation record!"<<endl;
       system("pause");
       system("cls");
       return; }

vector<int> v; 
int index=0;
bool p=true;

for(int i=0; i<of.order_size;i++)       
   {
       if(of.m_orderData[i]["Status"]=="Processing")
           {
            if(p)
                {cout<<"These reservations are going to be checked:"<<endl;
                p=false;}
           cout<<index+1<<"."<<"Stu_ID:"<<of.m_orderData[i]["Stu_ID"]<<" "<<"Name:"<<of.m_orderData[i]["Name"]<<
               " "<<"Room_ID:"<<of.m_orderData[i]["Room_ID"]<<" "<<"Day:"<<of.m_orderData[i]["Day"]<<
               " "<<"Time:"<<of.m_orderData[i]["Time_Interval"]<<endl;
               index++;
           v.push_back(i);
         }
      }
if (v.size()==0)
    { cout<<"All reservations are checked !"<<endl;
       system("pause");
       system("cls");
       return;
        }
int select=0;
cout<<"\n"<<"Please select one reservation to check...(Input 0: return back)"<<endl;
while(true)
    {
    cin >> select;   
    if(select>=0 && select <=v.size())  
    {
        if(select==0)  
         {break;}
        else 
         {
         int select2=0;
         cout<<"Please input the checking-resault:"<<endl;
         cout<<"1. Accept"<<endl;
         cout<<"2. Reject"<<endl;
         cin >> select2;
         if(select2==1 || select2==2)
          {
            if(select2==1)
              {
               of.m_orderData[v[select-1]]["Status"]="Reserved";
                }
              if(select2==2)
              {
               of.m_orderData[v[select-1]]["Status"]="Rejected";      
               }          
           }
         else
            {cout<<"Wrong!Please reselect..."<<endl;
            break;}
         of.updateOrder();
         cout<<"Checking is finished."<<endl;
         break;
        }
    }
       cout<<"Input Wrongly! Please try again."<<endl;}
system("pause");
system("cls");
         }


