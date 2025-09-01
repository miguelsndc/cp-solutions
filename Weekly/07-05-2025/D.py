from math import sqrt
for _ in range(int(input())):
    n = int(input())
    print(n + (n - 1) * (n - int(sqrt(n))))