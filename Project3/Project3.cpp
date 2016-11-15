// Project3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Chain.h"
#include <iostream>
using namespace std;
Chain chain;	//目标链表
/*
	向链表c插入数据data
	c为指定链表
	data为数据
*/
void Insert(Chain & c, int data) {	
	c.Insert(data);
}
/*
	向链表c插入数据
	c为指定链表
*/
void Insert(Chain & c) {			
	int length;	//定义数据长度						
	cout << "输入数据长度：" << endl;
	cin >> length;
	for (int i = 1; i <= length; i++) {
		int j;
		cout << "数据" << i << endl;
		cin >> j;
		Insert(c,j);	//循环向链表c插入数据
	}
}
/*
	查找
	显示指定元素所在位置
*/
void Search() {
	int target;	//待查元素
	cout << "输入查找元素:" << endl;
	cin >> target;
	cout << "结果" << endl;
	cout << chain.Search(target) << endl;	//调用查找功能
}
/*
	删除
	从链表中删除指定元素
*/
void Delete() {
	int target;	//指定元素
	cout << "输入删除元素:" << endl;
	cin >> target;
	chain.Delete(target);	//调用删除功能
}
/*
	输出链表
*/
void Output() {
	cout << "结果:" << endl;
	chain.Output();	//调用输出功能
	cout << endl;
}
/*
	反向输出功能
	反向输出链表内容
*/
void Reverse() {
	ChainIterator *it = new ChainIterator(chain);	//初始化迭代器
	Chain *reverse = it->Reverse();	//调用反向函数，将反向链表存入新链
	cout << "结果:" << endl;
	reverse->Output();	//输出新链表
	cout << endl;
	delete reverse;	//释放内存
	delete it;
}
/*
	合并有序链表
	输入两有序链表，显示合并后链表数据
*/
void Join() {
	Chain *a = new Chain();	//两条待合并链
	Chain *b = new Chain();
	cout << "输入第一组数据" << endl;
	Insert(*a);	//插入元素
	cout << "输入第二组数据" << endl;
	Insert(*b);
	ChainIterator *c = new ChainIterator(*a);
	Chain *result = c->Join(*b);	//调用合并函数，将新链存入result
	cout << "结果:" << endl;
	result->Output();	//输出
	cout << endl;
	delete result;	//释放内存
	delete c;
	delete b;
	delete a;
}
int main()
{
	bool exit = false;	//指示退出状态
	while (!exit) {
		cout << "选择操作：" << endl;
		cout << "1.插入元素" << endl;
		cout << "2.查找元素" << endl;
		cout << "3.删除元素" << endl;
		cout << "4.显示链表" << endl;
		cout << "5.反序输出" << endl;
		cout << "6.有序链表合并" << endl;
		cout << "其他.退出" << endl;
		int option;	//选项
		cin >> option;
		switch (option)	//根据选项调用相应功能
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

