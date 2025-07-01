'''
Modifique o algoritmo para resolver o problema das barras com memoiza ̧c ̃ao para
ele retornar, al ́em do rendimento  ́otimo, o solu ̧c ̃ao  ́otima. Ou seja, sua solu ̧c ̃ao deve
mostrar (“printar”) os tamanhos das barras da solu ̧c ̃ao  ́otima.
'''

'''
Modifique o algoritmo para resolver o problema das barras com memoiza ̧c ̃ao para
ele retornar, al ́em do rendimento  ́otimo, o solu ̧c ̃ao  ́otima. Ou seja, sua solu ̧c ̃ao deve
mostrar (“printar”) os tamanhos das barras da solu ̧c ̃ao  ́otima.
'''

def memoized_cut_rod(p, n):
    r = [-float('inf')] * (n + 1)
    return memoized_cut_rod_aux(p, n, r)

def memoized_cut_rod_aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    
    if n == 0:
        q = 0
    else:
        q = -float('inf')
        for i in range(1, n + 1):
            q = max(q, p[i - 1] + memoized_cut_rod_aux(p, n - i, r))
    
    r[n] = q
    return q


#Agora de forma memoizado

def memoized_cut_road(p,n):
    r = [-float('inf')] * (n+1)
    s = [0] * (n + 1) 

    val = memoized_cut_road_aux(p,n,r,s)
    print("Cortes da solução ótima:")
    print_solution(s, n)
    return val

def memoized_cut_road_aux(p,n,r,s):
    if r[n] >= 0:
        return r[n]
    
    if n == 0:
        q = 0

    else:
        q = -float('inf')
        for i in range (1, n+1):
            current = p[i-1] + memoized_cut_road_aux(p,n-i,r,s)
            if q < current:
                q = current
                s[n] = i

    r[n] = q
    return q               

def print_solution(s, n):
    while n > 0:
        print(s[n], end=' ')  
        n -= s[n]              
    print()



precos = [1, 5, 8, 9, 10, 17, 17, 20]
tamanho = 7
resultado = memoized_cut_road(precos, tamanho)
print("Lucro máximo:", resultado)








