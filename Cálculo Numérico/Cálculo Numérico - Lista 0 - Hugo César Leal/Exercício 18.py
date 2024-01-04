from itertools import combinations

n = int(input("Digite o número de elementos em A: "))

A = set(range(1, n + 1))

subconjuntos = list(combinations(A, 3))

print(f"Todos os subconjuntos de três elementos de A = {A} são:")
for subconjunto in subconjuntos:
    print(subconjunto)
