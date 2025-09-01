# 1 0 -1 -2 -3

N = int(input())

ps = 1 if N <= 0 else 0
for i in range(1, abs(N) + 1):
    if N < 0:
        ps -= i
    else:
        ps += i
print(ps)
