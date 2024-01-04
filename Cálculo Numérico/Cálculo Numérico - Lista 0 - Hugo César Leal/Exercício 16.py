while True:
    print("\nCalculadora Simples")
    print("Escolha uma operação:")
    print("1. Soma")
    print("2. Subtração")
    print("3. Multiplicação")
    print("4. Divisão")
    print("5. Potenciação")
    print("6. Sair")
    
    escolha = input("Digite o número da operação desejada: ")
    
    if escolha == '6':
        print("Calculadora encerrada.")
        break
    
    if escolha not in ['1', '2', '3', '4', '5']:
        print("Opção inválida. Escolha uma operação válida.")
        continue
    
    num1 = float(input("Digite o primeiro número: "))
    num2 = float(input("Digite o segundo número: "))
    
    if escolha == '1':
        resultado = num1 + num2
        print(f"A soma de {num1} e {num2} é igual a {resultado}.")
    elif escolha == '2':
        resultado = num1 - num2
        print(f"A subtração de {num1} e {num2} é igual a {resultado}.")
    elif escolha == '3':
        resultado = num1 * num2
        print(f"A multiplicação de {num1} e {num2} é igual a {resultado}.")
    elif escolha == '4':
        if num2 == 0:
            print("Erro: Divisão por zero não permitida.")
        else:
            resultado = num1 / num2
            print(f"A divisão de {num1} por {num2} é igual a {resultado}.")
    elif escolha == '5':
        resultado = num1 ** num2
        print(f"{num1} elevado a {num2} é igual a {resultado}.")