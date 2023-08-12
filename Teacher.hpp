#pragma once
#include <iostream>
#include "identity.h"
using namespace std;


class Teacher : public Identity
{
public:
    Teacher();
    Teacher(int te_ID, string te_name, string te_password);
    virtual void operMenu();//the operation menu for teachers
    
    void showallOrder();//check all the orders 
    
    void auditOrder();//audit the order
    
    int te_ID;
    
};

