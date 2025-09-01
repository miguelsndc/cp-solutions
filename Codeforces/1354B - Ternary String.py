import sys
for _ in range(int(input())):
    s = input()
    l = -1
    m = sys.maxsize
    for i in range(1, len(s)):
        if s[i] != s[i - 1]:
            if s[i] != s[l] and l >= 0:
                m = min(i - l + 1, m)
            l = i - 1
    print(0 if m == sys.maxsize else m)