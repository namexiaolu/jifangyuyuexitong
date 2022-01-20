#include "orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >>stuName && ifs >> roomId && ifs >> status)
	{
		//²âÊÔ´úÂë
		cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;

		string key;
		string value;
		map<string, string> m;
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(this->m_Size, m));
		++this->m_size;
	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->m_size == 0)
		return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
}
