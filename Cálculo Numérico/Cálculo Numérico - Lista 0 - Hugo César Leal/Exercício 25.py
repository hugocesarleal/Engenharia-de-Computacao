def input_int(mensagem):
    while True:
        try:
            entrada = int(input(mensagem))
            return entrada
        except ValueError:
            print("Número inválido. Tente novamente.")

def input_float(mensagem):
    while True:
        try:
            entrada = float(input(mensagem))
            return entrada
        except ValueError:
            print("Número inválido. Tente novamente.")

numero_inteiro = input_int("Digite um número inteiro: ")
numero_float = input_float("Digite um número de ponto flutuante: ")

print(f"Você digitou o número inteiro: {numero_inteiro}")
print(f"Você digitou o número de ponto flutuante: {numero_float}")
