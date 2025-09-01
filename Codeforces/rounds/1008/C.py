for _ in range(int(input())):
    n = int(input())
    q = list(map(int, input().split(' ')))
    q1 = []
    q2 = []
    q.sort(reverse=True)    
    for i in range(n + 1):
        q1.append(q[i])
    for i in range(n + 1, 2*n):
        q2.append(q[i])
    
    q2.append(sum(q1) - sum(q2)) # definitivamente maior q zero

    for i in range(n):
        print(q1[i], q2[i], end=" ")
    print(q1[-1])