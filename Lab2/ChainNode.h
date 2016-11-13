#pragma once
class ChainNode
{
public:
	ChainNode *next;
	int data;
	ChainNode(int a);
	~ChainNode();
	void insert(int a);

};

