n = int(input())

if n & 1:
    print(-1)
    exit()

if n == 2:
    print("bb")
    print("ww")
    print("")
    print("bb")
    print("ww")
    print("")
    exit()
else:
    # par de tamanho pelo menos 4 eu preencho os cantos de fora indo pra dentro
    matrix = [[1 for _ in range(n)] for _ in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == k or j == k or i == n  - 1 - k or j == n - 1 - k:
                    matrix[i][j] = 0 if k % 2 else 1

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if k % 2 == 0:
                    print("b" if matrix[i][j] == 1 else "w", end="")
                else:
                    print("w" if matrix[i][j] == 1 else "b", end="")
            print()
        print()


    