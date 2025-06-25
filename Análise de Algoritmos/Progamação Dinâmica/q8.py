def encontrar_melhor_costura(d):
    m = len(d)
    n = len(d[0])
    
    dp = [[0] * n for _ in range(m)]
    
    caminho = [[-1] * n for _ in range(m)]

    for j in range(n):
        dp[0][j] = d[0][j]

    for i in range(1, m):
        for j in range(n):
            opcoes = []
            if j > 0:
                opcoes.append((dp[i-1][j-1], j-1))
            opcoes.append((dp[i-1][j], j))
            if j < n - 1:
                opcoes.append((dp[i-1][j+1], j+1))
            
            min_custo, col_prev = min(opcoes)
            dp[i][j] = d[i][j] + min_custo
            caminho[i][j] = col_prev

    min_total = min(dp[m-1])
    j_min = dp[m-1].index(min_total)

    seam = [0] * m
    seam[m-1] = j_min
    for i in range(m-1, 0, -1):
        seam[i-1] = caminho[i][seam[i]]

    return min_total, seam
