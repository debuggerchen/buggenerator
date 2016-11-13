// PolyEval.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int PolyEval(int coeff[], int n, const int& x)
{
	int value = coeff[0], y = 1;
	for (int i = 1; i <= n; i++) {
		y *= x;
		value += coeff[i] * x;
	}
	return value;
}
int main()
{
	int coeff[] = { 1,2,1 };
	cout << PolyEval(coeff, 2, 1);
	int x;
	cin >> x;
    return 0;
}

