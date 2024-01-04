import random

total_elementos = int(input("Informe o número total de elementos na lista: "))

quantidade_sorteio = int(input("Informe quantos elementos você deseja sortear: "))

if quantidade_sorteio > total_elementos:
    print("A quantidade de elementos a serem sorteados não pode ser maior que o número total de elementos na lista.")
else:
    lista_elementos = list(range(1, total_elementos + 1))

    random.shuffle(lista_elementos)

    elementos_sorteados = lista_elementos[:quantidade_sorteio]

    print(f"Elementos sorteados: {elementos_sorteados}")
