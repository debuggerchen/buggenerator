#include "stdafx.h"
#include "MStack.h"


MStack::MStack()
{
}


MStack::~MStack()
{
}

/*
	��a,b��Ϊ����ѹ��ջ
*/
void MStack::push(int a, int b)
{
	Route * r = new Route();
	r->x = a;
	r->y = b;
	r->link = head;
	head = r;

}

//��ջ
Route * MStack::pop()
{
	Route * p = head;
	if (head) {
		head = head->link;
		p->link = NULL;
		return p;
	}
	return NULL;
}

//���ص�ǰ�ڵ�
Route * MStack::get()
{
	return head;
}
