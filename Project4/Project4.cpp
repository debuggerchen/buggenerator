 //Project4.cpp : �������̨Ӧ�ó������ڵ㡣


#include "stdafx.h"
#include "SparseMatrix.h"
#include <iostream>
#include "HashChain.h"
#include "HashTable.h"
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	//�������
	SparseMatrix x;
	x.Insert();
	cout << "�������ݣ�" << endl;
	x.Output();
	cout << "ת��" << endl;
	SparseMatrix *y=x.transpose();
	y->Output();
	cout << "�����¾���" << endl;
	SparseMatrix z;
	z.Insert();
	cout << "�������ݣ�" << endl;
	z.Output();
	SparseMatrix *t = x.add(z);
	cout << "�Ӻͽ����" << endl;
	t->Output();


	//����500�������
	vector<int> temp;
	for (int i = 0; i < 2000; i++) {
		temp.push_back(i + 1);
	}
	random_shuffle(temp.begin(), temp.end());
	int *a = new int[temp.size()];
	for (int i = 0; i < temp.size(); i++) {
		a[i] = temp[i];
	}

	//����ɢ�б�
	HashTable *ht=new HashTable(961);
	for (int i = 0; i < 500; i++) {
		ht->Insert(a[i]);	//��������
	}
	//��ѯ���
	while (true) {
		int s;
		cout << "��������ɢ�б��ѯ���ݣ�����-1�˳�" << endl;
		cin >> s;
		if (s == -1) {
			break;
		}
		else {
			cout << "���" << endl;
			int i = ht->Search(s);
			if (ht->Get(i) == s)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		
	}
	//����ɢ�б�
	HashChain *hc = new HashChain(961);
	for (int i = 0; i < 500; i++) {
		hc->Insert(a[i]);	//��������
	}

	//��ѯ���
	while (true) {
		int s;
		cin >> s;
		cout << "��������ɢ�б��ѯ���ݣ�����-1�˳�" << endl;
		if (s == -1) {
			break;
		}
		else {
			cout << "��ѯ�����" << endl;
			cout << hc->Search(s) << endl;
		}
		
	}
	
	int j;
	cin >> j;
    return 0;
}

