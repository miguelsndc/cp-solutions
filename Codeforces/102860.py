n, v, u = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
lo = 0.0
hi = 1e18
def check(T):
    l = 0
    for x in a:
        val = max(0, x - v * T)
        l += val 
    return l <= u * T
ans = 0
for i in range(200):
    mid = lo + (hi - lo) / 2
    if check(mid):
        ans = mid
        hi = mid
    else:
        lo = mid
print(ans * u)