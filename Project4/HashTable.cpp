#include "stdafx.h"
#include "HashTable.h"
#include <iostream>
using namespace std;


HashTable::HashTable(int div)
{
	D = div;	//DΪ����
	ht = new int[D];	//�洢����
	empty = new bool[D];	//�ж��Ƿ�Ϊ��
	for (int i = 0; i < D; i++)	//��ʼ��
		empty[i] = true;
}

HashTable::~HashTable()
{
}

/*
	����
	valueΪ����ֵ
*/
void HashTable::Insert(int value)
{
	int i = Search(value); //����Search��������ֹͣʱ���յ�
	if (empty[i]) {
		empty[i] = false;		//Ϊ�գ���˵���ҵ�����λ�ã������ݲ���
		ht[i] = value;
		return;
	}
	if (empty[i] == value) {	//��ֹͣλ��ǡΪ��Ԫ�أ�˵��Ԫ���Ѵ��ڣ��˳�
		cout << "�����ظ�" << endl;
	}
	else {						//���򣬱����޿���λ��
		cout << "������" << endl;
	}
	return;
}
/*
	Search
	value ����Ԫ��
*/
int HashTable::Search(int value)
{
	int i = value%D;
	int j = i;	//����ָ��
	do {
		if (empty[j]||ht[j] == value)
			return j;	//���ҵ���ֵ����˵�������ڣ����ҵ�valueֵ��˵�����ڣ�����ֹͣʱ����
		j = (j + 1) % D;
	} while (i != j); //�ص����ʱ˵��δ�ҵ�����ֹ

	return j;
}

int HashTable::Get(int index)
{
	return ht[index]; //����Ԫ��

}
