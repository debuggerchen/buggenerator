#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
}
/*
	��ջ
*/
void Stack::push(Node *i)
{
	i->link = list;
	list = i;
}
/*
	��ջ
*/
Node * Stack::pop()
{
	Node * p = list;
	if (list) {
		list = list->link;
		p->link = NULL;
	}
	return p;
}
/*
	���ص�һԪ��
*/
Node * Stack::Get()
{
	return list;
}
