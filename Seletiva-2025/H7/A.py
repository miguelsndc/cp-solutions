n = int(input())
mod = 1000000007
for i in range(n):
    a, b, c = map(int, input().split(' '))
    print(pow(a, pow(b, c, mod-1), mod))