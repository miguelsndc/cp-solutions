for _ in range(int(input())):
    a, b, x = map(int, input().split(' '))
    if a < b:
        a, b = b, a
    while a > x and b > 0:
        rem = a % b
        if ((x - rem) % b == 0): 
            a = x
        else:
            a = rem
        a, b = b, a
    print ("YES" if (a == x or b == x) else "NO")
