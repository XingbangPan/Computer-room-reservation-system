#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{

	this->m_Size = 0;
	this->m_OrderData.clear();

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	//׼�����������洢��ȡ������
	string date;	//����
	string interval;//ʱ���
	string stuId;	//ѧ�����
	string stuName;	//ѧ������
	string roomId;	//�������
	string status;	//ԤԼ״̬


	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;

		//date:1
		string key;
		string value;
		map<string, string>m;

		//��ȡ����
		int pos = date.find(":");	
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//cout << "key= " << key << endl;
		//cout << "value= " << value << endl;

		//��ȡʱ���
		pos = interval.find(":");	
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}


		//��ȡѧ��
		pos = stuId.find(":");	
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}


		//��ȡѧ������
		pos = stuName.find(":");	
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}


		//��ȡ������
		pos = roomId.find(":");	
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}


		//��ȡԤԼ״̬
		pos = status.find(":");	
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//��Сmap�������뵽���map������
		this->m_OrderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();
	

	//�������map����
	//for (map<int, map<string, string>>::iterator it = this->m_OrderData.begin(); it != this->m_OrderData.end(); it++)
	//{
	//	cout << "����Ϊ: " << it->first << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key = " << mit->first << " value = " << mit->second << "	";
	//	}
	//	cout << endl;
	//}

}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	//(ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)


	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " "
			<< "interval:" << this->m_OrderData[i]["interval"] << " "
			<< "stuId:" << this->m_OrderData[i]["stuId"] << " "
			<< "stuName:" << this->m_OrderData[i]["stuName"] << " "
			<< "roomId:" << this->m_OrderData[i]["roomId"] << " "
			<< "status:" << this->m_OrderData[i]["status"] << " "
			<< endl;
	}

	ofs.close();
	
}


