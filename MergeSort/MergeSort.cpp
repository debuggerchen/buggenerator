// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void Merge(int list[], int a, int b, int c) {
	int *temp = new int[c - a + 1];
	int ap = a, bp = b + 1, i;
	for (i = 0; ap <= b&&bp <= c; i++) {
		if (list[ap] < list[bp])
			temp[i] = list[ap++];
		else
			temp[i] = list[bp++];
	}
	while (ap <= b)
		temp[i++] = list[ap++];
	while (bp <= c)
		temp[i++] = list[bp++];
	i = 0;
	for (int j = a; j <= c; j++) {
		list[j] = temp[i++];
	}
}
void MergeSort(int list[], int a, int b) {
	if (a < b) {
		MergeSort(list, a, (a + b) / 2);
		MergeSort(list, (a + b) / 2 + 1, b);
		Merge(list, a, (a + b) / 2, b);
	}
}


int main()
{
	int a[] = { 5,4,2,8,7,9,6,3,1 };
	MergeSort(a, 0, 8);
	for (int i = 0; i < 9; i++)
		cout << a[i];
	int j;
	cin >> j;
    return 0;
}

