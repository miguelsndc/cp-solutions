n, a = int(input()), list(map(int, input().split(' ')))
k, p = sum(a), 0
if k % 3 == 0:
    k //= 3 # what each segment should be
    c = 0  # count how many segments equal to k
    s = 0  # reverse sum
    for r in a[:-1]:
        s += r
        if s == 2 * k: # se for 2k entao eu tenho mais c formas antes desse 2k de formar os pares
            p += c
        if s == k: # mais um s = k
            c += 1
print(p)
