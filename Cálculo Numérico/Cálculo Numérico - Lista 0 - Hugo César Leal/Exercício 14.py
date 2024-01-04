num1 = int(input("Digite o primeiro número: "))
num2 = int(input("Digite o segundo número: "))

while num2 != 0:
    temp = num2
    num2 = num1 % num2
    num1 = temp

mdc = num1

print(f"O MDC de {num1} e {num2} é {mdc}.")
