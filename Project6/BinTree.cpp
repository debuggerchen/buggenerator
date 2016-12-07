#include "stdafx.h"
#include "BinTree.h"
#include <iostream>

using namespace std;
BinTree::BinTree()
{
}


BinTree::~BinTree()
{
}

int BinTree::size()
{
	treesize = 0;
	size(root);
	return treesize;
}

int BinTree::height()
{
	return height(root);
}

void BinTree::setRoot(Tree * t)
{
	root = t;
}

void BinTree::preOrder()
{
	preOrder(root);
}

void BinTree::inOrder()
{
	inOrder(root);
}

void BinTree::postOrder()
{
	postOrder(root);
}

void BinTree::levelOrder()
{
	TQueue *tq = new TQueue();
	tq->push(root);
	bool finish = false;
	while (!finish) {
		Tree * t = tq->Delete();
		if (t) {
			cout << t->element << " ";
			if (t->lefttree)
				tq->push(t->lefttree);
			if (t->righttree)
				tq->push(t->righttree);
		}
		else {
			finish = true;
		}
	}
}

Tree * BinTree::PreIn2Post(char * pre, char * in, int ps, int pe,int is,int ie)
{
	int headindex = findIndex(in, pre[ps], is, ie);
	Tree * t = new Tree();
	t->element = pre[ps];
	if (headindex == is) {
		t->lefttree = NULL;
	}
	if (headindex == ie) {
		t->righttree = NULL;
	}
	if (headindex > is) {
		t->lefttree = PreIn2Post(pre, in, ps + 1, headindex - is, is, headindex - 1);
	}
	if (headindex < ie) {
		t->righttree = PreIn2Post(pre, in, headindex - is + ps + 1, ps - is + ie, headindex + 1, ie);
	}
	
	return t;
}

Tree * BinTree::form(char e, Tree * l, Tree * r)
{
	Tree *t = new Tree();
	t->element = e;
	t->lefttree = l;
	t->righttree = r;
	return t;
}

void BinTree::size(Tree * t)
{
	if (t) {
		treesize++;
		size(t->lefttree);
		size(t->righttree);
	}
}

int BinTree::height(Tree * t)
{
	if (t) {
		int hl = height(t->lefttree);
		int hr = height(t->righttree);
		return (hl > hr) ? ++hl : ++hr;
	}
	else {
		return 0;
	}
}

void BinTree::preOrder(Tree * t)
{
	if (t) {
		cout << t->element << " ";
		preOrder(t->lefttree);
		preOrder(t->righttree);
	}
}

void BinTree::inOrder(Tree * t)
{
	if (t) {
		inOrder(t->lefttree);
		cout << t->element << " ";
		inOrder(t->righttree);
	}
}

void BinTree::postOrder(Tree * t)
{
	if (t) {
		postOrder(t->lefttree);
		postOrder(t->righttree);
		cout << t->element << " ";
	}
}

int BinTree::findIndex(char *a, char t,int is,int ie)
{
	for (int i =is; i <= ie; i++) {
		if (a[i] == t)
			return i;
	}
	return -1;
}

void TQueue::push(Tree * t)
{
	if (t) {
		TNode * tn = new TNode();
		tn->t = t;
		if (head) {
			rear->link = tn;
		}
		else {
			head = tn;
		}
		rear = tn;
	}
}

Tree * TQueue::Delete()
{
	if (head) {
		TNode *tn = head;
		head = head->link;
		tn->link = NULL;
		//TODO: RELEASE MEMORY
		return tn->t;
	}
	else {
		rear = NULL;
		return NULL;
	}
}


