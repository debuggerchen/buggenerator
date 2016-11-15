#include "stdafx.h"
#include "Chain.h"
#include <iostream>
#include "Node.h"
using namespace std;
/*
	���캯��
	����������
*/
Chain::Chain()
{
	first = 0;
}
/*
	���캯��
	����������������
*/
Chain::Chain(Node * node)
{
	first = node;
}

/*
	��������
	ɾ�����нڵ�
*/
Chain::~Chain()
{
	Node *p;
	while (first) {
		p = first->link;
		delete first;
		first = p;
	}
}
/*
	����
	aΪ����������
*/
void Chain::Insert(int a)
{
	Node *p = new Node();	//�����½ڵ�
	p->data = a;	//Ϊ�½ڵ㸳ֵ
	if (first) {		
		p->link = first;	//ԭ����Ϊ�գ����½ڵ�����ͷ
		first = p;
	}
	else {
		first = p;	//ԭ����Ϊ�գ�ֱ�Ӹ�ֵ
	}
}
/*
	ɾ��
	aΪ��ɾԪ��
*/
void Chain::Delete(int a)
{
	Node *p = first;
	while (first&&first->data == a) {	//ѭ��ɾ��λ�ڿ�ͷ�Ķ�Ӧ�ڵ�
		first = first->link;
		delete p;
		p = first;
	}
	Node *dp;
	while (p&&p->link) {
		while (p->link&&p->link->data == a) {	//ѭ��ɾ���м�ڵ�
			dp = p->link;
			p->link = dp->link;
			delete dp;
		}
		p = p->link;
	}

}
/*
	����
	aΪ����Ԫ��
*/
int Chain::Search(int a)
{
	int index = 1;	//ָ��
	Node *p = first;
	while (p) {
		if (p->data == a) {	//�����ҵ�������index
			return index;
		}
		p = p->link;	//������
		index++;	//�Լ�
	}
	return 0;
}
/*
	�������
*/
void Chain::Output()
{
	Node *p = first;
	while (p) {
		cout << p->data << " "; //�����������
		p = p->link;
	}
}

/*
	������
	cΪ����
*/
ChainIterator::ChainIterator(const Chain & c)
{
	p = c.first;	//���ͷ�ڵ�
}

/*
	����
	���ط���������
*/
Chain* ChainIterator::Reverse()
{
	Chain *reverse = new Chain();	//���������
	Node *pt = p;
	while (pt) {
		reverse->Insert(pt->data);	//˳��ԭ�������ݲ����±��ͷ
		pt = pt->link;
	}
	return reverse;	//����������
}
/*
	�ϲ���������
	cΪ�ڶ�����
	���غϲ��������
*/
Chain * ChainIterator::Join(const Chain & c)
{
	Node *p2 = c.first;
	Chain *result = new Chain();
	while (p&&p2) {
		if (p->data < p2->data) {
			result->Insert(p->data);	//����СԪ���Ȳ�������
			p = p->link;
		}
		else {
			result->Insert(p2->data);
			p2 = p2->link;
		}
	}
	while (p) {
		result->Insert(p->data);	//��ʣ��δ�����Ԫ��ȫ������������
		p = p->link;
	}
	while (p2) {
		result->Insert(p2->data);
		p2 = p2->link;
	}
	ChainIterator *temp = new ChainIterator(*result);
	Chain *_result = temp->Reverse();	//���õ������ṩ�ķ����ܻ����������
	delete temp;
	delete result;
	return _result;
}
