#produtos mais leves melhor menor peso
#maximizar o  valor da carga
#c = 40kg
def sistema_de_distribuição(peso, valor,c,n):
    ratio = [(valor[i],peso[i],i ) for i in range(n)]

    x = [0] * n
    y = 0

    for v,p,i in ratio:
        if p<= c:
            x[i] += 1
            c -= p
            y += v
        else:
            break

    return x, y    



