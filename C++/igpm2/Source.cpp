#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define N 21

double PL(double xt, double* x, double* y, int n)
{
	double p = 0.0;
	double e;

	for (int k = 1; k < n + 1; k++)
	{
		e = 1;

		for (int i = 1; i < n + 1; i++)
		{
			if (i == k)
				continue;

			e *= (xt - x[i - 1]) / (x[k - 1] - x[i - 1]);
		}

		p += e * y[k - 1];
	}

	return p;
}

int main()
{
	setlocale(0, "rus");

	double a, b; // Интервал
	int m, n;
	double* xi, * xj, * yi, * yj, * yfj;
	double e = 0; // Погрешность

	cout << "Введите количество неизвестных параметров (n): ";         cin >> n;
	cout << "Введите колтчество точек в которых задана функция (m): "; cin >> m;
	cout << "Введите начало интервала (a): "; cin >> a;
	cout << "Введите конец интервала (b): ";  cin >> b;

	//--------------------------------
	xi = new double[m];
	xj = new double[N];
	yi = new double[m];
	yj = new double[N];
	yfj = new double[N];

	//--------------------------------

	for (int i = 1; i <= m; i++)
		xi[i - 1] = a + (i - 1) * (b - a) / (m - 1);
	for (int i = 1; i <= m; i++)
		yi[i - 1] = log(xi[i - 1]) - 5 * cos(xi[i - 1]);

	for (int j = 1; j <= N; j++)
		xj[j - 1] = a + (j - 1) * (b - a) / 20;
	for (int j = 1; j <= N; j++)
		yj[j - 1] = PL(xj[j - 1], xi, yi, m);

	for (int j = 1; j <= N; j++)
		yfj[j - 1] = log(xj[j - 1]) - 5 * cos(xj[j - 1]);

	for (int j = 1; j <= N; j++)
	{
		if (fabs(yfj[j - 1] - yj[j - 1]) > e)
			e = fabs(yfj[j - 1] - yj[j - 1]);
	}

	cout << "--------------------------------------------------" << endl;
	cout << "Узловые точки x, y (соответственно)..." << endl;
	for (int i = 1; i <= m; i++)
		cout << setw(10) << xi[i - 1] << "\t" << setw(10) << yi[i - 1] << endl;

	cout << "--------------------------------------------------" << endl;
	cout << "Высчитаная таблица x, y ..." << endl;
	for (int j = 1; j <= N; j++)
		cout << setw(10) << xj[j - 1] << "\t" << setw(10) << yfj[j - 1] << endl;

	cout << "--------------------------------------------------" << endl;
	cout << "Высчитаная таблица x, y (после апроксимации)..." << endl;
	for (int j = 1; j <= N; j++)
		cout << setw(10) << xj[j - 1] << "\t" << setw(10) << yj[j - 1] << endl;

	cout << "Погрешность: " << e << endl;

	return 0;
}
