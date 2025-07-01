''''
Vocˆe trabalha em uma fintech e ficou respons ́avel pelo desenvolvimento de um m ́odulo
para avaliar o desempenho de carteiras de investimentos ao longo do tempo. A
rentabilidade da carteira  ́e registrada diariamente e pode variar, resultando em ganhos
(valores positivos) ou perdas (valores negativos). Seu objetivo  ́e identificar o per ́ıodo
cont ́ınuo de tempo em que a carteira teve o melhor desempenho acumulado.
Dessa forma, dado um vetor de inteiros R onde R[i] representa a rentabilidade di ́aria
da carteira no dia i, encontre o subvetor cont ́ınuo (contendo pelo menos um n ́umero)
que possui a maior soma e retorne essa soma.
Exemplos. Para entrada R = [−2, 1, −3, 4, −1, 2, 1, −5, 4], temos 6 como soma
m ́axima e a solu ̧c ̃ao  ́otima  ́e o subvetor [4, −1, 2, 1]. Para entrada R = [5, 4, −1, 7, 8],

temos 23 como soma m ́axima e a solu ̧c ̃ao  ́otima  ́e o subvetor [5, 4, −1, 7, 8], ou seja,
o pr ́oprio vetor de entrada.
Usando programa ̧c ̃ao dinˆamica, apresente um algoritmo para resolver esse problema.
Observe que seu algoritmo deve retornar a soma m ́axima e o subvetor com essa soma.
Seu algoritmo deve executar em tempo O(n).
'''
def max_subrray(R):
    n = len(R)

    max_ending_here = R[0]
    max_so_far = R[0]

    start = 0
    end = 0
    s = 0 

    for i in range(1,n):
        if R[i] > max_ending_here + R[i]:
            max_ending_here = R[i]
            s = i
        else:
            max_ending_here += R[i]

        if max_ending_here > max_so_far:
            max_so_far = max_ending_here
            start = s
            end = i    

    return max_so_far, R[start:end+1]

print(max_subrray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  
print(max_subrray([5, 4, -1, 7, 8]))         
    #OK eu preciso encontrar o subvetor com o maior cálculo

