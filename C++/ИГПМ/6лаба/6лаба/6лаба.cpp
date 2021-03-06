#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

double f(double i)
{
	return  -1 * (i*i*i) + 9 * (i*i) - 24 * i - 2;
}
int main()
{
	int i, n;
	cout << "Kol-vo shagov n= ";
	cin >> n;
	double a = -5, b = 3, g, h, fu1, fu2;
	g = a + (b - a)*(3 - sqrt(double(5))) / 2;
	h = a + (b - a)*(sqrt(double(5)) - 1) / 2;
	fu1 = f(g);
	fu2 = f(h);
	for (i = 1; i <= n; i++)
	{
		if (fu1 <= fu2)
		{
			b = h;
			h = g;
			fu2 = fu1;
			g = a + (b - a)*(3 - sqrt(double(5))) / 2;
			fu1 = f(g);
		}
		else
		{
			a = g;
			g = h;
			fu1 = fu2;
			h = a + (b - a)*(sqrt(double(5)) - 1) / 2;
			fu2 = f(h);
		}
	}
	cout << (fu1 - fu2) / 2 + fu2 << endl;
	system("PAUSE");
	return 0;
}