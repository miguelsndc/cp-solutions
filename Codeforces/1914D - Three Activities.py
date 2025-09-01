from collections import Counter
for _ in range(int(input())):
    n = int(input())
    a = [(x, i) for i, x in enumerate(list(map(int, input().split(' '))))]
    b = [(x, i) for i, x in enumerate(list(map(int, input().split(' '))))]
    c = [(x, i) for i, x in enumerate(list(map(int, input().split(' '))))]
    """
    choose the biggest count for each day
    """
    a.sort(reverse=True); b.sort(reverse=True); c.sort(reverse=True);

    a = a[:3]
    b = b[:3]
    c = c[:3]

    mx = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):

                if len(Counter([a[i][1], b[j][1], c[k][1]]).keys()) == 3:
                    mx = max(mx, a[i][0] + b[j][0] + c[k][0])
    print(mx)