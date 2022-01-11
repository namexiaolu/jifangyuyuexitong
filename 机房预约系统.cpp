#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include "identity.h"
#include "globalFile.h"


//��¼���� 
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
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
	}
	else if (type == 2)
	{
	}
	else if (type == 3)
	{
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