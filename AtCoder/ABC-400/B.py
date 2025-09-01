n, m = map(int , input().split(' '))
sum = 1; cur = n
for i in range(1, m + 1):
    sum += cur;
    cur *= n;
    if (sum > (1000000000)):
        print("inf")
        exit()
print(sum)