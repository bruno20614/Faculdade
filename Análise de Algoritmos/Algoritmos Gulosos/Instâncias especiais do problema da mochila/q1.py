''''
Exr 11.2 O problema subset sum do exercício 10.14 pode ser resolvido por um algoritmo guloso?
O problema tem a propriedade da escolha gulosa?
Exr 11.3 [Problema do disquete, CLRS 16.2-3 simplificado ] Escreva um algoritmo guloso para o
seguinte problema: dados números inteiros não-negativos w1, . . . , wn e W , encontrar um subcon-
junto máximo K de {1, . . . , n} dentre os que satisfazem P
k∈K wk ≤ W . (Imagine que w1, . . . , wn
são os tamanhos de arquivos digitais que você deseja armazenar em um disquete de capacidade W .
Compare com os exercícios 10.14 e 10.16.)1
1 CLRS exige que os wi sejam distintos dois a dois. Esse caso particular do problema pode ser formulado assim:
dado um conjunto T de inteiros não-negativos e um inteiro não-negativo W , encontrar um subconjunto máximo S de T
tal que P
s∈S s ≤ W . Mas essas restrições não tornam o problema mais fácil.
70
CAPÍTULO 11. ESTRATÉGIA GULOSA 71
Exr 11.4 [Mochila fracionária, CLRS 16.2-1 ] O problema da mochila fracionária consiste no se-
guinte: dados números inteiros2 não-negativos v1, . . . , vn, w1, . . . , wn e W (imagine que wi é o peso
e vi é o valor do objeto i), encontrar números racionais x1, . . . , xn no intervalo fechado [0, 1] que
maximizem a soma x1v1 +· · ·+xnvn enquanto respeitam a restrição x1w1 +· · ·+xnwn ≤ W . Escreva
um algoritmo guloso para resolver o problema. (Para simplificar, basta que seu algoritmo devolva
o valor de uma solução, ou seja, o valor da soma x1v1 + · · · + xnvn.) Prove que o seu algoritmo
está correto. Dê um exemplo para mostrar que o algoritmo não resolve o problema booleano da
mochila (exercício 10.17).
Exr 11.5 O problema da mochila booleana (exercício 10.17) pode ser resolvido por um algoritmo
guloso?
Exr 11.6 Seja P um inteiro positivo e seja ⟨p1, . . . , pn⟩ uma sequência de números inteiros não-
negativos. Considere os seguintes problemas. Problema 1: Encontrar um subconjunto X de
{1, . . . , n} tal que P
i∈X pi ≤ P e P
i∈X pi é máximo. Problema 2: Encontrar um subconjunto X
de {1, . . . , n} que maximize P
i∈X pi sob a restrição P
i∈X pi ≤ P . Qual o consumo de tempo (em
notação O) do melhor algoritmo conhecido para cada um dos problemas?
'''



#okk em algoritmos gulosos ele vai ver o que é mais apetitoso naquele momento
#p = peso
#v = lista de valores dos itens
#n = número de itens disponiveis
#c = capacidade max da mochila

def Mochila_Fracionaria(p,v,n,c):
    ratio = [(v[i]/p[i],i) for i in range(n)]

    ratio.sort(reverse=True)

    x = [0] * n

    for r, i in ratio:
        if p[i] <=c:
            x[i] = 1
            c -=p[i]
        else:
            x[i] = c/p[i]
            break
    return x        

def mochila_fracionaria(valores, pesos, capacidade):
    n = len(valores)
    itens = [(valores[i], pesos[i], i) for i in range(n)]
    itens.sort(key=lambda item: item[0] / item[1], reverse=True)
    
    valor_total = 0
    for valor, peso, _ in itens:
        if capacidade == 0:
            break
        if peso <= capacidade:
            valor_total += valor
            capacidade -= peso
        else:
            fracao = capacidade / peso
            valor_total += valor * fracao
            capacidade = 0
    return valor_total


''''
Exr 11.3 [Problema do disquete, CLRS 16.2-3 simplificado ] Escreva um algoritmo guloso para o
seguinte problema: dados números inteiros não-negativos w1, . . . , wn e W , encontrar um subcon-
junto máximo K de {1, . . . , n} dentre os que satisfazem P k∈K wk ≤ W . (Imagine que w1, . . . , wn
são os tamanhos de arquivos digitais que você deseja armazenar em um disquete de capacidade W .
Compare com os exercícios 10.14 e 10.16.)
'''
from operator import itemgetter

def disquete_problem(tam_arquivo,C):
    arquivos_ordernados = sorted(enumerate(tam_arquivo),key=itemgetter(1), reverse=True)
    k = []
    soma = 0

    for idx, tamanho in arquivos_ordernados:
        if soma + tamanho <= C:
            k.append(idx) 
            soma += tamanho  
        else:
            break  
    return k      

'''''
Exr 11.4 [Mochila fracionária, CLRS 16.2-1 ] O problema da mochila fracionária consiste no se-
guinte: dados números inteiros2 não-negativos v1, . . . , vn, w1, . . . , wn e W (imagine que wi é o peso
e vi é o valor do objeto i), encontrar números racionais x1, . . . , xn no intervalo fechado [0, 1] que
maximizem a soma x1v1 +· · ·+xnvn enquanto respeitam a restrição x1w1 +· · ·+xnwn ≤ W . Escreva
um algoritmo guloso para resolver o problema. (Para simplificar, basta que seu algoritmo devolva
o valor de uma solução, ou seja, o valor da soma x1v1 + · · · + xnvn.) Prove que o seu algoritmo
está correto. Dê um exemplo para mostrar que o algoritmo não resolve o problema booleano da
mochila (exercício 10.17).
'''



