#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include"orderFile.h"

#include<vector>
#include<fstream>
//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���	������ѧ�š�����������
	Student(int id, string name, string psd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

public:
	//ѧ��ѧ��
	int m_Id;

	//������Ϣ
	vector<ComputerRoom>vCom;

};