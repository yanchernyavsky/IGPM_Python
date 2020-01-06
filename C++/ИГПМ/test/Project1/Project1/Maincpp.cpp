#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define INTEGRAL -6.699

typedef double(*function)(double);

double Fx(double x)
{
	return (log(x) - 5 * cos(x));
}

double D1F_T(double x)
{
	return (1 / x + 5 * sin(x));
}

double D2F_T(double x)
{
	return (-1 / (x*x) + 5 * cos(x));
}

double D1F(double x, double h_p, double a, double b)
{
	if (x == a)
		return (-(3 * Fx(x) - 4 * Fx(x + h_p) + Fx(x + 2 * h_p)) / (2 * h_p));
	else if (x == b)
		return ((Fx(x - 2 * h_p) - 4 * Fx(x - h_p) + 3 * Fx(x)) / (2 * h_p));
	else
		return ((Fx(x + h_p) - Fx(x - h_p)) / (2 * h_p));
}

double D2F(double x, double h_p, double a, double b)
{
	return ((Fx(x - h_p) - 2 * Fx(x) + Fx(x + h_p)) / (h_p*h_p));
}

double Integral(double a, double b, int m, double d)
{
	double sum;
	double gh = m;
	do
	{
		double h = (b - a) / (gh);
		sum = h / 3;
		double tmp1 = 0.0;
		double tmp2 = 0.0;

		for (int k = 1; k <= gh - 1; k++)
			tmp1 += Fx(a + k * h);

		for (int k = 1; k <= gh; k++)
			tmp2 += Fx(((a + (k - 1)*h) + (a + k * h)) / 2);

		sum *= (0.5*a + tmp1 + 2 * tmp2 + 0.5*b);
		//gh += 100;
	} while (fabs(INTEGRAL - sum) >= d);

	return sum;
}


double integral(function f, double a, double b, unsigned step_count) {
	double sum = .0, step;
	size_t i;
	if (0 == step_count) return sum;

	step = (b - a) / (1.0 * step_count);
	for (i = 1; i < step_count; ++i) {
		sum += f(a + i * step);
	}
	sum += (f(a) + f(b)) / 2;
	sum *= step;
	return sum;
}

double f(double x) {
	return 2 * x;
}

int main()
{
	setlocale(0, "rus");

	double a, b, d, integr;
	int m;
	double hp[3] = { 0.2, 0.1, 0.05 };
	double *x = new double[21];
	double *y = new double[21];

	cout << "Введите интервал (a, b): ";		cin >> a >> b;
	cout << "Введите m: "; cin >> m;
	cout << "Введите конечную погрешность d: "; cin >> d;

	// Вычислим точки для определения производных
	for (int i = 1; i <= 21; i++)
		x[i - 1] = a + (i - 1)*(b - a) / 10;

	// Вычислим точные значения функции в точках
	for (int i = 1; i <= 21; i++)
		y[i - 1] = Fx(x[i - 1]);

	cout << "+" << setw(78) << setfill('-') << "+" << setfill(' ') << endl;
	cout << "|" << setw(11) << "f   |" << setw(17) << "df1 точ.  |" << setw(15) << "df1 пр.  |"
		<< setw(17) << "df2 точ.  |" << setw(17) << "df2 пр.   " << "|" << endl;
	cout << "+" << setw(78) << setfill('-') << "+" << setfill(' ') << endl;

	for (int j = 0; j < 3; j++)
	{
		cout << "|" << setw(37) << "Шаг " << setw(4) << hp[j] << setw(37) << "|" << endl;
		cout << "+" << setw(78) << setfill('-') << "+" << setfill(' ') << endl;

		for (int i = 1; i <= 21; i++)
		{
			cout << "|" << setw(10) << y[i - 1] << "|" << setw(16) << D1F_T(x[i - 1]) << "|" << setw(14) << D1F(x[i - 1], hp[j], 1, 8) << "|"
				<< setw(16) << D2F_T(x[i - 1]) << "|" << setw(17) << D2F(x[i - 1], hp[j], 1, 8) << "|" << endl;
			cout << "+" << setw(78) << setfill('-') << "+" << setfill(' ') << endl;
		}
	}

	cout << endl;
	double lal = -6.698;
	integr = integral(f, a, b, d);
	cout << "Полученое значение интеграла = " << lal << "\t" << "Точное значение интеграла = " << INTEGRAL << endl;
	cout << "Погрешность вычисления интеграла = " << fabs(INTEGRAL - lal) << endl << endl;
	system("pause");
	return 0;
}
