// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}
void swap2(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int x = 1;
	int y = 2;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	swap(x, y);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	swap2(x, y);
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	int a;
	cin >> a;
    return 0;
}

