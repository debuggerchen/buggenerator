#pragma once
#include "Stack.h"
#include <string>

using namespace std;
class Calculator
{
public:
	Calculator(string expr);
	~Calculator();
	string Postfix();
	double Calc();
	static bool Isnum(char i);
	static int Char2Num(char i);
	static int Priority(char i);
	static double CharCal(double a, double b, char op);
private:
	string exp;
	Stack list;
};

