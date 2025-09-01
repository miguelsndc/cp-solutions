for _ in range(int(input())):
    x = int(input())
    n = input()
    a = ""
    b = ""
    msb = False
    for i in n:
        if i == '2':
            if msb:
                a += '0'
                b += '2'
            else:
                a += '1'
                b += '1'
        elif i == '1':
            if msb:
                a += '0'
                b += '1'
            else:
                a += '1'
                b += '0'
                msb = True
        else:
            a += '0'
            b += '0'
    print(a)
    print(b)
