#include "stdafx.h"
#include "Calculator.h"
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;
Calculator::Calculator(string expr)
{
	exp = expr;
}


Calculator::~Calculator()
{
}
/*
	���ɺ�׺���ʽ
*/
string Calculator::Postfix()
{
	string postfix = "";
	int length = exp.length();
	for (int i = 0; i < length; i++) {	//�������ʽ
		if (Isnum(exp[i])) {
			postfix += exp[i];	//����ֱ��д����ʽ
		}
		else {
			Node *node = new Node();
			node->isNum = false;
			node->op = exp[i];	//���������ջ�ڵ�
			if (exp[i] == ')') {	//����ǰ�����Ϊ�����ţ������ջȡ������һ�����ż����������������ʽ
				while (exp[i] == ')') {
					Node * temp = list.pop();
					if (temp->op != '(')
						postfix += temp->op;
					else {
						delete temp;
						break;
					}
					delete temp;
				}
			}
			else if (list.Get() == NULL ||
				Priority(exp[i]) > Priority(list.Get()->op)) //��ջ�ջ�ǰ��������ȼ��ߣ�ֱ����ջ
				list.push(node);
			else {	//����ѭ����ջ�������ֱ��ջ����������ȼ����ڵ�ǰ�������������������
				while (list.Get() && list.Get()->op != '('
					&&Priority(exp[i]) <= Priority(list.Get()->op)) {
					Node * temp = list.pop();
					postfix += temp->op;
					delete temp;
				}
				list.push(node);	//��ջ
			}
		}
	}
	while (list.Get()) {	//��ջ��ʣ�������ȡ��
		Node * p = list.pop();
		postfix += p->op;
		delete p;
	}
	exp = postfix;
	return postfix;
}
/*
	�ɺ�׺��ʽ����
*/
double Calculator::Calc()
{
	int length = exp.length();
	for (int i = 0; i < length; i++) {	//������׺���ʽ
		if (Isnum(exp[i])) {			//������ջ
			Node * node = new Node();
			node->isNum = true;
			node->num = Char2Num(exp[i]);
			list.push(node);
		}
		else {
			Node *b = list.pop();	//�����������ջ������
			Node *a = list.pop();
			double c = CharCal(a->num, b->num, exp[i]);	//�������ֽ��м���
			delete a;
			delete b;
			Node *d = new Node();
			d->isNum = true;
			d->num = c;
			list.push(d);	//����������ջ
		}
	}
	Node *temp = list.pop();
	double result = temp->num;
	delete temp;
	return result;
}
/*
	�ж��ַ��Ƿ�Ϊ����
*/
bool Calculator::Isnum(char i)
{
	switch (i) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
		return false;
		break;
	default:
		return true;
	}
	return false;
}
/*
	�ַ�ת����
*/
int Calculator::Char2Num(char i)
{
	switch (i)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
	return 0;
}
/*
	���ؼ������ȼ�
	iΪ�����
*/
int Calculator::Priority(char i)
{
	switch (i)
	{
	case '(':
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	}
	return 0;
}
/*
	���㲢���ؽ��
*/
double Calculator::CharCal(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a*b;
	case '/':
		return a / b;
	default:
		break;
	}
	return 0.0;
}
