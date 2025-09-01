for _ in range(int(input())):
    n = int(input())
    v = [int(x) for x in input().split(' ')]
    if (min(*v) == v[0]):
        print("Bob")
    else:
        print("Alice")