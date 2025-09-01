"""
upper bound é O(n) ja que n <= 6*10^4
deve haver algum caso q de pra subtrair um quadrado e dê outro
quadrado ou algo do genero, ent o n é menor, ent dp
if n == 1 retorno 1
se nao eu pego todos os quadrados menores q ele, nao deve ser mtos
e faço a recursao com f(x - quadrado) ate chegar em 1 e pego o minimo
"""
from bisect import bisect_left
squares = [i * i for i in range(250)]
n = int(input())
dp = [int(1e9 + 1) for i in range(n + 1)]
dp[1] = 1
for i in range(1, n + 1):
    # sqrt é log de qlqr jeito
    if (squares[bisect_left(squares, i)] == i):
        dp[i] = 1
    for sq in squares:
        if i + sq <= n:
            dp[i + sq] = min(dp[i + sq], dp[i] + 1)
        else:
            break
print(dp[n])
    

