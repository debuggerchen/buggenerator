#pragma once

struct Element {
	int row;
	int col;
	int data;
};

class SparseMatrix
{
public:
	SparseMatrix();
	~SparseMatrix();
	void Insert();
	SparseMatrix* transpose();
	SparseMatrix* add(SparseMatrix &a);
	void Output();
private:
	int maxRow;
	int maxCol;
	int size;
	Element *matrix;
};

