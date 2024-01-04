import random

lista_numeros = [random.randint(1, 10) for _ in range(100)]

print(lista_numeros)

contagem_numeros = [0] * 10

for numero in lista_numeros:
    contagem_numeros[numero - 1] += 1

for i in range(10):
    print(f"O número {i + 1} apareceu {contagem_numeros[i]} vezes na lista.")
