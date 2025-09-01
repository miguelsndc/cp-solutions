from math import *

def solve():
    n = int(input())
    a = [int(x) for x in input().split(' ')]
    for i in range(n - 2):
        if (a[i + 1] % gcd(a[i], a[i + 2]) != 0):
            print("NO")
            return
    print("YES")

for _ in range(int(input())):
    solve()

