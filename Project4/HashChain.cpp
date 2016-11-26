#include "stdafx.h"
#include "HashChain.h"



HashChain::HashChain(int div)
{
	D = div;
	hc = new Node*[D];	//新建长度D的数组，存放头节点
	for (int i = 0; i < div; i++) {	//初始化
		hc[i] = NULL;
	}
}

HashChain::~HashChain()
{
}
/*
	Insert
	将新节点插入相应链表头节点处
	value为待查元素
*/
void HashChain::Insert(int value)
{
	int i = value%D;
	Node *node = new Node();
	node->data = value;
	node->link = hc[i];
	hc[i] = node;
}

/*
	Search
	定位并遍历相应模数的链表
	value为待查元素
*/
bool HashChain::Search(int value)
{
	int i = value%D;
	Node *p = hc[i];
	while (p&&p->data != value) {
		p = p->link;
	}
	if (p) return true;
	else return false;
	return 0;
}
