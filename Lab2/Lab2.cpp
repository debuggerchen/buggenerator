// Lab2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "sort.h"
using namespace std;
int main()
{
	cout << "���鳤�ȣ�"<<endl;
	int length;
	cin >> length;
	int *a=new int[length];
	for (int i = 0; i < length; i++)
	{
		cout << "�����" << i + 1 << "��Ԫ��" << endl;
		cin >> a[i];
	}
	cout << "1.ѡ������" << endl << "2.��������" << endl << "3.ð������" << endl << "4.�鲢����" << endl << "5.��������" << endl;
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
	cout << "���" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	int b;
	cin >> b;
    return 0;
}

