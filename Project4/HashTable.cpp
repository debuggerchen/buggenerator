#include "stdafx.h"
#include "HashTable.h"
#include <iostream>
using namespace std;


HashTable::HashTable(int div)
{
	D = div;	//D为除数
	ht = new int[D];	//存储数组
	empty = new bool[D];	//判定是否为空
	for (int i = 0; i < D; i++)	//初始化
		empty[i] = true;
}

HashTable::~HashTable()
{
}

/*
	插入
	value为插入值
*/
void HashTable::Insert(int value)
{
	int i = Search(value); //利用Search返回搜索停止时的终点
	if (empty[i]) {
		empty[i] = false;		//为空，则说明找到插入位置，将数据插入
		ht[i] = value;
		return;
	}
	if (empty[i] == value) {	//若停止位置恰为该元素，说明元素已存在，退出
		cout << "数据重复" << endl;
	}
	else {						//否则，表中无空闲位置
		cout << "表已满" << endl;
	}
	return;
}
/*
	Search
	value 待查元素
*/
int HashTable::Search(int value)
{
	int i = value%D;
	int j = i;	//遍历指针
	do {
		if (empty[j]||ht[j] == value)
			return j;	//若找到空值，则说明不存在，若找到value值，说明存在，返回停止时索引
		j = (j + 1) % D;
	} while (i != j); //回到起点时说明未找到，终止

	return j;
}

int HashTable::Get(int index)
{
	return ht[index]; //读出元素

}
