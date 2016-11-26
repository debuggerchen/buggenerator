#include "stdafx.h"
#include "SparseMatrix.h"
#include <iostream>

using namespace std;
SparseMatrix::SparseMatrix()
{
	
}


SparseMatrix::~SparseMatrix()
{
}
/*
	插入新元素
*/
void SparseMatrix::Insert()
{
	//定义矩阵大小
	cout << "输入矩阵行数" << endl;
	cin >> maxRow;					
	cout << "输入矩阵列数" << endl;
	cin >> maxCol;
	cout << "输入非零项数" << endl;
	cin >> size;
	matrix = new Element[size];
	int p = -1;

	//循环读入元素
	for (int i = 0; i < size; i++) {
		int row, col, data;
		cout << "输入行号" << endl;
		cin >> row;
		cout << "输入列号" << endl;
		cin >> col;
		if (row <= maxRow&&col <= maxCol && ((row - 1)*maxCol + col) - 1 > p) {	//判断行列号合法性
			cout << "输入数据" << endl;
			cin >> data;
			matrix[i].col = col;		//若合法，将相应数据读入
			matrix[i].row = row;
			matrix[i].data = data;
			p = (row - 1)*maxCol + col - 1;
		}
		else {
			cout << "行列号有误" << endl;
			i--;
		}
	}
}
/*
	Transpose
	矩阵转置
*/
SparseMatrix * SparseMatrix::transpose()
{
	//定义新矩阵大小
	SparseMatrix *b = new SparseMatrix();
	b->maxCol = maxRow;
	b->maxRow = maxCol;
	b->size = size;
	b->matrix = new Element[size];
	
	int *colsize = new int[maxCol + 1]; //存放每一列大小
	int *rownext = new int[maxCol + 1]; //存放每一列头元素在新数组中的索引
	//初始化colsize
	for (int i = 1; i <= maxCol; i++)
		colsize[i] = 0;
	//遍历matrix，确定colsize值
	for (int i = 0; i < size; i++)
		colsize[matrix[i].col]++;
	//遍历colsize 确定rownext值
	rownext[1] = 0;
	for (int i = 2; i <= maxCol; i++)
		rownext[i] = rownext[i - 1] + colsize[i - 1];
	//遍历matrix，按rownext值存入新矩阵
	for (int i = 0; i < size; i++) {
		b->matrix[rownext[matrix[i].col]].col = matrix[i].row;
		b->matrix[rownext[matrix[i].col]].row = matrix[i].col;
		b->matrix[rownext[matrix[i].col]].data = matrix[i].data;
		rownext[matrix[i].col]++;
	}
	return b;
}

/*
	add
	将两矩阵相加
	a为另一待加数组
*/
SparseMatrix * SparseMatrix::add(SparseMatrix & a)
{
	//判断矩阵尺寸
	if (a.maxCol != maxCol || a.maxRow != maxRow) {
		cout << "大小不匹配" << endl;
		return nullptr;
	}

	//定义指针
	int i = 0, ia = 0, isize = 0;
	Element *e = new Element[size + a.size];
	
	//两矩阵都未遍历完成时进行的操作
	while (i < size&&ia < a.size) {
		//计算指针所指元素在矩阵中的索引值
		int ti = (matrix[i].row - 1)*maxCol + matrix[i].col;
		int ai = (a.matrix[ia].row - 1)*maxCol + a.matrix[ia].col;
		//取出较小的，直接存入新矩阵
		if (ti < ai) {
			e[isize] = matrix[i++];
		}
		else if (ai < ti) {
			e[isize] = a.matrix[ia++];
		}
		//若索引相同
		else if (ai == ti) {
			//将相加不为0的元素加和存入新矩阵
			if (matrix[i].data + a.matrix[ia].data != 0) {
				e[isize].data = matrix[i].data + a.matrix[ia].data;
				e[isize].col = matrix[i].col;
				e[isize].row = matrix[i].row;
			}
			i++;
			ia++;
		}
		isize++;
	}

	//将剩余元素存入矩阵
	while (i < size) {
		e[isize++] = matrix[i++];
	}
	while (ia < a.size) {
		e[isize++] = a.matrix[ia++];
	}
	SparseMatrix *c = new SparseMatrix();
	c->maxCol = maxCol;
	c->maxRow = maxRow;
	c->size = isize;
	Element *ce = new Element[isize];
	for (int k = 0; k < isize; k++) {
		ce[k] = e[k];
	}
	c->matrix = ce;
	delete e;
	return c;
}
/*
	output
	根据矩阵大小，及元素是否存在matrix中，输入元素值或0
*/
void SparseMatrix::Output()
{
	int p = 0;
	for (int i = 1; i <= maxRow; i++) {
		for (int j = 1; j <= maxCol; j++) {
			if (matrix[p].row == i&&matrix[p].col == j) {
				cout << matrix[p++].data << " ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
}
