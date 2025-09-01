n = int(input())
days = list(map(int, input().split(' ')))

"""
0 -> gym closed, no contest
1 -> gym closed, contest
2 -> gym open, no contest
3 -> gym open contest carried
"""

rest = 0 
ct = gym = False
for day in days:
    if day == 0:
        gym = ct = False
        rest += 1
    elif day == 1:
        if ct:
            rest += 1
            ct = gym = False
            continue
        ct = True
        gym = False
    elif day == 2:
        if gym:
            gym = ct = False 
            rest += 1
            continue
        gym = True
        ct = False
    else:
        if gym:
            ct = True
            gym = False
        elif ct:
            ct = False
            gym = True
    
print(rest)