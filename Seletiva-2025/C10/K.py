import sys
n = int(input())
l = [0] + [int(x) for x in input().split(' ')]
dp = [[sys.maxsize] * 1005 for _ in range(1005)]
dp[0][0] = 0
for i in range(1, n + 1):
    for j in range(i):
        # cheguei aqui
        if dp[i - 1][j] != sys.maxsize:
            ## min entre ir pra frente e teleportar pra algum lugar i - 1
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(l[i] - l[i - 1]));
            if i - 1 >= 0: # cria um ponto de teleporte no ponto i - 1 (onde a gnt tava) 
                # c custo |v[i] - v[j]| pra chegar
                dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(l[i] - l[j]));

print(min(*dp[n]))