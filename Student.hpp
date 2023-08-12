#pragma once
#include <iostream>
#include "identity.h"
#include <vector>
#include "computer.hpp"
using namespace std;


class Student : public Identity
{
public:
    Student();
    Student(int stu_Id,string stu_name,string stu_password);
    virtual void operMenu();//menu page 
    
    void applyOrder();//apply an order
    
    void showOrder();//check my order

     
    void cancelOrder();//cancle my corder
 
    void Computervector();
 
    int stu_Id;
    vector<Computer> vCompu;
};

