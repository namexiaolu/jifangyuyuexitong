#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器
	this->initVector();
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_comId && ifs>>com.m_maxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string filename;
	string tip;
	string errorTip; //重复错误提示
	ofstream ofs;

	int select = 0;
	cin >> select;
	cout << "fdafdasdf-----"<<(select == 1);
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip =  "请输入学号";
		errorTip = "学号重复";
	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		tip = "请输入学号";
		errorTip = "职工号重复";
	}
	else 
	{
		cout << "输入错误";
		cout << "输入的是" << select;
		return;
	}
	//利用追加的方式写文件
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	
	

	while (true)
	{
		cout << tip << endl;
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip <<endl;
		}
		else
		{
			break;
		}
	}


	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}
void printStudent(Student &s)
{
	cout << "学号" << s.m_Id <<"姓名"<< s.m_Name<<"密码" << s.m_Pwd<<endl;
}
void printTeacher(Teacher &t)
{
	cout << "学号" << t.m_EmpId << t.m_Name << t.m_Pwd << endl;
}


void Manager::showPerson()
{
	cout << "1.查看学生，2、查看老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		for_each(vStu.begin(),vStu.end(),printStudent);
	}
		
	else
	{
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

}

void Manager::showComputer()
{
	cout << "查看机房信息" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it)
		cout << "机房编号" << it->m_comId << "个数" << it->m_maxNum;
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功";
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	//确保容器是清空状态
	vStu.clear();
	vTea.clear();

	//读取信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前的学生数量" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为" << vTea.size() << endl;
	ifs.close();

}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); ++it)
		{
			if(id == it->m_Id)
			{
				return true;
			}
		}
	}
	if (type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); ++it)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}
