for _ in range(int(input())):
    n = int(input())
    p = [int(x) - 1 for x in input().split(' ')]
    found = False
    for i in range(n):
        if p[p[i]] == i:
            print(2)
            found = True
            break
    if not found:
        print(3)