num_trechos = int(input("Informe o número de trechos da viagem (entre 1 e 50): "))

distancias = []
velocidades = []

for i in range(num_trechos):
    distancia = float(input(f"Informe a distância do trecho {i + 1} (em km): "))
    velocidade = float(input(f"Informe a velocidade média do trecho {i + 1} (em km/h): "))
    distancias.append(distancia)
    velocidades.append(velocidade)

soma_distancias = sum(distancias)
soma_velocidades = sum(distancias[i] * velocidades[i] for i in range(num_trechos))
velocidade_media = soma_velocidades / soma_distancias

print(f"A velocidade média da viagem foi de {velocidade_media:.2f} km/h")

print("Trechos com velocidade acima da média:")
for i in range(num_trechos):
    if velocidades[i] > velocidade_media:
        print(f"Trecho {i + 1}: {velocidades[i]:.2f} km/h")
