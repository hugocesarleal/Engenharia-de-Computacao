import numpy as np


def gauss_seidel(A, b, x0, tol, iteracoes):
  n = len(A) # n é o número de linhas
  x = np.zeros(n, dtype='double') # Solução atual
  xant = x0 # Solução da iteração anterior
  for k in range(iteracoes): # Iterações do método
    for i in range(n): # Iterações para cada incógnita
      x[i] = b[i] # Termo constante
      for j in range(i): # Incógnitas anteriores
        x[i] -= A[i,j]*x[j]
      for j in range(i+1, n): # Incógnitas posteriores
        x[i] -= A[i,j]*xant[j]
      x[i] /= A[i,i] # Divisão pelo coeficiente da incógnita atual
    erro = np.linalg.norm(x-xant, np.inf) # Cálculo do erro
    print("Iteração {k:3d}: ".format(k=k+1) +
          "x={x}, ".format(x=np.round(x,8)) +
          "Erro={e:+5.8f}".format(e=erro))
    if (erro < tol): # Testa se erro é menor que a tolerância
      return x
    # Copia solução atual para ser a anterior na próxima iteração
    xant = np.copy(x)


# Entrada: M, b
M =np.array([
    [ 10, 1, 1, 2, 2],
    [ 1, -6, -2, 1, -2],
    [0, -1, 6, 0, 2],
    [2, 1, 1, 8, 0],
    [-2, 3, 0, 5, 3]
    ], dtype='double')
b = np.array([2, -2, 2, 0, 6], dtype='double')

# Aproximação inicial
x0 = np.array([0, 0, 0, 0, 0], dtype='double')
# Executa o método de Gauss-Seidel
x = gauss_seidel(M, b, x0, 0.0001, 40)
print('\nSolução aproximada encontrada')
print('x = (x1,x2,x3,x4,x5) = ', x)