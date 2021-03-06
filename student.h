#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <vector>
#include "computerRoom.h"
#include  "globalFile.h"
#include <fstream>
#include "orderFile.h"

class Student : public Identity
{
public:
	//默认构造函数
	Student();
	//有参构造
	Student(int id ,string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看预约
	void showMyOrder();

	void showAllOrder();
	
	void cancelOrder();
	//学生学号
	int m_Id;

	vector<ComputerRoom> vCom;

};

