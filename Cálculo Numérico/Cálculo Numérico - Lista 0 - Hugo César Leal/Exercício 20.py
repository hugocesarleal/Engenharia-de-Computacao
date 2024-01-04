lista1 = []
lista2 = []

print("Digite os números da primeira lista:")
for i in range(10):
    numero = float(input(f"Digite o {i+1}º número: "))
    lista1.append(numero)

print("\nDigite os números da segunda lista:")
for i in range(10):
    numero = float(input(f"Digite o {i+1}º número: "))
    lista2.append(numero)

lista_soma = []

for i in range(10):
    lista_soma.append(lista1[i] + lista2[i])

print("\nResultado da soma das duas listas:")
print(lista_soma)
