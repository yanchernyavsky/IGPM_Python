import numpy as np
import matplotlib.pyplot as plt


def coef(x, y):
    '''x : array of data points
       y : array of f(x)  '''
    x.astype(float)
    y.astype(float)
    n = len(x)
    a = []
    for i in range(n):
        a.append(y[i])

    for j in range(1, n):
        for i in range(n-1, j-1, -1):
            a[i] = float(a[i]-a[i-1])/float(x[i]-x[i-j])

    return np.array(a) # return an array of coefficient


def eval(a, x, r):
    ''' a : array returned by function coef()
        x : array of data points
        r : the node to interpolate at  '''
    x.astype(float)
    n = len(a) - 1
    temp = a[n] + (r - x[n])
    for i in range(n - 1, -1, -1):
        temp = temp * (r - x[i]) + a[i]
    return temp # return the y_value interpolation


def f(x):
    return x**3 + 10*x**2


print('Input a, b, n, m: ')
a, b, n, m = map(int, input().split())

x, y = [], []
for i in range(m):
    x.append(a + (i)*(b - a)/m)
    y.append(f(x[i]))
x = np.array(x)
y = np.array(y)
print('x = ', x)
print('y = ', y)

coefficients = coef(x, y)
print(coefficients)

xj, yj, error = [], [], []
for j in range(21):
    xj.append(a + j*(b-a)/20)
    yj.append(eval(coefficients, x, xj[j]))
xj = np.array(xj)
yj = np.array(yj)
#print(xj)
#print(yj)
for k in range(21):
    error.append(f(xj[k]) - yj[k])
print('error: ', error[0:16])

p = np.arange(-8, 0, 0.01)
fx = plt.plot(p, p**3+10*p*p)
fjx = plt.plot(xj[0:17], yj[0:17], 'r--')
plt.legend((fx[0], fjx[0]), ('f (x)', '\u03c6 (x)'), loc='best')
plt.xlabel(r'$x$')
plt.ylabel(r'$f (x)$')
plt.title(r'$y=x^3+10x^2$')
plt.grid(True)
plt.show()