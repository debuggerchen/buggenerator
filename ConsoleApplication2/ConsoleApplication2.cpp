// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
using namespace std;
bool *isIn;	//���Ԫ���Ƿ����Ӽ���
/*subset
	listΪԭ����
	startΪͷָ��
	lengthΪ���鳤��
*/
void subset(int list[], int start, int length) {
	if (start == length)
	{
		cout << "{";
		for (int i = 0; i < length; i++)	//����isIn����Ϣ�������
		{
			if (isIn[i] == true)
				cout << list[i];
		}
		cout << "}" << endl;
	}
	else {
		isIn[start] = true;
		subset(list, start + 1, length);	//��ǰָ������Ԫ�����Ӽ���ʱ����ʣ�༯�����Ӽ�
		isIn[start] = false;
		subset(list, start + 1, length);	//��ǰָ������Ԫ�ز����Ӽ���ʱ����ʣ�༯�����Ӽ�
	}
}

void main()
{
	int length;
	cout << "���뼯�ϳ��ȣ�" << endl;	//�������鳤��
	cin >> length;
	int *list = new int[length];
	isIn = new bool[length];
	for (int i = 0; i < length; i++) {
		cout << "�����" << i + 1 << "��Ԫ�أ�" << endl;	//��������Ԫ��
		cin >> list[i];
	}
	//int list[] = { 1,2,3 };
	subset(list, 0, length);	//���õݹ麯��
	int c;
	cin >> c;
}


