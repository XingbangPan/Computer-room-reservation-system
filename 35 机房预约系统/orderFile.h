#pragma once
#include<iostream>
using namespace std;

#include"globalFile.h"

#include<fstream>
#include<map>

class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();



public:
	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������ key��¼����	value�����¼��ֵ��Ӧ��Ϣ
	map<int, map<string, string>> m_OrderData;
};