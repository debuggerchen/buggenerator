// Lab2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "sort.h"
using namespace std;
int main()
{
	cout << "数组长度："<<endl;
	int length;
	cin >> length;
	int *a=new int[length];
	for (int i = 0; i < length; i++)
	{
		cout << "输入第" << i + 1 << "个元素" << endl;
		cin >> a[i];
	}
	cout << "1.选择排序" << endl << "2.插入排序" << endl << "3.冒泡排序" << endl << "4.归并排序" << endl << "5.快速排序" << endl;
	int type;
	cin >> type;
	switch (type)
	{
	default:
		break;
	case 1:
		sort::selectionSort(a,length);
		break;
	case 2:
		sort::InsertionSort(a, length);
		break;
	case 3:
		sort::BubbleSort(a, length);
		break;
	case 4:
		sort::MergeSort(a, 0, length - 1,length);
		break;
	case 5:
		sort::quicksort(a, 0, length - 1,length);
		break;
	}
	cout << "结果" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	int b;
	cin >> b;
    return 0;
}

