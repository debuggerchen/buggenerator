#include "stdafx.h"
#include "HashChain.h"



HashChain::HashChain(int div)
{
	D = div;
	hc = new Node*[D];	//�½�����D�����飬���ͷ�ڵ�
	for (int i = 0; i < div; i++) {	//��ʼ��
		hc[i] = NULL;
	}
}

HashChain::~HashChain()
{
}
/*
	Insert
	���½ڵ������Ӧ����ͷ�ڵ㴦
	valueΪ����Ԫ��
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
	��λ��������Ӧģ��������
	valueΪ����Ԫ��
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
