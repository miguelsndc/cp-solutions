""""""

for _ in range(int(input())):
    n, k = map(int, input().split(' '))
    v = [i for i in range(1, n + 1)]

    if k & 1:
        for i in range(n - 1):
            print(n, end=" ")
        print(n - 1)
    else:
        for i in range(n - 2):
            print(n - 1, end=" ")
        print(n, end=" ")
        print(n - 1)

    