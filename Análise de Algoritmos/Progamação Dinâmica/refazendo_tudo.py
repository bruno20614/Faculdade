#QUESTÃO 1
#Tendo subproblema

def Foo(A, n):
    if n <= 4:
        return 0 
    
    return Foo(A, n//2) + Foo(A, n//2 +1) + Foo(A, n//2 + 2) + A[n-1]

''''
em que A  ́e um vetor com posi ̧c ̃oes de 1 at ́e n. Justificando sua resposta, diga se o
algoritmo acima possui sobreposi ̧c ̃ao de subproblemas. Em caso positivo, mostre
um algoritmo com memoiza ̧c ̃ao para evitar recalcular subproblemas.
'''''

def Foo(A,n,memo= None):

    if n <= 4:
        return 0
    
    if memo >= 0:
        memo = {}

    if n in memo:
        return memo[n]
    

    val = Foo(A, n//2,memo) + Foo(A, n//2 +1,memo) + Foo(A, n//2 + 2,memo) + A[n-1]
    memo[n] = val
    return val

#QUESTÃO 2
# p é o preço
# n é o tamanho

def memoized_cut_rod(p,n):
    r = [-float("inf") * (n+1)]
    s = [0] * n

    val = memoized_cut_rod_aux(p,n,r,s)
    print("Tamanhos ótimos")
    print_solution(s,n)

def memoized_cut_rod_aux(p,n,r,s):
    
    if r[n] >= 0:
        return r[n]
   
    if n == 0:
        q = 0
    else:
        q = -float("inf")    
        for i in range(1, n+1):
            current = (p[i - 1] + memoized_cut_rod_aux(p,n-i, r,s))
            if current > q:
                q = current
                s[n] =i
        r[n] = q
        return q
        
def print_solution(s,n):   
    while n > 0:
        print(s[n], end="")
        n -= s[n]
        print()



#QUESTÃO 3

def memoized_cut_rod(p,n,valor_fixo):
    r = [-float("inf")] * (n+1)
    s = [0] * n + 1

    val = memoized_cut_rod_aux(p,n,r,s,valor_fixo)
    print("Tamanhos ótimos")
    print_solution(s,n)

def memoized_cut_rod_aux(p,n,r,s,valor_fixo):
    
    if r[n] >= 0:
        return r[n]
   
    if n == 0:
        q = 0
    else:
        q = -float("inf")    
        for i in range(1, n+1):
            current = (p[i - 1] + memoized_cut_rod_aux(p,n-i, r,s,valor_fixo))
            if n != i:
                current -= valor_fixo
                q = max(q , current)
            if current > q:
                q = current
                s[n] =i
        r[n] = q
        return q
        
def print_solution(s,n):   
    while n > 0:
        print(s[n], end="")
        n -= s[n]
        print()


#QUESTÃO 4

def Servidores(T):
    n = len(T)

    if n == 0:
        return [0], 0
    
    if n == 1:
        return T[0], 0
    
    dp = [0] * n 
    escolhido = [False] * n 

    dp[0] = T[0]
    dp[1] = max(T[0], T[1])
    escolhido[0] = True if  T[0] > T[1] else False
    escolhido[1] = not escolhido[0]

    for i in range(2, n):
        if dp[i -1] > dp[i -2] + T[i]:
            dp[i] = dp[i -1] 
            escolhido[i] = False
        else:
            dp[i]= dp[i -2] + T[i]
            escolhido[i]= True

    servidores_escolhidos = []
    i= n-1

    while i >= 0:
        if escolhido[i]:
            servidores_escolhidos.append(i)
            i -=2
        else:
            i -=1
    servidores_escolhidos.reverse()

    print(dp[n -1], servidores_escolhidos)    


#QUESTÃO 5

def viagem(C):
    n = len(C)

    if n == 0 :
        return 0 , [0]
    
    if n == 1:
        return C[0] , [0]
    
    dp = [0] * n 
    prev = [-1] * n

    dp[0] = C[0]
    dp[1] = C[1]
    prev[0] = -1
    prev[1] = -1

    for i in range(2,n):
        if dp[n -1] < dp[n -2]:
            dp[i] = C[i] + dp[n -1]
            prev[i] = i - 1

        else:
            dp[i] = C[i] + dp[n -2]
            prev[i] = i - 2

    if dp[n - 1] < dp[n - 2]:
        custo_min = dp[n - 1]
        atual = n - 1
    else:
        custo_min = dp[n - 2]
        atual = n - 2  

    caminho = []
    while atual != -1:
        caminho.append(atual)
        atual = prev[atual]
    
    caminho.reverse()
    return custo_min, caminho  


#Questão 6

def fintech(R):

    n = len(R)

    max_ending_here = R[0]
    max_ending = R[0]

    end = 0
    start = 0
    s = 0

    for i in range(1, n):
        if R[i] > max_ending_here + R[i]
            R[i] = max_ending_here
            s = i
        else:
            max_ending_here += R[i]

        if max_ending_here > max_ending:
            max_ending = max_ending_here
            start = s
            end =i

        return max_ending,R[start:end+1]]

    
          