#pragma once
class chainNode
{
public:
	chainNode *next;
	int data;
	chainNode(int a);
	~chainNode();
	void insert(int a);

};

