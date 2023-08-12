#pragma once
#include <iostream>
#include "identity.h"
#include "Student.hpp"
#include "Teacher.hpp"
#include <vector>
#include "computer.hpp"
using namespace std;

class Manager : public Identity
{
public:
    Manager();
    Manager(string name, string password);
    virtual void operMenu();//operation page of managers
    
    void addaccount();//add account
    void showPerson();//check accounts
    void showComputer();//check status of computers 
    void clearRecord();//clear the record of orders
    
    void InitVector();// read files of teachers&students 
    bool checkRepeat(int id ,int type);// avoid repeated account
    void Comvector();
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<Computer> vCom;
};
