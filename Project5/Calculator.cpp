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
	生成后缀表达式
*/
string Calculator::Postfix()
{
	string postfix = "";
	int length = exp.length();
	for (int i = 0; i < length; i++) {	//遍历表达式
		if (Isnum(exp[i])) {
			postfix += exp[i];	//数字直接写入表达式
		}
		else {
			Node *node = new Node();
			node->isNum = false;
			node->op = exp[i];	//创建运算符栈节点
			if (exp[i] == ')') {	//若当前运算符为右括号，按序从栈取出到上一左括号间所有运算符至入表达式
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
				Priority(exp[i]) > Priority(list.Get()->op)) //若栈空或当前运算符优先级高，直接入栈
				list.push(node);
			else {	//否则，循环出栈运算符，直到栈顶运算符优先级低于当前运算符，或遇到左括号
				while (list.Get() && list.Get()->op != '('
					&&Priority(exp[i]) <= Priority(list.Get()->op)) {
					Node * temp = list.pop();
					postfix += temp->op;
					delete temp;
				}
				list.push(node);	//入栈
			}
		}
	}
	while (list.Get()) {	//将栈中剩余运算符取出
		Node * p = list.pop();
		postfix += p->op;
		delete p;
	}
	exp = postfix;
	return postfix;
}
/*
	由后缀形式计算
*/
double Calculator::Calc()
{
	int length = exp.length();
	for (int i = 0; i < length; i++) {	//遍历后缀表达式
		if (Isnum(exp[i])) {			//数字入栈
			Node * node = new Node();
			node->isNum = true;
			node->num = Char2Num(exp[i]);
			list.push(node);
		}
		else {
			Node *b = list.pop();	//遇运算符，出栈两数字
			Node *a = list.pop();
			double c = CharCal(a->num, b->num, exp[i]);	//对两数字进行计算
			delete a;
			delete b;
			Node *d = new Node();
			d->isNum = true;
			d->num = c;
			list.push(d);	//将运算结果入栈
		}
	}
	Node *temp = list.pop();
	double result = temp->num;
	delete temp;
	return result;
}
/*
	判断字符是否为数字
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
	字符转数字
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
	返回计算优先级
	i为运算符
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
	计算并返回结果
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
