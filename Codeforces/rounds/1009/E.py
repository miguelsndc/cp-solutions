import random
for _ in range(int(input())):
    n = int(input())
    v = [1, 2, 3]
    for i in range(75):
        print(f"? {v[0]} {v[1]} {v[2]}")
        p = int(input())
        if p == 0:
            break
        v[random.randint(0, 2)] = p
    print(f"! {v[0]} {v[1]} {v[2]}")