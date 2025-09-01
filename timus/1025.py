import math
n = int(input())
grupos = list(map(int, input().split(' ')))
grupos.sort()
k = len(grupos)
minimo = 0
## ate a metade + 1 
precisa = int(k / 2) + 1
for i in range(precisa):
    minimo += int(grupos[i] / 2) + 1
print (minimo)