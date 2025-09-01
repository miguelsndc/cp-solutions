from math import *
for _ in range(int(input())):
    n = int(input())
    v = [int(x) for x in input().split(' ')]
    print(max(*v) - min(*v))
