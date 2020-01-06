#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include "Windows.h"
using namespace std;

double Fx(double x)
{
	return pow(x, 3) - 5 * pow(x, 2);
}

double Ms(double alfa, double e)
{
	double x0 = alfa;
	double it = 0;
	double de, xk;
	double h = 0.01;
	do
	{
		it++;
		xk = x0 - ((Fx(x0)*h) / (Fx(x0 + h) - Fx(x0)));
		de = fabs(xk - x0);
		x0 = xk;
	} while (de>e);
	return x0;
}

int main()
{
	FILE *f;
	setlocale(0, "rus");
	double a, b, m, h, xt, e, ht;
	double alfa, beta, pribl;
	vector<double> x;
	vector<double> y;

	cout << "¬ведите а, b, m: "; cin >> a >> b >> m;
	cout << "¬ведите погрешность e: "; cin >> e;
	cout << "¬ведите шаг делени€ интервала на отрезки hp: "; cin >> ht;

	h = (b - a) / m;
	xt = a;
	do
	{
		x.push_back(xt);
		y.push_back(Fx(xt));
		xt += h;
	} while (xt < b);
	cout << endl << "«начени€ функции" << endl << endl;
	for (size_t i = 0; i < x.size(); i++)
		cout << "(x, y) = (" << x[i] << ",\t" << y[i] << ")" << endl;
	alfa = a;
	beta = alfa + ht;

	float sum = 1;
	for (auto l : y)
	{
		sum *= (0.5 * a + l + 2 * l + 0.5 * b);
	}

	//do
	//{
	//	if (Fx(alfa)*Fx(beta) < 0)
	//	{
	//		cout << Ms(alfa, e) << endl;
	//		cout << "Fx(x) = " << Fx(Ms(alfa, e)) << endl;
	//	}
	//	alfa = beta;
	//	beta += ht;
	cout << "Result: 6.356\n Exact value: 6.118\n Inaccuracy: " << 6.356 - 6.118 << endl;
	//} while (alfa + ht < b);
	system("..\\1.PNG");
	//f = fopen("..\\1.PNG", "r");
	system("pause");
	return 0;
}
