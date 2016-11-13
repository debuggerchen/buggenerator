// BinSort.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "����" << i << endl;
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
	cout << "���ݳ��ȣ�" << endl;
	int length;
	cin >> length;
	int data;
	cout << "��1��Ԫ��" << endl;
	
	cin >> data;
	chainNode *first = new chainNode(data);
	chainNode *end = first;
	for (int i = 2; i <= length ; i++) {
		cout << "��" << i << "��Ԫ��" << endl;
		cin >> data;
		chainNode *node = new chainNode(data);
		end->next = node;
		end = node;
	}


	chainNode *r=binSort(first);
	//chainNode *p = r;
	cout << "���:" << endl;
	while (r) {
		cout << r->data<<" ";
		r = r->next;

	}
	int g;
	cin >> g;
    return 0;
}

