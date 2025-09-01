from math import sqrt
import sys

def dot(x1,y1,x2,y2):
    return x1*x2 + y1*y2

def norm(x1, y1):
    return sqrt(x1 * x1 + y1 * y1)

def sub(x1, y1, x2, y2):
    return (x2 - x1, y2 - y1)

def distance(vx, vy, x1, y1, x, y):
    v2x = x - x1
    v2y = y - y1
    k = dot(v2x, v2y, vx, vy) / dot(vx,vy,vx,vy)
    vx *= k
    vy *= k
    res_x = v2x - vx
    res_y = v2y - vy
    return norm(res_x, res_y)

for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split(' '))
    vx = x2 - x1
    vy = y2 - y1
    l = []
    m = int(input())
    for i in range(m):
        name, x, y = input().split(' ')
        x = int(x)
        y = int(y)
        l.append((x, y, name))

    mx = sys.maxsize
    for i, (x, y, name) in enumerate(l):
        dist = distance(vx, vy, x1, y1, x, y)
        if (dist < mx):
            mx = dist
        l[i] = (dist, name)

    for dist, name in l:
        if dist == mx:
            print(name, end=" ")
    print()
        
    
    



    
