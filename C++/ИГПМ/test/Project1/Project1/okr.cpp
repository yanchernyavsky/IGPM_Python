#include <cmath>

using namespace std;

double okr(double X, double eps)
{
	int i = 0;
	while (eps != 1) {
		i++;
		eps *= 10;
	}
	int okr = pow(double(10), i);
	X = int(X * okr + 0.5) / double(okr);
	return X;
}