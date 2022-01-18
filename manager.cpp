#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVector();
	//��ʼ��������Ϣ
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
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string filename;
	string tip;
	string errorTip; //�ظ�������ʾ
	ofstream ofs;

	int select = 0;
	cin >> select;
	cout << "fdafdasdf-----"<<(select == 1);
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip =  "������ѧ��";
		errorTip = "ѧ���ظ�";
	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		tip = "������ѧ��";
		errorTip = "ְ�����ظ�";
	}
	else 
	{
		cout << "�������";
		cout << "�������" << select;
		return;
	}
	//����׷�ӵķ�ʽд�ļ�
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


	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}
void printStudent(Student &s)
{
	cout << "ѧ��" << s.m_Id <<"����"<< s.m_Name<<"����" << s.m_Pwd<<endl;
}
void printTeacher(Teacher &t)
{
	cout << "ѧ��" << t.m_EmpId << t.m_Name << t.m_Pwd << endl;
}


void Manager::showPerson()
{
	cout << "1.�鿴ѧ����2���鿴��ʦ" << endl;
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
	cout << "�鿴������Ϣ" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); ++it)
		cout << "�������" << it->m_comId << "����" << it->m_maxNum;
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�";
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	//ȷ�����������״̬
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰ��ѧ������" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << vTea.size() << endl;
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
