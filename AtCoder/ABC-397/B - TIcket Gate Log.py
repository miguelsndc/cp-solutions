"""
length must be even
i at odd positions
o at even positions
if length is odd has to add 1

check if satifies constraint
    if it doesnt there must be either: 
        o character at odd position
        insert one i right before it will push all the others one position forward therefore making it even
        ioioi
        i at even position
        same
        odd length
        if preivous process made length odd just add the suited character to the nd
"""
s = ['-1'] + [x for x in input()]
i = 1; cnt = 0 
while i < len(s):
    if i & 1 and s[i] == 'o':
        s.insert(i, 'i')
        cnt += 1
    elif i % 2 == 0 and s[i] == 'i':
        s.insert(i, 'o')
        cnt += 1
    i += 1

if (len(s) - 1) & 1:
    s.append('o')
    cnt += 1

print(cnt)
