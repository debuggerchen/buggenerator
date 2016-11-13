#include "stdafx.h"
#include "sort.h"
#include <iostream>
#include <math.h>
using namespace std;
sort::sort()
{
}


sort::~sort()
{
}
//交换元素位置
void sort::swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}
/*
	选择排序
	list为输入数组，length为数组长度
*/
void sort::selectionSort(int list[], int length)
{
	int index = 0;
	for (int i = 0; i < length - 1; i++) {	//第一层循环，定位第i小的元素
		index = i;							//index记录最小元素所在位置
		for (int j = i; j < length; j++) {	//对从i到数组末尾的元素进行遍历
			if (list[j] < list[index])		//如果发现更小的元素，更新index
				index = j;
		}
		swap(list[i], list[index]);			//将第i小的元素放入第i位
		cout << "过程" << i + 1 << endl;
		for (int k = 0; k < length; k++) {
			cout << list[k] << " " ;		//过程输出
		}
		cout << endl;
	}
}
/*
	插入排序
	a为输入数组，length为数组长度
*/
void sort::InsertionSort(int a[], int length)
{
	for (int i = 1; i < length; i++) {					//确定由i及起以前元素构成的有序数组
		int temp = a[i];								//记录第i个元素值
		int j;
		for (j = i - 1; j >= 0 && a[j] > temp; j--) {	//从后向前查找a[i]应在的位置
			a[j + 1] = a[j];							//若元素值比temp大，则将该元素后移一位
		}
		a[j + 1] = temp;								//循环结束后，即确定a[i]应在的位置
		cout << "过程" << i << endl;						//过程输出
		for (int k = 0; k < length; k++) {
			cout << a[k] << " ";
		}
		cout << endl;
	}
}
/*
	冒泡过程
	list为数组，length为需要调整最大元素位置的数组长度
*/
void sort::Bubble(int list[], int length)
{
	for (int i = 0; i < length - 1; i++) {				//遍历数组
		if (list[i] > list[i + 1])						//将较大元素右移
			swap(list[i], list[i + 1]);
	}													//结束循环后最大元素移至末尾
}
/*
	冒泡排序
	list为数组，length为数组长度
*/
void sort::BubbleSort(int list[], int length)
{
	for (int i = length; i > 1; i--) {					//循环调整第i大元素的位置
		Bubble(list, i);								//对每一段数组执行冒泡过程
		cout << "过程" << length - i + 1 << endl;		//过程输出
		for (int k = 0; k < length; k++) {
			cout << list[k] <<" ";
		}
		cout << endl;
	}
}
/*
	快速排序
	list为数组，a为排序起点，b为排序终点，length为数组长度
*/
void sort::quicksort(int list[], int a, int b,int length)
{
	if (a < b) {										//a=b即待排数组仅含一个元素，返回
		int i = a, j = b;								//新建两指针
		while (i < j) {
			while (list[a] >= list[i] && i<j) {			//从前向后扫描比基准元素大的元素
				i++;
			}
			while (list[a] <= list[j] && i<j) {			//从后向前扫描比基准元素小的元素
				j--;
			}
			if (i == j&&list[a]<list[i]) {				//指针相交后结束扫描
				break;
			}
			else if (i == j&&list[a] >= list[i]) {		//调整基准元素位置
				swap(list[a], list[i]);
				break;
			}
			swap(list[i], list[j]);						//交换扫描到的位置错误的元素
		}

		quicksort(list, a, i - 1,length);				//递归排序剩余数组
		quicksort(list, i, b,length);
		cout << "过程" << endl;
		for (int m = 0; m < length; m++) {				//过程输出
			cout << list[m] << " ";
		}
		cout << endl;
	}
}
/*
	Merge
	用于将两个有序数组合并为一个有序数组
	list为待排数组，a为第一段数组起点，b为第一段数组终点，c为第二段数组终点
*/
void sort::Merge(int list[], int a, int b, int c)
{
	int *temp = new int[c - a + 1];						//临时数组，存放排序后数组
	int ap = a, bp = b + 1, i;							//新建两指针，分别指示两数组
	for (i = 0; ap <= b&&bp <= c; i++) {				//将两数组元素至入新有序数组
		if (list[ap] < list[bp])
			temp[i] = list[ap++];
		else
			temp[i] = list[bp++];
	}
	while (ap <= b)										//填入剩余数组
		temp[i++] = list[ap++];
	while (bp <= c)
		temp[i++] = list[bp++];
	i = 0;
	for (int j = a; j <= c; j++) {						//将合并后数组返回原数组
		list[j] = temp[i++];
	}
}
/*
	归并排序
	list为待排数组，a为待排数组起点，b为待排数组终点，length为原数组长度
*/
void sort::MergeSort(int list[], int a, int b, int length)
{
	if (a < b) {										//a=b时无需排序，返回
		MergeSort(list, a, (a + b) / 2, length);		//递归排序
		MergeSort(list, (a + b) / 2 + 1, b,length);
		Merge(list, a, (a + b) / 2, b);					//合并数组
		cout << "过程" << endl;							//过程输出
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}
/*
	用于计算链表中元素最大长度
	list为待求链表
	返回最大长度
*/
int sort::maxLength(ChainNode * list)
{
	int max = 0;
	ChainNode *temp = list;
	while (temp) {
		max = (max < (log10(temp->data) + 1)) ? log10(temp->data) + 1 : max;
		//利用对数求数字长度
		temp = temp->next;
	}
	return max;
}
/*
	基数排序
	list为待排链表
*/
ChainNode * sort::binSort(ChainNode * first)
{
	int length = maxLength(first), mod = 10, div = 1;//确定数字长度，mod,div用于求相应数位值
	ChainNode **bottom, **top, *end = NULL;
	bottom = new ChainNode*[10];					//指针数组，存放相应值的链表
	top = new ChainNode*[10];

	for (int i = 0; i < 10; i++) {					//初始化数组
		bottom[i] = NULL;
	}
	for (int i = 1; i <= length; i++) {
		while (first) {								//将元素分入相应链表中
			int data = first->data;
			int num = data%mod / div;
			if (bottom[num] == NULL) {
				bottom[num] = first;
			}
			else {
				top[num]->next = first;
			}
			top[num] = first;
			first = first->next;
			top[num]->next = NULL;

		}
		for (int j = 0; j < 10; j++) {				//顺序取出链表
			if (bottom[j] == NULL) {
				continue;
			}
			if (first == NULL) {
				first = bottom[j];
			}
			else {
				end->next = bottom[j];
			}
			end = top[j];
		}
		for (int k = 0; k < 10; k++) {				//再次初始化数组
			bottom[k] = NULL;
			top[k] = NULL;
		}
		mod *= 10;									//*10，求下一位值
		div *= 10;
	}
	return first;
}
