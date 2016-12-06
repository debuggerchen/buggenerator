#include "stdafx.h"
#include "Mazer.h"
#include "MStack.h"
#include <iostream>

using namespace std;
Mazer::Mazer(int **maze_, int wid, int hei)
{
	//��ʼ��
	maze = maze_;
	width = wid;
	height = hei;
	solved = false;

	//�������
	entry();

	//����ڲ���·��
	if(find(startx, starty))
		output();
	else {
		cout << "�޽�" << endl;
	}
}


Mazer::~Mazer()
{
}
/*
	���Һ���
	x,yΪ�����
	����x,y��ͨ�����ڣ�����true
	���򣬷���false
*/
bool Mazer::find(int x, int y)
{
	//��ȡ��һ·���㣬����ȷ����һ������
	Route * r = route.get();
	int lastx = -2, lasty = -2;
	if (r) {
		lastx = r->x;
		lasty = r->y;
	}
	
	//����ǰ·������ջ
	route.push(x, y);

	//��ǽ�򳬳��Թ���Χ
	if (x>=width||y>=height||x<0||y<0||maze[y][x] == 0) {
		route.pop();
		return false;
	}

	//�������
	else if ((x==width-1||y==height-1||x==0||y==0)&&(x!=startx&&y!=starty)) {
		solved = true;
		return true;
	}

	//����ʣ���������Ƿ�ɵ������
	else {
		bool up = false, left = false, down = false, right = false;
		//solvedָʾ��ǰ�Թ��Ƿ��ѽ��
		//�������෽���Ƿ����
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

		//������һ��������Ե�����ڣ�����true
		if (up || left || down || right) {
			return true;
		}
		//���򽫵�ǰλ������Ϊ0��pop������false
		else {
			maze[y][x] = 0;
			route.pop();
			return false;
		}
	}
}

void Mazer::entry()
{
	//������һ�������һ��
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
	//������һ�������һ��
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
	���·��
*/
void Mazer::output()
{
	cout << "�����" << endl;
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
