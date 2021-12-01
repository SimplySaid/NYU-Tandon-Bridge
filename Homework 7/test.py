import numpy
import math

def test(n):
    count = 0
    for i in range (0, math.log(n)):
        i = i * 2
        for j in range (0, i):
            count += 1

x = 10000000000000000000000000000000000000000000000000000000000000000000000000000000

print(math.log(x))
print(test(x))


