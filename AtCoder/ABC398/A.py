from math import *
n = int(input())
if n & 1:
    for i in range(n):
        if i == floor(n / 2):
            print("=", end="")
        else:
            print("-", end="")
else:
    for i in range(n):
        if i == floor(n/2) or i + 1 == ceil(n / 2):
            print("=", end="")   
        else:
            print('-', end="")

