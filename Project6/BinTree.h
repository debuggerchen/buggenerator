#pragma once
struct Tree {
	char element;
	Tree *lefttree, *righttree;
};

class TNode {
public:
	Tree * t;
	TNode * link;
};

class TQueue {
public:
	void push(Tree *t);
	Tree * Delete();
private:
	TNode *head, *rear;
};



class BinTree
{
public:
	BinTree();
	~BinTree();
	int size();
	int height();
	void setRoot(Tree *t);
	void preOrder();
	void inOrder();
	void postOrder();
	void levelOrder();
	Tree * PreIn2Post(char *pre,char *in,int ps,int pe,int is,int ie);
	static Tree * form(char e, Tree *l, Tree *r);
private:
	Tree *root;
	int treesize;
	void size(Tree *t);
	int height(Tree *t);
	void preOrder(Tree *t);
	void inOrder(Tree *t);
	void postOrder(Tree *t);
	int findIndex(char *a, char t, int is,int ie);
};

