for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split(' ')))
    s = input()
    ps = [0]
    for i in range(0, n):
        ps.append(ps[i] + a[i])
    score = 0
    i = 0; j = n - 1
    while i < j:
        while i < n and s[i] == 'R':
            i += 1
        while j >= 0 and s[j] == 'L':
            j -= 1
        if i < j:
            score += ps[j + 1] - ps[i]
            i += 1
            j -= 1
    print(score)

        