print("Escolha a conversão desejada:")
print("1. Celsius para Fahrenheit")
print("2. Fahrenheit para Celsius")
opcao = int(input("Digite o número da opção desejada (1 ou 2): "))

if opcao == 1:
    celsius = float(input("Digite a temperatura em graus Celsius: "))
    fahrenheit = (celsius * 9/5) + 32
    print(f"{celsius} graus Celsius equivalem a {fahrenheit} graus Fahrenheit.")
    
elif opcao == 2:
    fahrenheit = float(input("Digite a temperatura em graus Fahrenheit: "))
    celsius = (fahrenheit - 32) * 5/9
    print(f"{fahrenheit} graus Fahrenheit equivalem a {celsius} graus Celsius.")
    
else:
    print("Opção inválida. Por favor, escolha 1 ou 2 para a conversão desejada.")
