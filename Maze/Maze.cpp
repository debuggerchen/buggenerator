// Maze.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Mazer.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int width, height;
	cout << "�������Թ����ȣ�" << endl;
	cin >> width;
	cout << "�������Թ���ȣ�" << endl;
	cin >> height;
	int **maze;
	maze = new int*[height];
	for (int i = 0; i < height; i++)
		maze[i] = new int[width];
	//���ļ�
	FILE *fp;
	fopen_s(&fp, "D:\\maze.txt", "r");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fscanf_s(fp, "%d", &maze[i][j]);
			if (feof(fp)) break;
		}
	}
	fclose(fp);

	//չʾ�Թ�
	cout << "�Թ�" << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	Mazer m(maze, width, height);	
	int j;
	cin >> j;
    return 0;
}

