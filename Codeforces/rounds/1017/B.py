for _ in range(int(input())):
    n, m, l, r = map(int, input().split(' '))

    if n == m:
        print(f"{l} {r}")
        continue
    if m == 0:
        print(f"{0} {0}")
        continue
    

    a = 0; b = 0 
    for i in range(m):
        b += 1
        b = min(r, b)
    m -= b
    for i in range(m):
        a -= 1
        a = max(a, l)
    print(f"{a} {b}")


