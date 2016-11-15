#include "stdafx.h"
#include "Chain.h"
#include <iostream>
#include "Node.h"
using namespace std;
/*
	构造函数
	创建新链表
*/
Chain::Chain()
{
	first = 0;
}
/*
	构造函数
	从已有链创建链表
*/
Chain::Chain(Node * node)
{
	first = node;
}

/*
	析构函数
	删除所有节点
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
	插入
	a为待插入数据
*/
void Chain::Insert(int a)
{
	Node *p = new Node();	//创建新节点
	p->data = a;	//为新节点赋值
	if (first) {		
		p->link = first;	//原链表不为空，将新节点插入表头
		first = p;
	}
	else {
		first = p;	//原链表为空，直接赋值
	}
}
/*
	删除
	a为待删元素
*/
void Chain::Delete(int a)
{
	Node *p = first;
	while (first&&first->data == a) {	//循环删除位于开头的对应节点
		first = first->link;
		delete p;
		p = first;
	}
	Node *dp;
	while (p&&p->link) {
		while (p->link&&p->link->data == a) {	//循环删除中间节点
			dp = p->link;
			p->link = dp->link;
			delete dp;
		}
		p = p->link;
	}

}
/*
	查找
	a为待查元素
*/
int Chain::Search(int a)
{
	int index = 1;	//指针
	Node *p = first;
	while (p) {
		if (p->data == a) {	//若查找到，返回index
			return index;
		}
		p = p->link;	//向后查找
		index++;	//自加
	}
	return 0;
}
/*
	输出链表
*/
void Chain::Output()
{
	Node *p = first;
	while (p) {
		cout << p->data << " "; //遍历链表并输出
		p = p->link;
	}
}

/*
	迭代器
	c为链表
*/
ChainIterator::ChainIterator(const Chain & c)
{
	p = c.first;	//获得头节点
}

/*
	反向
	返回反向后的链表
*/
Chain* ChainIterator::Reverse()
{
	Chain *reverse = new Chain();	//反向后链表
	Node *pt = p;
	while (pt) {
		reverse->Insert(pt->data);	//顺序将原链表数据插入新表表头
		pt = pt->link;
	}
	return reverse;	//返回新链表
}
/*
	合并有序链表
	c为第二链表
	返回合并后的链表
*/
Chain * ChainIterator::Join(const Chain & c)
{
	Node *p2 = c.first;
	Chain *result = new Chain();
	while (p&&p2) {
		if (p->data < p2->data) {
			result->Insert(p->data);	//将较小元素先插入链表
			p = p->link;
		}
		else {
			result->Insert(p2->data);
			p2 = p2->link;
		}
	}
	while (p) {
		result->Insert(p->data);	//将剩余未插入的元素全部插入新链表
		p = p->link;
	}
	while (p2) {
		result->Insert(p2->data);
		p2 = p2->link;
	}
	ChainIterator *temp = new ChainIterator(*result);
	Chain *_result = temp->Reverse();	//利用迭代器提供的反向功能获得升序链表
	delete temp;
	delete result;
	return _result;
}
