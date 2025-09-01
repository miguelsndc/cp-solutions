s = input()
s = str(int(s[::-1]))
for ch in s:
    if ch == '5':
        print('2',end="")
    elif ch == '2':
        print('5',end="")
    else:
        print(ch, end="")