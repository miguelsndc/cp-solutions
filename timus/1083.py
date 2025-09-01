n, k = input().split(' ')
n = int(n)
k = len(k)
if k >= n:
    print(n)
    exit()

ate = k if (n % k == 0) else n % k
respotsa =1
for i in range(n, ate-1, -k):
    respotsa *= i
print(respotsa)
