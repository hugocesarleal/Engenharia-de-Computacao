import numpy as np


def fatora_lu(A):
  U = np.copy(A) # Copia A para U
  n = len(U) # n é o número de linhas de U
  L = np.eye(n) # matriz identidade
  for j in range(n-1): # Fixa na coluna j
    for i in range(j+1, n): # Fixa na linha i
      L[i, j] = U[i, j] / U[j, j] # Calcula L_i,j
      # Altera linha i de U a partir da coluna j
      for k in range(j, n):
        U[i, k] = U[i, k] - L[i, j] * U[j, k]
  return L, U




def resolve_diag_inf(L, b):
  n = len(L) # n é o número de linhas de L
  y = np.arange(n, dtype='double') # Cria vetor y de tamanho n
  y[0] = b[0] / L[0, 0] # y_1 já está isolado
  # Resolve demais icógnitas
  for i in range(1, n):
    # Soma das icógnitas já resolvidas
    soma = 0
    for j in range(0, i):
      soma += y[j] * L[i, j]
    # y_i = b_i - (soma das demais icógnitas)
    y[i] = b[i] - soma
  return y



def resolve_diag_sup(U, y):
  n = len(U)
  x = np.arange(n, dtype='double')
  # x_n = y_n / U_n,n
  x[n-1] = y[n-1] / U[n-1, n-1]
  # Percorre as linhas (em ordem decrescente)
  for i in range(n-2, -1, -1):
    soma = 0
    # Soma das icógnitas já resolvidas (depois da diagonal)
    for j in range(i+1, n):
      soma += x[j] * U[i, j]
    # x_i = (y_i - (soma das demais icógnitas)) / U_i,i
    x[i] = (y[i] - soma) / U[i, i]
  return x


def determinante(U):
  n = len(U)
  det = 1
  for i in range(n):
    det *= U[i, i]
  return det


M =np.array([
    [ 10, 1, 1, 2, 2],
    [ 1, -6, -2, 1, -2],
    [0, -1, 6, 0, 2],
    [2, 1, 1, 8, 0],
    [-2, 3, 0, 5, 3]
    ], dtype='double')
b = np.array([2, -2, 2, 0, 6], dtype='double')

# Fatoração LU
L, U = fatora_lu(M)
print('Matriz L')
print(L)
print('Matriz U')
print(U)
print('')

# Analise do determinante de U
d = determinante(U)
print('determinante:', d)
print('')

# Resolução
y = resolve_diag_inf(L, b)
print('Solução do sistema Ly=b')
print('y =', y)
x = resolve_diag_sup(U, y)
print('Solução do sistema Ux=y e solução do sistema Ax=b')
print('x =', x)