#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double Fx(double x)
{
	return log(x) - 5 * cos(x);
}

double Ms(double alfa, double e)
{
	double x0 = alfa;
	double it = 0;
	double de, xk;
	double h = 0.1;
	do
	{
		it++;
		xk = x0 - ((Fx(x0) * h) / (Fx(x0 + h) - Fx(x0)));
		de = fabs(xk - x0);
		x0 = xk;
	} while (de > e);
	return x0;
}

int main()
{
	setlocale(0, "rus");
	double a, b, m, h, xt, e, ht;
	double alfa, beta, pribl;
	vector<double> x;
	vector<double> y;

	cout << "¬ведите а, b, m: "; cin >> a >> b >> m;
	cout << "¬ведите погрешность e: "; cin >> e;
	cout << "¬ведите шаг делени€ интервала на отрезки ht: "; cin >> ht;

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

	do
	{
		if (Fx(alfa) * Fx(beta) < 0)
		{
			cout << Ms(alfa, e) << endl;
			cout << "Fx(x) = " << Fx(Ms(alfa, e)) << endl;
		}
		alfa = beta;
		beta += ht;
	} while (alfa + ht < b);
	return 0;
}
