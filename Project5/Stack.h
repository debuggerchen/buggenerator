#pragma once
struct Node {
	bool isNum;
	double num;
	char op;
	Node * link;
};
class Stack
{
public:
	Stack();
	~Stack();
	void push(Node *i);
	Node * pop();
	Node * Get();
private:
	Node * list;
};

