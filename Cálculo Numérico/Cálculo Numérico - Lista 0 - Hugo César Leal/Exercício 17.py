from itertools import combinations

n = int(input("Digite o número de elementos em A: "))

A = list(range(1, n + 1))

comb = list(combinations(A, 3))

print(f"Todas as combinações de três elementos de A = {A} são:")

for c in comb:
    print(c)
