#include <iostream>
#include <cmath>
#include <iomanip>
#include "windows.h"
using namespace std;

#define INTEGRAL -69.42

double Fx(double x)
{
	return (pow(x, 3) - 5 * pow(x, 2));
}

double D1F_T(double x)
{
	return ( 1/x +5*sin(x) );
}

double D2F_T(double x)
{
	return ( -1/(x*x) +5*cos(x) );
}

double D1F(double x, double h_p, double a, double b)
{
	if(x==a)
		return ( -(3*Fx(x)-4*Fx(x+h_p)+Fx(x+2*h_p))/(2*h_p) );
	else if(x==b)
		return ( (Fx(x-2*h_p)-4*Fx(x-h_p)+3*Fx(x))/(2*h_p) );
	else
		return ( (Fx(x+h_p)-Fx(x-h_p))/(2*h_p) );
}

double D2F(double x, double h_p, double a, double b)
{
	return ( (Fx(x-h_p)-2*Fx(x)+Fx(x+h_p))/(h_p*h_p)  );
}

double Integral(double a, double b, int m, double d)
{
	double sum;
	double gh = m;
	do
	{
	double h = (b-a)/(gh);
	sum = h/3;
	double tmp1 = 0.0;
	double tmp2 = 0.0;

	for(int k = 1; k<=gh-1; k++)
		tmp1 += Fx(a+k*h);

	for(int k = 1; k<=gh; k++)
		tmp2 += Fx( ((a+(k-1)*h)+(a+k*h))/2 );

	sum *= (0.5*a + tmp1 + 2*tmp2 + 0.5*b);
	gh += 100;
	}while(fabs(INTEGRAL-sum) >= d);

	return sum;
}

int main()
{
	setlocale(0, "rus");

	double a, b, d, integr;
	int m;
	double hp[3] = {0.2, 0.1, 0.05};
	double *x = new double[21];
	double *y = new double[21];

	cout <<"������� �������� (a, b): ";		cin >> a >> b;
	cout <<"������� m: "; cin >> m;
	cout <<"������� �������� ����������� d: "; cin >> d;

	// �������� ����� ��� ����������� �����������
	for(int i = 1; i <= 21; i++)
		x[i-1] = a+(i-1)*(b-a)/10;

	// �������� ������ �������� ������� � ������
	for(int i = 1; i <= 21; i++)
		y[i-1] = Fx(x[i-1]);

	cout <<"+"<<setw(78)<<setfill('-')<<"+" << setfill(' ')<<endl;
	cout <<"|"<<setw(11)<<"f   |"<<setw(17)<<"df1 ���.  |"<<setw(15)<<"df1 ��.  |"
		<<setw(17)<<"df2 ���.  |"<<setw(17)<<"df2 ��.   "<<"|"<<endl;
	cout <<"+"<<setw(78)<<setfill('-')<<"+" << setfill(' ')<<endl;

	for(int j = 0; j < 3; j++)
	{	
	cout <<"|"<<setw(37)<<"��� "<<setw(4)<<hp[j]<<setw(37)<<"|"<<endl;
	cout <<"+"<<setw(78)<<setfill('-')<<"+" << setfill(' ')<<endl;

	for(int i = 1; i <= 21; i++)
	{
		cout <<"|"<<setw(10)<<y[i-1]<<"|"<<setw(16)<<D1F_T(x[i-1])<<"|"<<setw(14)<<D1F(x[i-1],hp[j],1,8)<<"|"
			 <<setw(16)<<D2F_T(x[i-1])<<"|"<<setw(17)<<D2F(x[i-1],hp[j],1,8)<<"|"<<endl;
		cout <<"+"<<setw(78)<<setfill('-')<<"+" << setfill(' ')<<endl;
	}
	}

	cout << endl << endl << endl;
	integr = Integral(a, b, m, d);
	cout <<"��������� �������� ��������� = "<< integr <<"\t"<<"������ �������� ��������� = "<<INTEGRAL<<endl;
	cout << "����������� ���������� ��������� = " << fabs(INTEGRAL - integr) << endl << endl;
	system("C:\\Users\\DELL\\source\\repos\\igpm3\\image.png");
	system("pause");
	return 0;
}
