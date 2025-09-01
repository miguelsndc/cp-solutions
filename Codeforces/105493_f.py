n, D = map(int, input().split())
visita = [0] * n
for _ in range(D):
    f, s = map(int, input().split())
    visita[f - 1] += 1
    visita[s - 1] += 1
m = max(visita)
if n % 2 == 0:
    k = m
else:
    k = m if m % 2 == 0 else m + 1
print(k)