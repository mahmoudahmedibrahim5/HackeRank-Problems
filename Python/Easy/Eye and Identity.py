import numpy
numpy.set_printoptions(legacy = '1.13')

x, y = list(map(int, input().split()))
print(numpy.eye(x, y, k=0))
