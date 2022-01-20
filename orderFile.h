#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <fstream>
#include <string>

class OrderFile
{
public:
	OrderFile();
	//更新预约记录
	void updateOrder();

	//key 条数 value 记录的信息
	map<int, map<string, string>> m_orderData;

	//预约记录条数
	int m_size;
};
