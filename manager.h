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
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ��������Ϊ�˸�ȥ����׼��
	void initVector();

	//ѧ������
	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

	//����ظ�
	bool checkRepeat(int id,int type);

};

