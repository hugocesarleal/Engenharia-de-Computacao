import numpy as np


def jacobi(A, b, x0, tol, iteracoes):
  n = len(A) # n é o número de linhas
  x = np.zeros(n, dtype='double') # Solução atual
  xant = x0 # Solução da iteração anterior
  for k in range(iteracoes): # Iterações do método
    for i in range(n): # Iterações para cada incógnita
      x[i] = b[i] # Termo constante
      for j in range(i): # Incógnitas anteriores
        x[i] -= A[i,j]*xant[j]
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
M = np.array([[ 10, 1, 1, 2],
              [ 1, -6, -2, 1],
              [ 0, -1, 6, 0],
              [ 2, 1, 1, 8]], dtype='double')

b = np.array([2.5, -2.5, 2.1, 0.1], dtype='double')

x0 = np.array([1, 1, -1, 1], dtype='double')

x1 = jacobi(M, b, x0, 0.00001, 30)
x2 = gauss_seidel(M, b, x0, 0.00001, 30)

D = np.diag(np.diag(M))
L = np.tril(M)-D
U=np.triu(M)-D

TJ = -np.linalg.inv(D).dot(L+U)
TG = -np.linalg.inv(L+D).dot(U)

av_TJ, _ = np.linalg.eig(TJ) # Autovalores de TJ , o simbolo _ representa os autovetores de TJ, mas não usaremos os autovetores
raio_espectral_TJ = max(abs(av_TJ))

av_TG, _ = np.linalg.eig(TG) # Autovalores de TG
raio_espectral_TG = max(abs(av_TG))

if(raio_espectral_TJ < 1):
    print('\nA solução do sistema converge no método TJ')
else:
    print('\nA solução do sistema NÃO converge no método TJ')

if(raio_espectral_TG < 1):
    print('\nA solução do sistema converge no método TG')
else:
    print('\nA solução do sistema NÃO converge no método TG')


print('\nSolução aproximada encontrada pelo Método de Jacobi')
print('(x1,x2,x3,x4) = ', x1)

print('\nSolução aproximada encontrada pelo Método de Gauss Seidel')
print('(x1,x2,x3,x4) = ', x2)