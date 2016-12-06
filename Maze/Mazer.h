#pragma once
#include "MStack.h"
class Mazer
{
public:
	Mazer(int **maze_, int wid, int hei);
	~Mazer();
	bool find(int x, int y);
	void entry();
	void output();
private:
	int **maze;
	int width;
	int height;
	int startx;
	int starty;
	bool solved;
	MStack route;
};

