from math import *
l, r = map(int, input().split(' '))
d = r + r
"""
x^2 + y^2 = r^2
if y = lado / 2
x² + (lado/2)² = r² 
x² + lado²/4 = r² 
x = sqrt(r² - lado² / 4)
se x < - lado ou > lado -> 0
"""

if (d <= l):
    print("{:.3f}".format(l * l - (pi * r * r)))
    exit()
x = sqrt(r * r - (l * l / 4))
if x > l / 2:
    print(0)
    exit()

v1 = (-x, l/2)
v2 = (x, l/2)
norm = sqrt(v2[0]*v2[0] + v2[1]*v2[1])
dot_product = (v1[0] * v2[0] + v1[1]*v2[1])
angle = acos(dot_product / (norm * norm))
area = ((r * r / 2) * (angle - sin(angle)))
print("{:.3f}".format(pi * r * r - 4 * area))