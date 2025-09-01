n = int(input())
exp = input()
a = exp[:]
b = ""
while a != b:
    b = a[:]
    a = a.replace(')(', ')*(').replace('()', '(1)').replace('))', ')+1)')

print(eval(a))
