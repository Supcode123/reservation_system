#include "OrderFile.hpp"
#include <fstream>
#include "globleFile.hpp"
#include <string>
using namespace std;

OrderFile::OrderFile()
{
 ifstream ifs;
 ifs.open(ORDER_FILE,ios::in);
 if(!ifs.is_open())
     {
      cout <<"Fails to open the file !" << endl;    }
 this->order_size=0;
 string day;
 string time_interval;   
 string stu_id;
 string name;
 string room_id; 
 string status;

while(ifs>>day&&ifs>>time_interval&&ifs>>stu_id&&ifs>>name&&ifs>>room_id&&ifs>>status)
{
    map<string,string> m;
    int pos=0;
    string key;
    string value;
    
    pos=day.find(":");
    if(pos!=-1)
    {
    key=day.substr(0,pos);
    value=day.substr(pos+1,day.size()-pos);
    m.insert(make_pair(key,value));}
  
    pos=time_interval.find(":");
    if(pos!=-1)
    {
    key=time_interval.substr(0,pos);
    value=time_interval.substr(pos+1,time_interval.size()-pos);
    m.insert(make_pair(key,value));}
    
    pos=stu_id.find(":");
    if(pos!=-1)
    {
    key=stu_id.substr(0,pos);
    value=stu_id.substr(pos+1,stu_id.size()-pos);
    m.insert(make_pair(key,value));}
    
    pos=name.find(":");
    if(pos!=-1)
    {
    key=name.substr(0,pos);
    value=name.substr(pos+1,name.size()-pos);
    m.insert(make_pair(key,value));}
    
    pos=room_id.find(":");
    if(pos!=-1)
    {
    key=room_id.substr(0,pos);
    value=room_id.substr(pos+1,room_id.size()-pos);
    m.insert(make_pair(key,value));}
    
    pos=status.find(":");
    if(pos!=-1)
    {
    key=status.substr(0,pos);
    value=status.substr(pos+1,status.size()-pos);
    m.insert(make_pair(key,value));}
    
    
    this->m_orderData.insert(make_pair(order_size,m));
    this->order_size++;
    }
    ifs.close();
}
void OrderFile::updateOrder()
{
if(order_size==0)
    {
    return;}
  ofstream ofs;
  ofs.open(ORDER_FILE,ios::out | ios::trunc);
  for(int i=0 ; i<order_size; i++ )
  { ofs <<"Day:"<< this->m_orderData[i]["Day"] << " ";
    ofs <<"Time_Interval:"<<this->m_orderData[i]["Time_Interval"] <<" ";
    ofs <<"Stu_ID:"<<this->m_orderData[i]["Stu_ID"]<<" ";
    ofs <<"Name:"<<this->m_orderData[i]["Name"]<<" ";
    ofs <<"Room_ID:"<<this->m_orderData[i]["Room_ID"]<<" ";
    ofs <<"Status:"<<this->m_orderData[i]["Status"]<<" "<<endl;
      }
    ofs.close();
  
  } 
