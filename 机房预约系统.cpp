#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//�������Ա�Ӳ˵�����
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//���ø���
		manager->operMenu();
		//������ָ��תΪ����ָ�룬����������������ӿ�
		Manager * man = (Manager *)manager;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����1������Ա";
			man->addPerson();
			
			break;
		case 2:
			cout << "�����2�鿴�û�";
			man->showPerson();
			break;
		case 3:
			cout << "�����3�鿴����";
			man->showComputer();

			break;
		case 4:
			cout << "�����4���ԤԼ";
			man->cleanFile();
			break;
		case 5:
			cout << "�����5";
			break;
		default:
			delete manager;
			cout << "ע���ɹ�";
			system("cls");
			return;
			
		}
	
	}
	
}

//��¼���� 
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������0620
	Identity *person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������"<< endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������˺�" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs>>fName && ifs >> fPwd)
		{
			cout << fId << fName << fPwd;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���";
				person = new Student(id, name, pwd);
				system("pause");
				system("cls");
				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			cout << fId << fName << fPwd;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���";
				person = new Teacher(id, name, pwd);
				system("pause");
				system("cls");
				return;
			}
		}

	}
	else if (type == 3)
	{
	
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			cout << fName << fPwd;
			if ( fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���";
	
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}

	}
	cout << "��֤��½ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;

	while (true)
	{

		cout << "======================  ��ӭ��������ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select)
		{
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE,1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			cout << "�������ɶ"<<endl;
			return 0;
			break;

		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			
			break;
		}

	}
	system("pause");
	return 0;

}