#include "stdafx.h"
#include "Mazer.h"
#include "MStack.h"
#include <iostream>

using namespace std;
Mazer::Mazer(int **maze_, int wid, int hei)
{
	//初始化
	maze = maze_;
	width = wid;
	height = hei;
	solved = false;

	//查找入口
	entry();

	//从入口查找路径
	if(find(startx, starty))
		output();
	else {
		cout << "无解" << endl;
	}
}


Mazer::~Mazer()
{
}
/*
	查找函数
	x,y为待查点
	若经x,y可通往出口，返回true
	否则，返回false
*/
bool Mazer::find(int x, int y)
{
	//获取上一路径点，用以确定下一步方向
	Route * r = route.get();
	int lastx = -2, lasty = -2;
	if (r) {
		lastx = r->x;
		lasty = r->y;
	}
	
	//将当前路径点入栈
	route.push(x, y);

	//遇墙或超出迷宫范围
	if (x>=width||y>=height||x<0||y<0||maze[y][x] == 0) {
		route.pop();
		return false;
	}

	//到达出口
	else if ((x==width-1||y==height-1||x==0||y==0)&&(x!=startx&&y!=starty)) {
		solved = true;
		return true;
	}

	//查找剩余三方向是否可到达出口
	else {
		bool up = false, left = false, down = false, right = false;
		//solved指示当前迷宫是否已解决
		//查找其余方向是否可行
		if (!solved&&(x!=lastx||(y-1)!=lasty)) {
			up = find(x, y - 1);
		}
		if (!solved&&((x-1)!=lastx||y!=lasty)) {
			left = find(x - 1, y);
		}
		if (!solved&&(x!=lastx||(y+1)!=lasty)) {
			down = find(x, y + 1);
		}
		if (!solved&&((x+1)!=lastx||y!=lasty)) {
			right = find(x + 1, y);
		}

		//若存在一个方向可以到达出口，返回true
		if (up || left || down || right) {
			return true;
		}
		//否则将当前位置设置为0，pop，返回false
		else {
			maze[y][x] = 0;
			route.pop();
			return false;
		}
	}
}

void Mazer::entry()
{
	//遍历第一行与最后一行
	for (int i=0; i < width; i++)
	{
		if (maze[0][i] == 1) {
			startx = i;
			starty = 0;
			return;
		}
		else if (maze[height - 1][i] == 1) {
			startx = i;
			starty = height - 1;
			return;
		}
	}
	//遍历第一列与最后一列
	for (int i = 0; i < height; i++) {
		if (maze[i][0] == 1) {
			startx = 0;
			starty = i;
			return;
		}
		else if (maze[i][width - 1]) {
			startx = width - 1;
			starty = i;
			return;
		}
	}
	startx = 0;
	starty = 0;
	
}

/*
	输出路径
*/
void Mazer::output()
{
	cout << "结果：" << endl;
	Route *p = route.pop();
	while (p) {
		maze[p->y][p->x] = 3;
		p = route.pop();
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (maze[i][j] == 3)
				cout << maze[i][j] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}
