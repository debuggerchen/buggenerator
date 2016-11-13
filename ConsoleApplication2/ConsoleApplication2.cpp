// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
bool *isIn;	//标记元素是否在子集中
/*subset
	list为原集合
	start为头指针
	length为数组长度
*/
void subset(int list[], int start, int length) {
	if (start == length)
	{
		cout << "{";
		for (int i = 0; i < length; i++)	//按照isIn中信息进行输出
		{
			if (isIn[i] == true)
				cout << list[i];
		}
		cout << "}" << endl;
	}
	else {
		isIn[start] = true;
		subset(list, start + 1, length);	//当前指针所在元素在子集中时，对剩余集合求子集
		isIn[start] = false;
		subset(list, start + 1, length);	//当前指针所在元素不在子集中时，对剩余集合求子集
	}
}

void main()
{
	int length;
	cout << "输入集合长度：" << endl;	//输入数组长度
	cin >> length;
	int *list = new int[length];
	isIn = new bool[length];
	for (int i = 0; i < length; i++) {
		cout << "输入第" << i + 1 << "个元素：" << endl;	//输入数组元素
		cin >> list[i];
	}
	//int list[] = { 1,2,3 };
	subset(list, 0, length);	//调用递归函数
	int c;
	cin >> c;
}


