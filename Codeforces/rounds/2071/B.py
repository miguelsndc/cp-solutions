from math import *
seq = [2,1,3,4,5,6,7,9,8]
for _ in range(int(input())):
    n = int(input())
    x = int(sqrt(n * (n + 1) / 2))
    if x * x == (n * (n + 1) / 2):
        print(-1)
        continue

    l = [i for i in range(1, n + 1)]
    pref = 0; fail = False
    for i in range(n):
        pref += l[i]
        x = int(sqrt(pref))
        if x * x == pref:
            pref -= l[i]
            if i < n - 1:
                l[i], l[i + 1] = l[i + 1], l[i] 
                pref += l[i]
            else:
                print(-1)
                fail = True
    if fail:
        print(-1)
    else:
        for i in l:
            print(i, end=" ")
        print()

    