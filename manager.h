#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "globalFile.h"
#include <fstream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <algorithm>

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

	//初始化容器。为了给去重做准别
	void initVector();

	//学生容器
	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

	//检测重复
	bool checkRepeat(int id,int type);

};

