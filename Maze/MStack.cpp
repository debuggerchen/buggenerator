#include "stdafx.h"
#include "MStack.h"


MStack::MStack()
{
}


MStack::~MStack()
{
}

/*
	将a,b作为坐标压入栈
*/
void MStack::push(int a, int b)
{
	Route * r = new Route();
	r->x = a;
	r->y = b;
	r->link = head;
	head = r;

}

//出栈
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

//返回当前节点
Route * MStack::get()
{
	return head;
}
