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
	//����ԤԼ��¼
	void updateOrder();

	//key ���� value ��¼����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_size;
};
