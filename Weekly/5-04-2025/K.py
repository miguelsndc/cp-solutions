n, m = map(int, input().split(' '))
i = j = (m + 1) // 2
i -= 1
j += 1
v = []
pat = [(m+1)//2]

while i >= 1 or j <= m:
    if m & 1:
        if i >= 1:
            pat.append(i)
        if j <= m:
            pat.append(j)
    else:
        if j <= m:
            pat.append(j)
        if i >= 1:
            pat.append(i)

    i -= 1
    j += 1

while len(v) < n:
    v.extend(pat)

for i in range(n):
    print(v[i])