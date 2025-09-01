from math import gcd
"""
tem q ser alguma combinacao dos pulos
constraint paiapradp
3x + 5y + 4z divide n extended gcd
"""
n, x = map(int, input().split(' '))
p = gcd(*list(map(int,input().split(' '))))
if x % p == 0:
    print("YES")
else:
    print("NO")