#include "stdafx.h"
#include "chainNode.h"


chainNode::chainNode(int a)
{
	data = a;
	next = NULL;
}


chainNode::~chainNode()
{
}

void chainNode::insert(int a)
{
	chainNode *node = new chainNode(a);
	this->next = node;
}

