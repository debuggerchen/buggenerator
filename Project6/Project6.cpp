// Project6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinTree.h"
#include <iostream>

using namespace std;

int main()
{
	BinTree t;
	Tree *t1 = t.form('G', NULL, NULL);
	Tree *t2 = t.form('H', NULL, NULL);
	Tree *t3 = t.form('I', NULL, NULL);
	Tree *t4 = t.form('J', NULL, NULL);
	Tree *t5 = t.form('D', t1, NULL);
	Tree *t6 = t.form('E', NULL, t2);
	Tree *t7 = t.form('F', t3, t4);
	Tree *t8 = t.form('B', t5, t6);
	Tree *t9 = t.form('C', t7, NULL);
	Tree *t10 = t.form('A', t8, t9);
	t.setRoot(t10);
	cout << "pre" << endl;
	t.preOrder();
	cout << endl;
	cout << "in" << endl;
	t.inOrder();
	cout << endl;
	cout << "post" << endl;
	t.postOrder();
	cout << endl;
	cout << "level" << endl;
	t.levelOrder();
	cout << endl;
	cout << "size" << endl;
	cout << t.size() << endl;
	cout << "height" << endl;
	cout << t.height() << endl;
	char *pre = "ABDGEHCFIJ";
	char *in = "GDBEHAIFJC";
	Tree * a = t.PreIn2Post(pre, in, 0, 9, 0, 9);
	BinTree b;
	b.setRoot(a);
	b.postOrder();
	int j;
	cin >> j;
	return 0;
}

