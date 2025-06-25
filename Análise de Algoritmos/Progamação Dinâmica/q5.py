''''
Vocˆe est ́a desenvolvendo um aplicativo para planejar uma viagem de carro por uma

s ́erie de cidades, onde cada cidade tem um custo associado, como alimenta ̧c ̃ao, hos-
pedagem e passeios tur ́ısticos. A entrada  ́e um vetor de inteiros positivos C onde C[i]

 ́e o custo associado `a parada na cidade i. Ap ́os pagar o custo de uma cidade, vocˆe
pode escolher dirigir para a pr ́oxima cidade ou pular uma cidade, indo diretamente
para a seguinte. Vocˆe pode iniciar sua viagem a partir da primeira ou da segunda
cidade. Dessa forma, dado o vetor C, seu algoritmo deve retornar o custo m ́ınimo
para completar a viagem e alcan ̧car o destino final.
Exemplos. Para entrada C = [10, 15, 20], temos 15 como custo m ́ınimo. Uma
solu ̧c ̃ao  ́otima consiste de iniciar na segunda cidade e pular a terceira cidade. Para
entrada C = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1], temos 6 como custo m ́ınimo. Uma solu ̧c ̃ao
 ́otima consiste de iniciar na primeira cidade, depois ir para a terceira, depois para
quinta, depois para a s ́etima, depois para a oitava, depois para a  ́ultima.
Usando programa ̧c ̃ao dinˆamica, apresente um algoritmo para resolver esse problema.
Observe que seu algoritmo deve retornar o custo m ́ınimo da viagem e as cidades que
ser ̃ao visitadas. Seu algoritmo deve executar em tempo O(n).
'''

#

def AlocaçãoDinamica(C):
    n = len(C)

    if n ==0:
        return 0, []
    
    if n == 1:
        return C[0], [0]
    

    #ok agora precisamos ver se começamos em C[0] ou C[1]

    #mas antes precissamos escrever os locais para guardar o dp

    dp = [0] * n
    prev = [-1] * n

    dp[0] = C[0]
    dp[1] = C[1]

    for i in range (2,n):
        if dp[i - 1] < dp[i - 2]:
            dp[i] = C[i] + dp [i - 1]
            prev[i]  = i - 1
        else:
            dp[i] = C[i]  + dp[i - 2]   
            prev[i] = i - 2

    if dp[n - 1] < dp[n - 2]:
        custo_min = dp[n - 1]
        atual = n - 1
    else:
        custo_min = dp[n - 2]
        atual = n - 2

    # Reconstrução do caminho
    caminho = []
    while atual != -1:
        caminho.append(atual)
        atual = prev[atual]
    
    caminho.reverse()
    return custo_min, caminho               


print(AlocaçãoDinamica([2, 7, 9, 3, 1,10]))







