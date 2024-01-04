import mat

numero = int(input("Digite um número para verificar se é ímpar: "))
if mat.impar(numero):
    print(f"{numero} é ímpar")
else:
    print(f"{numero} não é ímpar")

raio = float(input("Digite o raio do círculo para calcular a área: "))
area = mat.area_circulo(raio)
print(f"A área do círculo com raio {raio} é {area:.2f}")
