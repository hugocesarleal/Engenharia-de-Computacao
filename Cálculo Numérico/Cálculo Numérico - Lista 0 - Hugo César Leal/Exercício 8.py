A = float(input("Digite o valor de A: "))
B = float(input("Digite o valor de B: "))
C = float(input("Digite o valor de C: "))

denominador = 2 * C + B
if denominador == 0:
    print("O denominador da fórmula é igual a zero. A divisão não é possível.")
else:
    N = ((A + B * C) - (A * B * C)**0.5) / denominador
    print('O valor de N é: ',N)