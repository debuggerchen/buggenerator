// gcd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

int main()
{
	int x, y;
	cin >> x;
	cin >> y;
	cout << gcd(x, y);
	int z;
	cin >> z;
	return 0;
}

