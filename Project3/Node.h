#pragma once
//#include "Chain.h"
#include <iostream>
using namespace std;
class Node {
	friend class Chain;
	friend class ChainIterator;
private:
	int data;	//����
	Node *link;	//�ڵ�ָ��
};
