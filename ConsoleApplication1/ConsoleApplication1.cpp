#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
int index = 0;
string set[8];
void subset(string a[], int n)
{
	if (n == 0)
		set[0] = "";
	else
	{
		subset(a, n - 1);
		for (int i = 1; i <= index + 1; i++)
			set[i + index] = set[-1 + i] + " " + a[n - 1];
		index = 2 * index + 1;
	}
}
void main()
{
	string a[3];
	a[0] = "a";
	a[1] = "b";
	a[2] = "c";
	subset(a, 3);
	for (int i = 0; i < 8; i++)
		cout << "{" + set[i] + "}" << endl;
	int abcd;
	cin >> abcd;
}
