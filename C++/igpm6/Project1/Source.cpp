#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void FPR(double x, double* y, double* f)
{
	f[0] = y[0] + 2 * y[1] / exp(x) - 2 * x;
	f[1] = y[0] / (2 * x) - exp(x) / y[1] + y[1];
}


void OUT(double x, double* y)
{
	cout << "x = " << setw(3) << x << "\t" << "y1 = " << setw(10) << y[0] << "\t" << "u1 = " << setw(8) << 2 * x << "\t" << "d1 = " << setw(10) << 2 * x - y[0] << endl
		<< setw(7) << "\t" << "y2 = " << setw(10) << y[1] << "\t" << "u2 = " << setw(8) << exp(x) << "\t" << "d2 = " << setw(10) << exp(x) - y[1] << endl << endl;
}

int main()
{
	setlocale(0, "rus");
	double a = 2, b = 3, h, x, z, d;
	double eps, de;
	int nx = 10, ny = 2, nit = 4, np = 1, k;

	double* y = new double[ny];
	double* yp = new double[ny];
	double* f = new double[ny];
	double* fp = new double[ny];

	y[0] = 2 * a;
	y[1] = exp(a);

	cout << "¬ведите погрешность : "; cin >> eps;
	cout << endl;

	h = (b - a) / nx;
	x = a;

	if (np != 0)
		OUT(x, y);
	else
		np = nx + 1;

	for (int n = 1; n <= nx; n++)
	{
		FPR(x, y, f);
		x += h;

		for (int i = 0; i < ny; i++)
		{
			fp[i] = f[i];
			yp[i] = y[i];
		}

		k = 0;

		do
		{
			++k;
			FPR(x, y, f);
			de = 0.0;

			for (int i = 0; i < ny; i++)
			{
				z = yp[i] + h / 2 * (fp[i] + f[i]);
				d = fabs(z - y[i]);
				y[i] = z;

				if (d > de)
					de = d;
			}

		} while (k < nit || de > eps);

		if (n % np == 0)
			OUT(x, y);
	}

	system("C:\\Users\\DELL\\source\\repos\\igpm6\\Project1\\graf1.png");
	system("C:\\Users\\DELL\\source\\repos\\igpm6\\Project1\\graf2.png");
	system("pause");
	return 0;
}
