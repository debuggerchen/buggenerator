#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
}
/*
	入栈
*/
void Stack::push(Node *i)
{
	i->link = list;
	list = i;
}
/*
	出栈
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
	返回第一元素
*/
Node * Stack::Get()
{
	return list;
}
