// Project3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Chain.h"
#include <iostream>
using namespace std;
Chain chain;	//Ŀ������
/*
	������c��������data
	cΪָ������
	dataΪ����
*/
void Insert(Chain & c, int data) {	
	c.Insert(data);
}
/*
	������c��������
	cΪָ������
*/
void Insert(Chain & c) {			
	int length;	//�������ݳ���						
	cout << "�������ݳ��ȣ�" << endl;
	cin >> length;
	for (int i = 1; i <= length; i++) {
		int j;
		cout << "����" << i << endl;
		cin >> j;
		Insert(c,j);	//ѭ��������c��������
	}
}
/*
	����
	��ʾָ��Ԫ������λ��
*/
void Search() {
	int target;	//����Ԫ��
	cout << "�������Ԫ��:" << endl;
	cin >> target;
	cout << "���" << endl;
	cout << chain.Search(target) << endl;	//���ò��ҹ���
}
/*
	ɾ��
	��������ɾ��ָ��Ԫ��
*/
void Delete() {
	int target;	//ָ��Ԫ��
	cout << "����ɾ��Ԫ��:" << endl;
	cin >> target;
	chain.Delete(target);	//����ɾ������
}
/*
	�������
*/
void Output() {
	cout << "���:" << endl;
	chain.Output();	//�����������
	cout << endl;
}
/*
	�����������
	���������������
*/
void Reverse() {
	ChainIterator *it = new ChainIterator(chain);	//��ʼ��������
	Chain *reverse = it->Reverse();	//���÷������������������������
	cout << "���:" << endl;
	reverse->Output();	//���������
	cout << endl;
	delete reverse;	//�ͷ��ڴ�
	delete it;
}
/*
	�ϲ���������
	����������������ʾ�ϲ�����������
*/
void Join() {
	Chain *a = new Chain();	//�������ϲ���
	Chain *b = new Chain();
	cout << "�����һ������" << endl;
	Insert(*a);	//����Ԫ��
	cout << "����ڶ�������" << endl;
	Insert(*b);
	ChainIterator *c = new ChainIterator(*a);
	Chain *result = c->Join(*b);	//���úϲ�����������������result
	cout << "���:" << endl;
	result->Output();	//���
	cout << endl;
	delete result;	//�ͷ��ڴ�
	delete c;
	delete b;
	delete a;
}
int main()
{
	bool exit = false;	//ָʾ�˳�״̬
	while (!exit) {
		cout << "ѡ�������" << endl;
		cout << "1.����Ԫ��" << endl;
		cout << "2.����Ԫ��" << endl;
		cout << "3.ɾ��Ԫ��" << endl;
		cout << "4.��ʾ����" << endl;
		cout << "5.�������" << endl;
		cout << "6.��������ϲ�" << endl;
		cout << "����.�˳�" << endl;
		int option;	//ѡ��
		cin >> option;
		switch (option)	//����ѡ�������Ӧ����
		{
		default:
			exit = true;
			break;
		case 1:
			Insert(chain);
			break;
		case 2:
			Search();
			break;
		case 3:
			Delete();
			break;
		case 4:
			Output();
			break;
		case 5:
			Reverse();
			break;
		case 6:
			Join();
			break;
		}

	}


	

}

