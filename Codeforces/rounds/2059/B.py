def solve():
    n, k = map(int, input().split(' '))
    v = [int(x) for x in input().split(' ')]
    if k == n:
        for i in range(1, n, 2):
            x = int((i+1)/2)
            if v[i] != int((i+1)/2):
                print(int((i+1)/2))
                return
        print(int(k/2) + 1)
        return
    
    for i in range(1, min(n - k + 2, n)):
        if v[i] != 1:
            print(1)
            return
    print(2)

for _ in range(int(input())):
    solve()
