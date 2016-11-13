// BinSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "chainNode.h"
#include <iostream>
#include <math.h>
using namespace std;
int maxLength(chainNode *list) {
	int max = 0;
	chainNode *temp = list;
	while (temp) {
		max = (max < (log10(temp->data) + 1)) ? log10(temp->data) + 1 : max;
		temp = temp->next;
	}
	return max;
}

chainNode* binSort(chainNode *first) {
	int length = maxLength(first), mod = 10, div = 1;
	chainNode **bottom, **top,*end=NULL;
	bottom = new chainNode*[10];
	top = new chainNode*[10];

	for (int i = 0; i < 10; i++) {
		bottom[i] = NULL;
	}
	for (int i = 1; i <= length; i++) {
		while (first) {
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
		for (int j = 0; j < 10; j++) {
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
		cout << "过程" << i << endl;
		chainNode* temp = first;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
		for (int k = 0; k < 10; k++) {
			bottom[k] = NULL;
			top[k] = NULL;
		}
		mod *= 10;
		div *= 10;
	}
	return first;
}
int main()
{
	cout << "数据长度：" << endl;
	int length;
	cin >> length;
	int data;
	cout << "第1个元素" << endl;
	
	cin >> data;
	chainNode *first = new chainNode(data);
	chainNode *end = first;
	for (int i = 2; i <= length ; i++) {
		cout << "第" << i << "个元素" << endl;
		cin >> data;
		chainNode *node = new chainNode(data);
		end->next = node;
		end = node;
	}


	chainNode *r=binSort(first);
	//chainNode *p = r;
	cout << "结果:" << endl;
	while (r) {
		cout << r->data<<" ";
		r = r->next;

	}
	int g;
	cin >> g;
    return 0;
}

