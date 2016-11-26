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
	������Ԫ��
*/
void SparseMatrix::Insert()
{
	//��������С
	cout << "�����������" << endl;
	cin >> maxRow;					
	cout << "�����������" << endl;
	cin >> maxCol;
	cout << "�����������" << endl;
	cin >> size;
	matrix = new Element[size];
	int p = -1;

	//ѭ������Ԫ��
	for (int i = 0; i < size; i++) {
		int row, col, data;
		cout << "�����к�" << endl;
		cin >> row;
		cout << "�����к�" << endl;
		cin >> col;
		if (row <= maxRow&&col <= maxCol && ((row - 1)*maxCol + col) - 1 > p) {	//�ж����кźϷ���
			cout << "��������" << endl;
			cin >> data;
			matrix[i].col = col;		//���Ϸ�������Ӧ���ݶ���
			matrix[i].row = row;
			matrix[i].data = data;
			p = (row - 1)*maxCol + col - 1;
		}
		else {
			cout << "���к�����" << endl;
			i--;
		}
	}
}
/*
	Transpose
	����ת��
*/
SparseMatrix * SparseMatrix::transpose()
{
	//�����¾����С
	SparseMatrix *b = new SparseMatrix();
	b->maxCol = maxRow;
	b->maxRow = maxCol;
	b->size = size;
	b->matrix = new Element[size];
	
	int *colsize = new int[maxCol + 1]; //���ÿһ�д�С
	int *rownext = new int[maxCol + 1]; //���ÿһ��ͷԪ�����������е�����
	//��ʼ��colsize
	for (int i = 1; i <= maxCol; i++)
		colsize[i] = 0;
	//����matrix��ȷ��colsizeֵ
	for (int i = 0; i < size; i++)
		colsize[matrix[i].col]++;
	//����colsize ȷ��rownextֵ
	rownext[1] = 0;
	for (int i = 2; i <= maxCol; i++)
		rownext[i] = rownext[i - 1] + colsize[i - 1];
	//����matrix����rownextֵ�����¾���
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
	�����������
	aΪ��һ��������
*/
SparseMatrix * SparseMatrix::add(SparseMatrix & a)
{
	//�жϾ���ߴ�
	if (a.maxCol != maxCol || a.maxRow != maxRow) {
		cout << "��С��ƥ��" << endl;
		return nullptr;
	}

	//����ָ��
	int i = 0, ia = 0, isize = 0;
	Element *e = new Element[size + a.size];
	
	//������δ�������ʱ���еĲ���
	while (i < size&&ia < a.size) {
		//����ָ����ָԪ���ھ����е�����ֵ
		int ti = (matrix[i].row - 1)*maxCol + matrix[i].col;
		int ai = (a.matrix[ia].row - 1)*maxCol + a.matrix[ia].col;
		//ȡ����С�ģ�ֱ�Ӵ����¾���
		if (ti < ai) {
			e[isize] = matrix[i++];
		}
		else if (ai < ti) {
			e[isize] = a.matrix[ia++];
		}
		//��������ͬ
		else if (ai == ti) {
			//����Ӳ�Ϊ0��Ԫ�ؼӺʹ����¾���
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

	//��ʣ��Ԫ�ش������
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
	���ݾ����С����Ԫ���Ƿ����matrix�У�����Ԫ��ֵ��0
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
