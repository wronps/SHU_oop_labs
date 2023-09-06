#include"equation_solving.h"
#include<iostream>
using namespace std;
int main()
{
	double a, b, c, x_1, x_2;
	while (cin >> a >> b >> c && a != 0)
	{
	
		if (equation_solving(a, b, c, x_1, x_2) >= 0)
		{
			cout << "x_1=" << x_1 << endl;
			cout << "x_2=" << x_2 << endl;
		}
		else
		{
			cout << "无实数根!" << endl;
		}
	}
	return 0;
}