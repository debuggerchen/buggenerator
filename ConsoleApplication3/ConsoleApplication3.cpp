// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"

using namespace std;
/*��������Ԫ��x,y*/
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
/*����
	listΪ����������
	startΪ����ͷԪ��ָ��
	lengthΪ�����ܳ�
*/
void Perm(int list[], int start, int length) {
	if (start == length)					//ͷָ��������鳤�ȣ��ݹ����
	{
		for (int i = 0; i < length; i++)
			cout << list[i] << " ";			//�������
		cout << endl;
	}
	else
	{
		for (int i = start; i < length; i++) {
			swap(list[start], list[i]);		//�������п��ܵ�ͷԪ��
			Perm(list, start + 1, length);	//�ݹ�����ʣ��Ԫ��
			swap(list[start], list[i]);		//��ԭ����ǰ����
		}
	}

}

int main()
{
	cout << "�������鳤��:" << endl;	
	int length;
	cin >> length;							//�������鳤��
	int *a = new int[length];
	for (int i = 0; i < length; i++) {
		cout << "�����" << i + 1 << "��Ԫ��:" << endl;	//��������Ԫ��
		cin >> a[i];
	}
	Perm(a, 0, length);		//���õݹ鷽��
	int b;
	cin >> b;
	return 0;
}

