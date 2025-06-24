#agora precisamos adicioanr um valor fixo para ele subtrair

def memoized_cut_rod(p, n,valor_fixo):
    r = [-float('inf')] * (n + 1)
    return memoized_cut_rod_aux(p, n,r, valor_fixo)

def memoized_cut_rod_aux(p, n, r,valor_fixo):
    if r[n] >= 0:
        return r[n]
    
    if n == 0:
        q = 0
    else:
        q = -float('inf') 
        for i in range(1, n + 1):
            current = p[i - 1] + memoized_cut_rod_aux(p, n - i, r, valor_fixo)
            if n != i:
                current -=valor_fixo 
            q = max(q, current)
    r[n] = q
    return q




precos = [1, 5, 8, 9, 10, 17, 20]
tamanho = 7
valor_fixo = 2
resultado = memoized_cut_rod(precos, tamanho,valor_fixo)
print("Lucro máximo:", resultado)











