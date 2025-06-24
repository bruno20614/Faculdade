''''
Você  ́e um administrador de uma rede de servidores distribuídos e precisa alocar a
carga de trabalho entre eles de maneira eficiente. Cada servidor pode processar uma
quantidade específica de tarefas em um determinado período de tempo, representado
por um vetor de inteiros positivos T, onde T[i]  ́e a quantidade de tarefas que o servidor

i pode processar. Al ́em disso, os servidores est ̃ao dispostos em sequência. Por motivos
de seguran ̧ca e integridade da rede, voccê não pode sobrecarregar servidores adjacentes
ao mesmo tempo, pois isso pode causar falhas ou sobrecarga na rede.
Dessa forma, dado um vetor de inteiros positivos T representando a capacidade de
processamento de cada servidor, devemos retornar a quantidade m ́axima de tarefas

que podem ser processadas pela rede sem causar sobrecarga, evitando ativar servido-
res adjacentes simultaneamente. Al ́em disso, a solu ̧c ̃ao  ́otima consiste dos servidores

que ser ̃ao escolhidos.
Exemplos. Para entrada T = [2, 7, 9, 3, 1] temos 12 como a quantidade m ́axima
de tarefas. Nesse caso, os servidores escolhidos na solu ̧c ̃ao  ́otima s ̃ao o primeiro, o
terceiro e o quinto. Para entrada T = [2, 1, 1, 2] temos 4 como quantidade m ́axima
de tarefas escolhendo o primeiro e o  ́ultimo servidores.
Usando programa ̧c ̃ao dinâmica, apresente um algoritmo para resolver esse problema.

Observe que seu algoritmo deve retornar a quantidade m ́axima de tarefas e os servi-
dores escolhidos. Seu algoritmo deve executar em tempo O(n).
'''


#Rede de Servidores,vetor de inteiros T , onde T[i] é a quantidade de tarefas que o servidor i pode processar
#Além disso os servidores estão em sequência
#Ele quer que retornemos a quantoade máxima de tarefas que podem ser processada pela rede sem causar sobrecarga e a solução otima consiste dos servidores que serão escolhidos
#então ele quer o numero maximo de tarefas e os servidores escolhidos
#Para uma entrada T = [2, 7, 9, 3, 1] temos 12 como a quantiade maxima e

def AlocacaoDinamica(T):
    n = len(T)
    if n == 0:
        return 0, []
    if n == 1:
        return T[0], [0]

    dp = [0] * n
    escolha = [False] * n  

    dp[0] = T[0]
    dp[1] = max(T[0], T[1])
    escolha[0] = True if T[0] >= T[1] else False
    escolha[1] = not escolha[0]

    for i in range(2, n):
        if dp[i - 1] > dp[i - 2] + T[i]:
            dp[i] = dp[i - 1]
            escolha[i] = False
        else:
            dp[i] = dp[i - 2] + T[i]
            escolha[i] = True

    servidores_usados = []
    i = n - 1
    while i >= 0:
        if escolha[i]:
            servidores_usados.append(i)
            i -= 2  
        else:
            i -= 1

    servidores_usados.reverse()
    return dp[-1], servidores_usados

print(AlocacaoDinamica([2, 7, 9, 3, 1]))  # (12, [0, 2, 4])
print(AlocacaoDinamica([2, 1, 1, 2]))     # (4, [0, 3])


             
        
#Eu tenho que fazer alguma forma de guardar todas as combinações de cada servidor, mas como?????????


