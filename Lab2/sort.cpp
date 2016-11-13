#include "stdafx.h"
#include "sort.h"
#include <iostream>
using namespace std;
sort::sort()
{
}


sort::~sort()
{
}

void sort::swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

void sort::selectionSort(int list[], int length)
{
	int index = 0;
	for (int i = 0; i < length - 1; i++) {
		index = i;
		for (int j = i; j < length; j++) {
			if (list[j] < list[index])
				index = j;
		}
		swap(list[i], list[index]);
		for (int i = 0; i < length; i++) {
			cout << list[i] << " " ;
		}
		cout << endl;
	}
}

void sort::InsertionSort(int a[], int length)
{
	for (int i = 1; i < length; i++) {
		int temp = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > temp; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
		for (int i = 0; i < length; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

void sort::Bubble(int list[], int length)
{
	for (int i = 0; i < length - 1; i++) {
		if (list[i] > list[i + 1])
			swap(list[i], list[i + 1]);
	}
}

void sort::BubbleSort(int list[], int length)
{
	for (int i = length; i > 1; i--) {
		Bubble(list, i);
		for (int i = 0; i < length; i++) {
			cout << list[i] <<" ";
		}
		cout << endl;
	}
}

void sort::quicksort(int list[], int a, int b,int length)
{
	if (a < b) {
		int i = a, j = b;
		while (i < j) {
			while (list[a] >= list[i] && i<j) {
				i++;
			}
			while (list[a] <= list[j] && i<j) {
				j--;
			}
			if (i == j&&list[a]<list[i]) {
				break;
			}
			else if (i == j&&list[a] >= list[i]) {
				swap(list[a], list[i]);
				break;
			}
			swap(list[i], list[j]);
		}

		quicksort(list, a, i - 1,length);
		quicksort(list, i, b,length);
		for (int m = 0; m < length; m++) {
			cout << list[m] << " ";
		}
		cout << endl;
	}
}

void sort::Merge(int list[], int a, int b, int c)
{
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

void sort::MergeSort(int list[], int a, int b, int length)
{
	if (a < b) {
		MergeSort(list, a, (a + b) / 2, length);
		MergeSort(list, (a + b) / 2 + 1, b,length);
		Merge(list, a, (a + b) / 2, b);
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}
