n, k = map(int, input().split(' '))
l = [int(x) for x in input().split(' ')]
h = 0; bob = 0; time = 0
for i in l:
    h += i
    time += 1
    bob = min(h, bob + k)

while bob < h:
    bob += k
    time += 1

print(time)
    