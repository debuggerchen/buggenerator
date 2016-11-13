// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
void quicksort(int list[], int a, int b) {
	if (a < b) {
		int i = a, j = b;
		while (i < j) {
			while (list[a] >= list[i]&&i<j) {
				i++;
			}
			while (list[a] <= list[j]&&i<j) {
				j--;
			}
			if (i==j&&list[a]<list[i]) {
				break;
			}
			else if (i == j&&list[a] >= list[i]) {
				swap(list[a], list[i]);
				break;
			}
			swap(list[i], list[j]);
		}
		
		quicksort(list, a, i - 1);
		quicksort(list, i, b);
	}
	

}

int main()
{
	int b[] = { 5,7,8,9,6,4,1,2,3 };
	quicksort(b, 0, 8);
	for (int i = 0; i < 9; i++) {
		cout << b[i];
	}
	int bbb;
	cin >> bbb;
    return 0;
}

