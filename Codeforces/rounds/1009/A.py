for _ in range(int(input())):
    l, r, d, u = map(int, input().split(' '))
    if u == d == l == r:
        print("YES")
    else:
        print("NO")
