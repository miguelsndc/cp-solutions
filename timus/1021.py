from bisect import bisect_left
n1 = int(input())
l1 = [0] * n1
for i in range(n1):
    l1[i] = int(input())
n2 = int(input())
l2 = [0] * n2
for i in range(n2): 
    l2[i] = int(input())

l1.sort()
l2.sort()

for i in range(len(l1)):
    l = 0
    r = n2 - 1
    target = 10000 - l1[i]
    while l <= r:
        m = int(l + (r - l) / 2)
        if (l2[m] == target):
            print("YES\n")
            exit()
        elif l2[m] > target:
            r = m - 1
        else:
            l = m + 1 

print("NO")



