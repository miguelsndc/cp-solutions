Sp, Sm, Dp, Dm, Tp, Tm, E = map(int ,input().split())
k1 = 0
# quantos caras vai
if Sp < E:
    k1 = (E - Sp + Dp - 1) // Dp  
k2 = 0
if Sm < E:
    k2 = (E - Sm + Dm - 1) // Dm  
D_min = max(k1, k2)
if D_min == 0:
    print("0\n0")
    exit()
#folga
L1 = D_min - k1
L2 = D_min - k2
# cada dia precisa de 2
rp_max = min(D_min, 2 * L1)
rm_max = min(D_min, 2 * L2)
# bullshit
total_cost = (4 * Tp * D_min - 3 * Tp * rp_max) + (4 * Tm * D_min - 3 * Tm * rm_max)
print(D_min)
print(total_cost)
