a = [1]
b = [1]

n, x = map(int, input().split(' '))

for i in range(n):
    a.append(a[i] * 2 + 3) # total patties in full burger
    b.append(b[i] * 2 + 1) # patties contained in level i burger

def f(n, x): #number of patties in x layers down in a level n burger
    if n == 0:
        return 0 if x <= 0 else 1 # trivial case
    elif x <= 1 + a[n - 1]: # bottom bun + up to level n - 1 burgers from x-1 layers
        return f(n - 1, x - 1)
    else:
        # patties in n - 1 burger + bottom bun + 
        # level n - 1 burger with layers - bottom bun - middle patty - all patties below
        return b[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1])

print(f(n, x))

