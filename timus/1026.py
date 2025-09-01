n = int(input())
l = [0] * n
for i in range(n):
    l[i]=int(input())
l.sort()
_ = input()
k = int(input())
for i in range(k):
    q = int(input())
    print(l[q - 1])