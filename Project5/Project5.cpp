// Project5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;
int main()
{
	cout << "������ʽ��" << endl;
	string i;
	cin >> i;
	Calculator t(i);
	cout << "��׺���ʽ��" << endl;
	cout << t.Postfix() << endl;
	cout << "���:" << endl;
	cout << t.Calc() << endl;
	int j;
	cin >> j;
    return 0;
}

