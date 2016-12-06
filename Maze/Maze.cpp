// Maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Mazer.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int width, height;
	cout << "请输入迷宫长度：" << endl;
	cin >> width;
	cout << "请输入迷宫宽度：" << endl;
	cin >> height;
	int **maze;
	maze = new int*[height];
	for (int i = 0; i < height; i++)
		maze[i] = new int[width];
	//读文件
	FILE *fp;
	fopen_s(&fp, "D:\\maze.txt", "r");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fscanf_s(fp, "%d", &maze[i][j]);
			if (feof(fp)) break;
		}
	}
	fclose(fp);

	//展示迷宫
	cout << "迷宫" << endl;
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

