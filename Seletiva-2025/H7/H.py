def solve():
    n = int(input())
    s = input()
    for i in range(1, n + 1):
        if n % i == 0:
            ok = 2
            for j in range(0, i):
                for k in range(j + i, n, i):
                    if s[k] != s[j]:
                        ok -= 1
            if ok > 0:
                print(i)
                return
            ok = 2
            for j in range(n - i, n):
                for k in range(j - i, -1, -i):
                    if s[k] != s[j]:
                        ok -= 1
            if ok > 0:
                print(i)
                return


for _ in range(int(input())):
    solve()