import numpy as np
import matplotlib.pyplot as plot

def metodo_das_secantes(a, b, n, TOL, f):
    x = a
    x_prime = b

    for k in range(1, n + 1):
        epsilon = abs(x - x_prime) / max(abs(x), 1)  # Calcula erro

        print(f"Iteração {k}: x = {x}, f(x) = {f(x)}, ε = {epsilon}")

        if f(x) == 0 or epsilon < TOL:  # Testa o critério de parada
            break

        x_double_prime = x - f(x) * (x - x_prime) / (f(x) - f(x_prime))  # Calcula x_{n+1}
        x_prime = x  # Atualiza x_{n}
        x = x_double_prime  # Atualiza x_{n-1}

    return x

# Exemplo de uso
def f(x):
    return x-3-x**(-x)  # A equação para a qual queremos encontrar a raiz

a = 2
b = 4
n_iteracoes = 20
tolerancia = 10**(-5)

interval = np.linspace(a, b)

aproximacao_raiz = metodo_das_secantes(a, b, n_iteracoes, tolerancia, f)
print(f"\nAproximação da raiz: {aproximacao_raiz}")

plot.plot(interval, f(interval)) # plotar a função no intervalo
plot.grid() # coloca a grade no gráfico
plot.show() # exibição da figura/gráfico