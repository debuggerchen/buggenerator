#pragma once
class Node {
public:
	Node *link;
	int data;
};
class HashChain
{
public:
	HashChain(int div);
	~HashChain();
	void Insert(int value);
	bool Search(int value);
private:
	int D;
	Node **hc;
};

