import numpy as np

def interpolacao_lagrange(valores_x, valores_y, x_alvo):
    resultado = 0
    n = len(valores_x)

    for i in range(n):
        termo = valores_y[i]
        for j in range(n):
            if j != i:
                termo = termo * (x_alvo - valores_x[j]) / (valores_x[i] - valores_x[j])
        resultado += termo

    return resultado

def coeficientes_diferencas_divididas(valores_x, valores_y):
    n = len(valores_x)
    coeficientes = np.zeros((n, n))

    # Preencher a primeira coluna com os valores de y
    coeficientes[:, 0] = valores_y

    # Calcular as diferenças divididas
    for j in range(1, n):
        for i in range(n - j):
            coeficientes[i, j] = (coeficientes[i + 1, j - 1] - coeficientes[i, j - 1]) / (valores_x[i + j] - valores_x[i])

    return coeficientes[0, :]

def interpolacao_newton(valores_x, valores_y, x_alvo):
    coeficientes = coeficientes_diferencas_divididas(valores_x, valores_y)
    resultado = 0
    n = len(coeficientes)

    for i in range(n):
        termo = coeficientes[i]
        for j in range(i):
            termo = termo * (x_alvo - valores_x[j])
        resultado += termo

    return resultado

# Dados para os conjuntos de pontos
pontos_a = np.array([(0, 1), (1, 2), (1, 3), (4, 10)])
pontos_b = np.array([(-3, 1), (-2, 2), (1, 0), (4, 10), (7, 8)])
pontos_c = np.array([(-5, 2), (-3, 4), (1, 5), (4, -6), (7, -9), (10, -15)])
pontos_d = np.array([(-6, 4), (4, 9), (9, 0), (17, -7)])

# Pontos x e y para cada conjunto
valores_x_a, valores_y_a = pontos_a.T
valores_x_b, valores_y_b = pontos_b.T
valores_x_c, valores_y_c = pontos_c.T
valores_x_d, valores_y_d = pontos_d.T

# Ponto de interesse para avaliar o polinômio interpolador
x_alvo = 2

# Encontrar polinômio interpolador utilizando Lagrange
resultado_lagrange_a = interpolacao_lagrange(valores_x_a, valores_y_a, x_alvo)
resultado_lagrange_b = interpolacao_lagrange(valores_x_b, valores_y_b, x_alvo)
resultado_lagrange_c = interpolacao_lagrange(valores_x_c, valores_y_c, x_alvo)
resultado_lagrange_d = interpolacao_lagrange(valores_x_d, valores_y_d, x_alvo)

# Encontrar polinômio interpolador utilizando Newton
resultado_newton_a = interpolacao_newton(valores_x_a, valores_y_a, x_alvo)
resultado_newton_b = interpolacao_newton(valores_x_b, valores_y_b, x_alvo)
resultado_newton_c = interpolacao_newton(valores_x_c, valores_y_c, x_alvo)
resultado_newton_d = interpolacao_newton(valores_x_d, valores_y_d, x_alvo)

# Imprimir resultados
print("Polinômio interpolador usando Lagrange para (0, 1), (1, 2), (1, 3), (4, 10) é:", resultado_lagrange_a)
print("Polinômio interpolador usando Newton para (0, 1), (1, 2), (1, 3), (4, 10) é:", resultado_newton_a)
print("Polinômio interpolador usando Lagrange para (-3, 1), (-2, 2), (1, 0), (4, 10), (7, 8) é:", resultado_lagrange_b)
print("Polinômio interpolador usando Newton para (-3, 1), (-2, 2), (1, 0), (4, 10), (7, 8) é:", resultado_newton_b)
print("Polinômio interpolador usando Lagrange para (-5, 2), (-3, 4), (1, 5), (4, -6), (7, -9), (10, -15) é:", resultado_lagrange_c)
print("Polinômio interpolador usando Newton para (-5, 2), (-3, 4), (1, 5), (4, -6), (7, -9), (10, -15) é:", resultado_newton_c)
print("Polinômio interpolador usando Lagrange para (-6, 4), (4, 9), (9, 0), (17, -7) é:", resultado_lagrange_d)
print("Polinômio interpolador usando Newton para (-6, 4), (4, 9), (9, 0), (17, -7) é:", resultado_newton_d)
