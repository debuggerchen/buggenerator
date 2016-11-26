 //Project4.cpp : 定义控制台应用程序的入口点。


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
	//矩阵操作
	SparseMatrix x;
	x.Insert();
	cout << "矩阵内容：" << endl;
	x.Output();
	cout << "转置" << endl;
	SparseMatrix *y=x.transpose();
	y->Output();
	cout << "输入新矩阵" << endl;
	SparseMatrix z;
	z.Insert();
	cout << "矩阵内容：" << endl;
	z.Output();
	SparseMatrix *t = x.add(z);
	cout << "加和结果：" << endl;
	t->Output();


	//生成500个随机数
	vector<int> temp;
	for (int i = 0; i < 2000; i++) {
		temp.push_back(i + 1);
	}
	random_shuffle(temp.begin(), temp.end());
	int *a = new int[temp.size()];
	for (int i = 0; i < temp.size(); i++) {
		a[i] = temp[i];
	}

	//线性散列表
	HashTable *ht=new HashTable(961);
	for (int i = 0; i < 500; i++) {
		ht->Insert(a[i]);	//插入数据
	}
	//查询结果
	while (true) {
		int s;
		cout << "输入线性散列表查询内容，输入-1退出" << endl;
		cin >> s;
		if (s == -1) {
			break;
		}
		else {
			cout << "结果" << endl;
			int i = ht->Search(s);
			if (ht->Get(i) == s)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		
	}
	//链表散列表
	HashChain *hc = new HashChain(961);
	for (int i = 0; i < 500; i++) {
		hc->Insert(a[i]);	//插入数据
	}

	//查询结果
	while (true) {
		int s;
		cin >> s;
		cout << "输入链表散列表查询内容，输入-1退出" << endl;
		if (s == -1) {
			break;
		}
		else {
			cout << "查询结果：" << endl;
			cout << hc->Search(s) << endl;
		}
		
	}
	
	int j;
	cin >> j;
    return 0;
}

