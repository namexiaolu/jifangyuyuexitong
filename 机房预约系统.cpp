#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include "identity.h"


//��¼���� 
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
	Identity *person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!fs.is_open())
	{
		cout << "�ļ�������"<< endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ



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
			break;
		case 2:  //��ʦ���
			break;
		case 3:  //����Ա���
			break;
		case 0:  //�˳�ϵͳ
			cout << "�������ɶ";
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