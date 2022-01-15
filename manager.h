#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "globalFile.h"
#include <fstream>

class Manager:public Identity
{
public:
	Manager();
	Manager(string name , string pwd);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();

};

