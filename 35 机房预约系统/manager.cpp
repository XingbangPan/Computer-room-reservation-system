#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ��ȡ�������ļ��� ѧ������ʦ��Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;

	while (ifs >> com.m_ComId && ifs >> com.m_Maxnum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "��������: " << vCom.size() << endl;
	

}

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա: " << this->m_Name << "��¼! " << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|               1 ����˺�               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|               2 �鿴�˺�               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|               3 �鿴����               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|               4 ���ԤԼ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|               0 ע����¼               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
	cout << "��ѡ�����Ĳ���: " << endl;

}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺�����: " << endl;
	cout << "1 ���ѧ��" << endl;
	cout << "2 �����ʦ" << endl;

	string fName;	//�����ļ���
	string tip;		//��ʾid��
	string errTip;	//�ظ�������ʾ

	ofstream ofs;	//�ļ���������

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ӵ���ѧ��
		fName = STUDENT_FILE;
		tip = "������ѧ��: ";
		errTip = "ѧ���ظ�������������";
		
	}
	else
	{
		fName = TEACHER_FILE;
		tip = "������ְ�����: ";
		errTip = "ְ������ظ�������������";

	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fName, ios::out | ios::app);
	
	int id;		//ѧ�� /ְ����
	string name;//����
	string pwd;	//����
	
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		
		//���ѧ��/ְ������ظ�
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errTip << endl;
		}
		else
		{
			break;
		}

	}

	cout << "����������: " << endl;
	cin >> name;
	
	cout << "����������: " << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	
	ofs.close();

	//���ó�ʼ�������ӿ� ���»�ȡ�ļ��е�����
	this->initVector();



	system("pause");
	system("cls");
	return;



}

void printStudent(Student& s)
{
	cout << "ѧ��: " << s.m_Id << "	����: " << s.m_Name << "	����: " << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ�����: " << t.m_EmpId << "	����: " << t.m_Name << "	����: " << t.m_Pwd << endl;
}



//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����: " << endl;
	cout << "1 �鿴����ѧ��" << endl;
	cout << "2 �鿴������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�鿴��ʦ
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager::showComputerRoom()
{
	cout << "������Ϣ����: " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������: " << it->m_ComId << "	�����������: " << it->m_Maxnum << endl;
	}
	system("pause");
	system("cls");

}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");

}


//��ʼ������
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ	ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ: " << vStu.size() << endl;
	ifs.close();


	//��ȡ��Ϣ	��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ: " << vTea.size() << endl;

	ifs.close();
}


//����ظ�	����1 ���ѧ��/ְ����	����2 �������
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				//��⵽�ظ�ѧ��ѧ��
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				//��⵽�ظ�ְ�����
				return true;
			}
		}

	}
	return false;
}

