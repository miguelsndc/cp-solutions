n = int(input())
fivecnt = 0
for x in range(1, 10000000):
    y = x
    while y % 5 == 0:
        fivecnt += 1
        y //= 5
    if fivecnt > n:
        print(0); exit(0)
    if fivecnt == n:
        print(5)
        print(x, x + 1, x + 2, x + 3, x + 4)
        break
