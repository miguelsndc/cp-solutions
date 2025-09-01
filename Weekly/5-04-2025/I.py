n = int(input())
points_first = []
points_second = []
last = False
sum = 0
for i in range(n):
    a = int(input())
    sum += a
    if a > 0:
        points_first.append(a)
    else:
        points_second.append(-a)
    last = bool(a > 0)
    
if sum > 0:
    print("first"); exit(0)
elif sum < 0:
    print("second"); exit(0)

for i in range(min(len(points_first), len(points_second))):
    if points_first[i] > points_second[i]:
        print("first"); exit(0)
    elif points_first[i] < points_second[i]:
        print("second"); exit(0)

if len(points_first) > len(points_second):
    print("first");exit(0)
elif len(points_first) < len(points_second):
    print("second");exit(0)


if last:
    print("first")
else:
    print("second")
