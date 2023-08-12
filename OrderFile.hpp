#pragma once
#include <map>
#include "identity.h"
#include <string>
using namespace std;

class OrderFile
{
public:
    OrderFile();
    void updateOrder();//update order information
    map<int,map<string,string>> m_orderData;//store order info with key:value
    
    int order_size;
    
};

