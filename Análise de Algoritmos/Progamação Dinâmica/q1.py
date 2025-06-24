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

A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
n = 10

resultado = Foo(A, n)
print(resultado)


#Usando memoização, por que não memorização?
def Foo(A, n,memo = None):
    if n <= 4:
        return 0
    
    if memo is None:
        memo = {}
  
    for n in memo:
      return memo[n]

    val = (Foo(A, n//2,memo) + Foo(A, n//2 + 1,memo) + Foo(A, n//2 + 2,memo) + A[n-1]) 

    memo[n] = val
    return val

