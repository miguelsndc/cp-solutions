from fractions import Fraction

q = int(input())
mult = Fraction(1)
add = Fraction(0)
bottles = [0] * q
history = []
for i in range(q):
    line = input().split()
    type = int(line[0])
    if type == 1:
        x = int(line[1])
        bottles[i] = (x)
    elif type == 2:
        x = int(line[1])
        add += Fraction(x)
    elif type == 3:
        p, q = map(int, line[1:])
        frac = Fraction(p, q)
        mult *= frac
        add *= frac
    elif type == 4:
        j = int(line[1]) - 1
        x = bottles[j]
        Mj, Aj = history[j]
        val = x * (mult / Mj) + (add - Aj * (mult / Mj))
        print(int(val))
    history.append((mult, add))