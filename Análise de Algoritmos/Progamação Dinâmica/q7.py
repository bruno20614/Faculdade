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
