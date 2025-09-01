for _ in range(int(input())):
    n, m = map(int, input().split(' '))
    if m & 1:
        m -= 1
    print(m * n // 2)