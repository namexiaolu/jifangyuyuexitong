#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入管理员子菜单界面
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//调用父类
		manager->operMenu();
		//将父类指针转为子类指针，调用子类里的其他接口
		Manager * man = (Manager *)manager;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "这是1增加人员";
			man->addPerson();
			
			break;
		case 2:
			cout << "这个是2查看用户";
			man->showPerson();
			break;
		case 3:
			cout << "这个是3查看机房";
			man->showComputer();

			break;
		case 4:
			cout << "这个是4清空预约";
			man->cleanFile();
			break;
		case 5:
			cout << "这个是5";
			break;
		default:
			delete manager;
			cout << "注销成功";
			system("cls");
			return;
			
		}
	
	}
	
}

//登录功能 
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象0620
	Identity *person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在"<< endl;
		ifs.close();
		return;
	}

	//准备接收用户的信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入账号" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
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
				cout << "学生验证登录成功，";
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
				cout << "老师验证登录成功，";
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
				cout << "管理员验证登录成功，";
	
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}

	}
	cout << "验证等陆失败" << endl;
	system("pause");
	system("cls");
	return;
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
			LoginIn(STUDENT_FILE,1);
			break;
		case 2:  //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << "输出的是啥"<<endl;
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