n = int(input())
v = [int(x) for x in input().split(' ')]
cntneg = cnteven = cntodd = ansp = 0
for i in v:
    if cntneg & 1:
        cntodd += 1
    else:
        cnteven += 1
    if i < 0:
        cntneg += 1
    if cntneg & 1:
        ansp += cntodd
    else:
        ansp += cnteven


print (n * (n + 1)//2 - ansp, ansp) 