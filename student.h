#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
class Student : public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Student();
	//�вι���
	Student(int id ,string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴ԤԼ
	void showMyOrder();

	void showAllOrder();
	
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;

};

