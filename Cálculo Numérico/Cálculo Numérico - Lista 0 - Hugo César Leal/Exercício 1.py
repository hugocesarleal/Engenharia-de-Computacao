segundos = int(input("Digite o número de segundos: "))

horas = segundos // 3600
minutos = (segundos % 3600) // 60
segundos = segundos % 60

print(segundos, ' segundos é igual a ', horas,' horas, ', minutos,' minutos e ', segundos,' segundos.')

horas = int(input("Digite o número de horas: "))
minutos = int(input("Digite o número de minutos: "))
segundos = int(input("Digite o número de segundos: "))

total_segundos = (horas * 3600) + (minutos * 60) + segundos

print(horas,' horas, ', minutos,' minutos e ', segundos,' segundos é igual a ', total_segundos)