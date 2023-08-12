#pragma once
#include <string>
#include <iostream>
using namespace std;

class Identity
{
public:
  virtual void operMenu()=0;//operation menu
  
  string name; // name 
  string password; // password
  };