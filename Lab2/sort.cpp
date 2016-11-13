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
//����Ԫ��λ��
void sort::swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}
/*
	ѡ������
	listΪ�������飬lengthΪ���鳤��
*/
void sort::selectionSort(int list[], int length)
{
	int index = 0;
	for (int i = 0; i < length - 1; i++) {	//��һ��ѭ������λ��iС��Ԫ��
		index = i;							//index��¼��СԪ������λ��
		for (int j = i; j < length; j++) {	//�Դ�i������ĩβ��Ԫ�ؽ��б���
			if (list[j] < list[index])		//������ָ�С��Ԫ�أ�����index
				index = j;
		}
		swap(list[i], list[index]);			//����iС��Ԫ�ط����iλ
		cout << "����" << i + 1 << endl;
		for (int k = 0; k < length; k++) {
			cout << list[k] << " " ;		//�������
		}
		cout << endl;
	}
}
/*
	��������
	aΪ�������飬lengthΪ���鳤��
*/
void sort::InsertionSort(int a[], int length)
{
	for (int i = 1; i < length; i++) {					//ȷ����i������ǰԪ�ع��ɵ���������
		int temp = a[i];								//��¼��i��Ԫ��ֵ
		int j;
		for (j = i - 1; j >= 0 && a[j] > temp; j--) {	//�Ӻ���ǰ����a[i]Ӧ�ڵ�λ��
			a[j + 1] = a[j];							//��Ԫ��ֵ��temp���򽫸�Ԫ�غ���һλ
		}
		a[j + 1] = temp;								//ѭ�������󣬼�ȷ��a[i]Ӧ�ڵ�λ��
		cout << "����" << i << endl;						//�������
		for (int k = 0; k < length; k++) {
			cout << a[k] << " ";
		}
		cout << endl;
	}
}
/*
	ð�ݹ���
	listΪ���飬lengthΪ��Ҫ�������Ԫ��λ�õ����鳤��
*/
void sort::Bubble(int list[], int length)
{
	for (int i = 0; i < length - 1; i++) {				//��������
		if (list[i] > list[i + 1])						//���ϴ�Ԫ������
			swap(list[i], list[i + 1]);
	}													//����ѭ�������Ԫ������ĩβ
}
/*
	ð������
	listΪ���飬lengthΪ���鳤��
*/
void sort::BubbleSort(int list[], int length)
{
	for (int i = length; i > 1; i--) {					//ѭ��������i��Ԫ�ص�λ��
		Bubble(list, i);								//��ÿһ������ִ��ð�ݹ���
		cout << "����" << length - i + 1 << endl;		//�������
		for (int k = 0; k < length; k++) {
			cout << list[k] <<" ";
		}
		cout << endl;
	}
}
/*
	��������
	listΪ���飬aΪ������㣬bΪ�����յ㣬lengthΪ���鳤��
*/
void sort::quicksort(int list[], int a, int b,int length)
{
	if (a < b) {										//a=b�������������һ��Ԫ�أ�����
		int i = a, j = b;								//�½���ָ��
		while (i < j) {
			while (list[a] >= list[i] && i<j) {			//��ǰ���ɨ��Ȼ�׼Ԫ�ش��Ԫ��
				i++;
			}
			while (list[a] <= list[j] && i<j) {			//�Ӻ���ǰɨ��Ȼ�׼Ԫ��С��Ԫ��
				j--;
			}
			if (i == j&&list[a]<list[i]) {				//ָ���ཻ�����ɨ��
				break;
			}
			else if (i == j&&list[a] >= list[i]) {		//������׼Ԫ��λ��
				swap(list[a], list[i]);
				break;
			}
			swap(list[i], list[j]);						//����ɨ�赽��λ�ô����Ԫ��
		}

		quicksort(list, a, i - 1,length);				//�ݹ�����ʣ������
		quicksort(list, i, b,length);
		cout << "����" << endl;
		for (int m = 0; m < length; m++) {				//�������
			cout << list[m] << " ";
		}
		cout << endl;
	}
}
/*
	Merge
	���ڽ�������������ϲ�Ϊһ����������
	listΪ�������飬aΪ��һ��������㣬bΪ��һ�������յ㣬cΪ�ڶ��������յ�
*/
void sort::Merge(int list[], int a, int b, int c)
{
	int *temp = new int[c - a + 1];						//��ʱ���飬������������
	int ap = a, bp = b + 1, i;							//�½���ָ�룬�ֱ�ָʾ������
	for (i = 0; ap <= b&&bp <= c; i++) {				//��������Ԫ����������������
		if (list[ap] < list[bp])
			temp[i] = list[ap++];
		else
			temp[i] = list[bp++];
	}
	while (ap <= b)										//����ʣ������
		temp[i++] = list[ap++];
	while (bp <= c)
		temp[i++] = list[bp++];
	i = 0;
	for (int j = a; j <= c; j++) {						//���ϲ������鷵��ԭ����
		list[j] = temp[i++];
	}
}
/*
	�鲢����
	listΪ�������飬aΪ����������㣬bΪ���������յ㣬lengthΪԭ���鳤��
*/
void sort::MergeSort(int list[], int a, int b, int length)
{
	if (a < b) {										//a=bʱ�������򣬷���
		MergeSort(list, a, (a + b) / 2, length);		//�ݹ�����
		MergeSort(list, (a + b) / 2 + 1, b,length);
		Merge(list, a, (a + b) / 2, b);					//�ϲ�����
		cout << "����" << endl;							//�������
		for (int i = 0; i < length; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
}
/*
	���ڼ���������Ԫ����󳤶�
	listΪ��������
	������󳤶�
*/
int sort::maxLength(ChainNode * list)
{
	int max = 0;
	ChainNode *temp = list;
	while (temp) {
		max = (max < (log10(temp->data) + 1)) ? log10(temp->data) + 1 : max;
		//���ö��������ֳ���
		temp = temp->next;
	}
	return max;
}
/*
	��������
	listΪ��������
*/
ChainNode * sort::binSort(ChainNode * first)
{
	int length = maxLength(first), mod = 10, div = 1;//ȷ�����ֳ��ȣ�mod,div��������Ӧ��λֵ
	ChainNode **bottom, **top, *end = NULL;
	bottom = new ChainNode*[10];					//ָ�����飬�����Ӧֵ������
	top = new ChainNode*[10];

	for (int i = 0; i < 10; i++) {					//��ʼ������
		bottom[i] = NULL;
	}
	for (int i = 1; i <= length; i++) {
		while (first) {								//��Ԫ�ط�����Ӧ������
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
		for (int j = 0; j < 10; j++) {				//˳��ȡ������
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
		for (int k = 0; k < 10; k++) {				//�ٴγ�ʼ������
			bottom[k] = NULL;
			top[k] = NULL;
		}
		mod *= 10;									//*10������һλֵ
		div *= 10;
	}
	return first;
}
