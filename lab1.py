import gauss
import numpy

d = float(-7)
q = float(-2.86)

a = numpy.array([[q, 1., 0, 0, 0, 0],
                [1, -2, 1, 0, 0, d],
                [0, 1, -2, 1, 0, d],
                [0, 0, 1, -2, 1, d],
                [0, 0, 0, 1, q, 0]])

print(a)
print("\n")

b = gauss.gaussFunc(a)
print("РћС‚РІРµС‚:")
print(b)