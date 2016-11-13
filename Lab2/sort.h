#pragma once
#include "ChainNode.h"
class sort
{
public:
	sort();
	~sort();
	static void swap(int& x, int& y);
	static void selectionSort(int list[], int length);
	static void InsertionSort(int a[], int length);
	static void Bubble(int list[], int length);
	static void BubbleSort(int list[], int length);
	static void quicksort(int list[], int a, int b,int length);
	static void Merge(int list[], int a, int b, int c);
	static void MergeSort(int list[], int a, int b,int length);
	static int maxLength(ChainNode *list);
	static ChainNode* binSort(ChainNode *first);
};

