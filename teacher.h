#pragma once
#include <iostream>
#include "identity.h"
#include <string>
#include "orderFile.h"
#include <vector>
using namespace std;
class Teacher : public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Teacher();
	//�������Ĺ��캯��
	Teacher(int empId,string name,string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;
};