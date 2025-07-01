'''''
Vocˆe  ́e o gerente de um projeto de desenvolvimento de software da empresa DP
Health Solutions. O projeto  ́e dividido em n fases, como planejamento, an ́alise das
necessidades do cliente, defini ̧c ̃ao da arquitetura do sistema, defini ̧c ̃ao das interfaces,
defini ̧c ̃ao dos fluxos de dados, codifica ̧c ̃ao do software, testes de unidade, testes de
integra ̧c ̃ao, documenta ̧c ̃ao, implanta ̧c ̃ao e avalia ̧c ̃ao da implanta ̧c ̃ao.
Vocˆe fez o or ̧camento de cada fase com trˆes software houses. Todas elas conseguem
realizar todas as fases do projeto. Para cada fase do projeto, cada software house
define um or ̧camento potencialmente diferente das outras para concluir a fase. Al ́em
disso, uma software house pode concluir a primeira fase do projeto e depois outra
software house pode realizar a segunda fase, e assim por diante. Dessa forma, tamb ́em
s ̃ao estimados custos associados ao redirecionamento do projeto em cada fase entre
as software houses. Por exemplo, temos um custo de redirecionamento da primeira
software house para a segunda ap ́os a conclus ̃ao da fase de planejamento, temos um
custo de redirecionamento da terceira software house para a primeira ap ́os a fase de
defini ̧c ̃ao das interfaces, e assim por diante.
Seu objetivo  ́e determinar o menor custo necess ́ario para completar todas as fases
do projeto, levando em considera ̧c ̃ao os tempos de conclus ̃ao de cada fase em cada
software house e os custos de redirecionamento entre elas.
Dessa forma, vocˆe tem n fases, e cada fase i tem um custo cost[i][j] para a j- ́esima
software house. Al ́em disso, vocˆe tem um custo de redirecionamento redirect[i][j][k]
para redirecionar o projeto da j- ́esima software house para a k- ́esima software house
ap ́os a conclus ̃ao da fase i e para iniciar a fase i + 1. Usando programa ̧c ̃ao dinˆamica,
vocˆe deve criar um algoritmo que, a partir da entrada n, cost e redirect, retorne o
menor custo total para completar o projeto e que software house ficar ́a respons ́avel
por cada fase do projeto. Seu algoritmo deve resolver o problema em tempo O(n).
'''''
def menor_custo_projeto(n, cost, redirect):
    m = 3

    dp = [[float('inf')] * m for _ in range(n)]
    
    parent = [[-1] * m for _ in range(n)]

    for j in range(m):
        dp[0][j] = cost[0][j]

    for i in range(1, n):  
        for j in range(m):  
            for k in range(m):  
                custo = dp[i-1][k] + redirect[i-1][k][j] + cost[i][j]
                if custo < dp[i][j]:
                    dp[i][j] = custo
                    parent[i][j] = k

    ultimo_custo = min(dp[n-1])
    empresa_final = dp[n-1].index(ultimo_custo)

    caminho = [0] * n
    caminho[n-1] = empresa_final
    for i in range(n-1, 0, -1):
        caminho[i-1] = parent[i][caminho[i]]

    return ultimo_custo, caminho
