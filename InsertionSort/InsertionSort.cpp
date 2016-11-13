// InsertionSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void InsertionSort(int a[], int length) {
	for (int i = 1; i < length; i++) {
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > temp ; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

int main()
{
	int a[] = { 2,1,5,8,7,4,6,9,3 };
	InsertionSort(a, 9);
	for (int i = 0; i < 9; i++) {
		cout << a[i];
	}
	int c;
	cin >> c;
    return 0;
}

