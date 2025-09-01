for _ in range(int(input())):
    s = input()
    ans = []
    mn = s[-1]
    for i in reversed(s):
        mn = min(mn, i)
        ans.append(i if i <= mn else str(min(int(i) + 1, 9)))
    print("".join(sorted(ans)))
    """
        a resposta era literalmente empurrar o menor caracter pra frente e aumentar
        quem tiver no caminho, era o q eu tinha pensando mas sla oq porra eu tenho na
        cabeça
    """
