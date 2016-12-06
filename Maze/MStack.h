#pragma once 

struct Route {
	int x;
	int y;
	Route * link;
};

class MStack
{
public:
	MStack();
	~MStack();
	void push(int a, int b);
	Route * pop();
	Route * get();
private:
	Route * head;
};

