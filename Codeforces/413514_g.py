for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split(' ')))
    y = list(map(int, input().split(' ')))
    d = [y[i] - x[i] for i in range(n)]
    d.sort(reverse=True)
    i = 0; j = n - 1
    pairs = 0
    while i < j:
        if (d[i] + d[j] >= 0):
            pairs += 1
            i += 1
            j -= 1
        else:
            j -= 1
    print(pairs)
