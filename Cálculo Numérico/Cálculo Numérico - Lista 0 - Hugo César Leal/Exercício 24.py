input_string = input("Digite uma lista de números inteiros separados por espaços: ")

numeros_str = input_string.split()

numeros_inteiros = [int(numero) for numero in numeros_str]

numeros_sem_repeticao = []

for numero in numeros_inteiros:
    if numero not in numeros_sem_repeticao:
        numeros_sem_repeticao.append(numero)

print("Números sem repetições:", numeros_sem_repeticao)
