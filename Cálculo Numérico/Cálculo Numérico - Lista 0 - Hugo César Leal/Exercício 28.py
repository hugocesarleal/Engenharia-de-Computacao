import math

def calcular_mdc(a, b):
    while b:
        a, b = b, a % b
    return a

def calcular_mmc(a, b):
    return a * b // calcular_mdc(a, b)

def calcular_mdc_lista(lista):
    if len(lista) < 2:
        raise ValueError("A lista deve conter pelo menos dois números para calcular o MDC.")

    mdc_result = lista[0]
    for num in lista[1:]:
        mdc_result = calcular_mdc(mdc_result, num)
    return mdc_result

def calcular_mmc_lista(lista):
    if len(lista) < 2:
        raise ValueError("A lista deve conter pelo menos dois números para calcular o MMC.")

    mmc_result = lista[0]
    for num in lista[1:]:
        mmc_result = calcular_mmc(mmc_result, num)
    return mmc_result

try:
    numeros = input("Digite uma lista de números separados por espaços: ").split()
    numeros = [int(num) for num in numeros]

    mdc = calcular_mdc_lista(numeros)
    mmc = calcular_mmc_lista(numeros)

    print(f"O MDC dos números é: {mdc}")
    print(f"O MMC dos números é: {mmc}")

except ValueError as e:
    print(f"Erro: {e}")
except ZeroDivisionError:
    print("Erro: Divisão por zero.")
except Exception as e:
    print(f"Erro inesperado: {e}")
