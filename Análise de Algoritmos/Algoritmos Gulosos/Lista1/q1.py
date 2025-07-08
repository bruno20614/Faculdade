'''''
No problema de Sele ̧c ̃ao de Atividades, suponha que, em vez de sempre selecionar
a primeira atividade a terminar, vocˆe selecione a  ́ultima atividade a come ̧car que
seja compat ́ıvel com todas as atividades selecionadas anteriormente. 
Apresente um algoritmo guloso que usa essa estrat ́egia para resolver o problema. Justifique infor-
malmente porque essa estrat ́egia garante a solu ̧c ̃ao  ́otima. Apresente o tempo de
execu ̧c ̃ao do seu algoritmo em nota ̧c ̃ao assint ́otica Θ.
'''

def selecao_atividades(s,f,n):
    atividades = [(s[i],f[i],i) for i in range(n)]

    atividades.sort(reverse=True)

    selecionados = []
    ultimo_inicio = float('inf')

    for inicio, fim, idx in atividades:
        if fim < ultimo_inicio:
            selecionados.append(idx)
            ultimo_inicio = inicio
    return selecionados        

# Θ(n log n)