#pragma once
#include <iostream>
#include "Node.h"

using namespace std;
class ChainIterator {
public:
	ChainIterator(const Chain & c);
	Chain* Reverse();
	Chain* Join(const Chain & c);
private:
	Node *p;
};

class Chain
{
	friend class ChainIterator;
public:
	Chain();
	Chain(Node *node);
	~Chain();
	void Insert(int a);
	void Delete(int a);
	int Search(int a);
	void Output();
private:
	Node *first;
};
