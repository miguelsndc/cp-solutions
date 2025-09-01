from math import *
n, m, t = map(int, input().split(' '))

ans = 0
for i in range(4, n + 1):
    if (t - i) >= 1 and m >= (t - i):
        ans += comb(n, i) * comb(m, t - i)
print(ans)
