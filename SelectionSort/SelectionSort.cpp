// SelectionSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void selectionSort(int list[], int length) {
	int index = 0;
	for (int i = 0; i < length-1; i++) {
		index = i;
		for (int j = i; j < length; j++) {
			if (list[j] < list[index])
				index = j;
		}
		swap(list[i], list[index]);
	}
}

int main()
{
	int list[] = { 3,5,7,4,1,6,8,9,2 };
	selectionSort(list, 9);
	for (int i = 0; i < 9; i++) {
		cout << list[i];
	}
	int j;
	cin >> j;
    return 0;
}

