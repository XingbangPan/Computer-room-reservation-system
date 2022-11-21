#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"globalFile.h"
#include"computerRoom.h"

#include<fstream>
#include<vector>
#include<algorithm>

class Manager :public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputerRoom();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ�	����1 ���ѧ��/ְ����	����2 �������
	bool checkRepeat(int id, int type);

	//��ʼ����������

public:
	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ
	vector<ComputerRoom>vCom;

	


};