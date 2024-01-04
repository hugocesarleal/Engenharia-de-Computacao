def ano_bissexto(ano):
    if (ano % 4 == 0 and ano % 100 != 0) or (ano % 400 == 0):
        return True
    else:
        return False

def dias_mes(ano, mes):
    meses_com_31_dias = [1, 3, 5, 7, 8, 10, 12]
    meses_com_30_dias = [4, 6, 9, 11]

    if mes == 2:
        if ano_bissexto(ano):
            return 29
        else:
            return 28
    elif mes in meses_com_31_dias:
        return 31
    elif mes in meses_com_30_dias:
        return 30
    else:
        return None

def nome_mes(mes):
    nomes = [
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    ]
    if mes >= 1 and mes <= 12:
        return nomes[mes - 1]
    else:
        return None
20
try:
    ano = int(input("Digite o ano: "))
    mes = int(input("Digite o mês (1 a 12): "))

    if mes >= 1 and mes <= 12:
        bissexto = ano_bissexto(ano)
        quantidade_dias = dias_mes(ano, mes)
        nome_do_mes = nome_mes(mes)

        if bissexto:
            print(f"O ano {ano} é bissexto.")
        else:
            print(f"O ano {ano} não é bissexto.")

        if quantidade_dias is not None:
            print(f"{nome_do_mes} de {ano} tem {quantidade_dias} dias.")
        else:
            print("Mês inválido.")
    else:
        print("Mês inválido. O mês deve estar no intervalo de 1 a 12.")

except ValueError:
    print("Por favor, digite um ano e mês válidos.")
