#pragma once
class HashTable
{
public:
	HashTable(int div);
	~HashTable();
	void Insert(int value);
	int Search(int value);
	int Get(int index);
private:
	int D;
	int *ht;
	bool *empty;
};

