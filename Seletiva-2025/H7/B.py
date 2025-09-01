mod = 1000000007

sa, op, sb = input().split(' ')

def pegamodulo(x):
    resultado = 0
    for d in x:
        resultado = (resultado * 10 + int(d)) % mod
    return resultado

def pegamodulo2(x):
    resultado = 0
    for d in x:
        resultado = (resultado * 10 + int(d)) % (mod - 1)
    return resultado

a = pegamodulo(sa)

if op == '+':
    b = pegamodulo(sb)
    print(((a % mod) + (b % mod)) % mod)
elif op == '-':
    b = pegamodulo(sb)
    print(((a % mod) - (b % mod) + mod) % mod)
elif op == '*':
    b = pegamodulo(sb)
    print(((a % mod) * (b % mod)) % mod)
else:  
    b = pegamodulo2(sb) 
    print(pow(a, b, mod))
