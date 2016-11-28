// Project5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;
int main()
{
	cout << "输入表达式：" << endl;
	string i;
	cin >> i;
	Calculator t(i);
	cout << "后缀表达式：" << endl;
	cout << t.Postfix() << endl;
	cout << "结果:" << endl;
	cout << t.Calc() << endl;
	int j;
	cin >> j;
    return 0;
}

