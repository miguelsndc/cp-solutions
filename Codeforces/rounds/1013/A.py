for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split(' ')))
    zero = 3; twos = 2; five = 1; one = 1; three = 1;
    can = False
    for i in range(n):
        if l[i] == 0 and zero > 0: zero -= 1
        if l[i] == 1 and one > 0: one -= 1
        if l[i] == 2 and twos > 0: twos -= 1
        if l[i] == 3 and three > 0: three -= 1
        if l[i] == 5 and five > 0: five -= 1

        if (zero + twos + five + one + three == 0):
            print(i + 1)
            can = True
            break

    if not can:
        print(0)