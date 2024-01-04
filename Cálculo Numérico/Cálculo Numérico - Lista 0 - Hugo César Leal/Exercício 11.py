maior_numero = float('-inf')
menor_numero = float('inf')

while True:
    numero = float(input("Digite um número: "))
    
    if numero > maior_numero:
        maior_numero = numero
        
    if numero < menor_numero:
        menor_numero = numero
    
    continuar = input("Deseja continuar? (Digite 'sim' ou 's' para continuar, ou qualquer outra coisa para parar): ")
    
    if continuar.lower() != 'sim' and continuar.lower() != 's':
        break

print('O maior número informado foi: ',maior_numero)
print('O menor número informado foi: ',menor_numero)
