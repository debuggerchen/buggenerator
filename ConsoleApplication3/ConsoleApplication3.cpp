// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;
/*交换数组元素x,y*/
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
/*排列
	list为待排列数组
	start为数组头元素指针
	length为数组总长
*/
void Perm(int list[], int start, int length) {
	if (start == length)					//头指针等于数组长度，递归结束
	{
		for (int i = 0; i < length; i++)
			cout << list[i] << " ";			//输出数组
		cout << endl;
	}
	else
	{
		for (int i = start; i < length; i++) {
			swap(list[start], list[i]);		//交换所有可能的头元素
			Perm(list, start + 1, length);	//递归排列剩余元素
			swap(list[start], list[i]);		//还原交换前数组
		}
	}

}

int main()
{
	cout << "输入数组长度:" << endl;	
	int length;
	cin >> length;							//输入数组长度
	int *a = new int[length];
	for (int i = 0; i < length; i++) {
		cout << "输入第" << i + 1 << "个元素:" << endl;	//输入数组元素
		cin >> a[i];
	}
	Perm(a, 0, length);		//调用递归方法
	int b;
	cin >> b;
	return 0;
}

