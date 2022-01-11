#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include "identity.h"


//登录功能 
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity *person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!fs.is_open())
	{
		cout << "文件不存在"<< endl;
		ifs.close();
		return;
	}

	//准备接收用户的信息



}

int main()
{
	int select = 0;

	while (true)
	{

		cout << "======================  欢迎来到机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:  //学生身份
			break;
		case 2:  //老师身份
			break;
		case 3:  //管理员身份
			break;
		case 0:  //退出系统
			cout << "输出的是啥";
			return 0;
			break;

		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			
			break;
		}

	}
	system("pause");
	return 0;

}