"""

"""

for _ in range(int(input())):
    n, x = map(int, input().split(' '))
    v = list(map(int, input().split(' ')))
    if ((sum(v) / n) == x):
        print("YES")
    else:
        print("NO")