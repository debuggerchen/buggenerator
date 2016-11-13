#include "stdafx.h"
#include "ChainNode.h"


ChainNode::ChainNode(int a)
{
	data = a;
	next = NULL;
}


ChainNode::~ChainNode()
{
}

void ChainNode::insert(int a)
{
	ChainNode *node = new ChainNode(a);
	this->next = node;
}

