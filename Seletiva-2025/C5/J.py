n = int(input())
mod = 10**9 + 7
ans = (2**(n-3)*n) % mod
print(int(ans))