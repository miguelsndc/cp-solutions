from math import *

def FLOOR(x, n):
    while n > 0:
        if not x:
            return x
        x >>= 1
        n -= 1
    return x

def CEIL(x, n):
    while n > 0:
        if x <= 1:
            return x
        x = ((x + 1) >> 1)
        n -= 1
    return x


for _ in range(int(input())):
    x, n1, m1 = map(int, input().split(' '))
    print(f"{FLOOR(CEIL(x, m1), n1)} {CEIL(FLOOR(x, n1), m1)}")
  

