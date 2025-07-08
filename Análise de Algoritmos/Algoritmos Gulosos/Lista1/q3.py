def sistema_logistico(peso,n,C):
    relação = [(peso[i],i ) for i in range(n)]

    x = [0] * n

    for p , i in relação:
        if p <=C:
            x[i] = 1
            C -= p
    return x        
