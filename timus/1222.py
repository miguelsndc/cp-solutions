from collections import defaultdict
N = int(input())
coins = [1, 2, 3]
dp = defaultdict(int)
dp[0] = 1
for x in range(0, N + 1):
    for y in coins:
        if (x - y >= 0):
            dp[x] = max(dp[x], y * dp[x - y])
print(dp[N])