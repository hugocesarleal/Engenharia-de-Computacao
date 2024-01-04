import numpy as np


def le_matriz():
  M = []
  n = int(input('Informe o número de variáveis do sistema: '))
  print('Informe a matriz estendida do sistema (linha por linha)')
  for i in range(n):
    lin = input('Linha {i}: '.format(i=i))
    lin_num = lin.split(',')
    lin_num = [float(i) for i in lin_num]
    M.append(lin_num)
  M = np.array(M, dtype='double')
  return M


def linha_pivo(mat, lin, col):
  # Maior valor como o primeiro elemento
  maior = abs(M[lin,col])
  # Linha pivo como a linha do primeiro elemento
  lin_pivo = lin
  # n é o número de linhas de M (pode ser usado len(M) ou np.alen(M), dependendo da versão do python)
  n = len(M)
  # Percorremos a coluna col a partir de lin
  for i in range(lin, n):
    # Se o elemento da linha atual for maior
    if abs(M[i,col]) > maior:
      # Atualizamos o pivô
      maior = abs(M[i,col])
      lin_pivo = i
  return lin_pivo


def troca_linha(M, lin1, lin2):
  # Testa se a linhas são diferentes
  if lin1 != lin2:
    print('Troca de linhas: ', lin1, '<->', lin2)
    aux = np.copy(M[lin1, :])
    M[lin1, :] = np.copy(M[lin2, :]) # observem que a linha 1 recebe uma cópia da linha 2, sabem porque?
    M[lin2, :] = aux
    print(M)


def resolve_diag_sup(M):
  # n é o número de linhas de M
  n = len(M)
  # b é o vertor de termos constantes
  b = np.copy(M[:,n])
  # Cria vetor x para guardar a solução
  x = np.arange(n, dtype='double')
  # Última linha já está isolada
  # x_n = b_n / M_n,n
  x[n-1] = b[n-1] / M[n-1, n-1]
  # Percorre as linhas (em ordem decrescente, ignorando a última)
  for i in range(n-2, -1, -1):
    soma = 0
    # Soma as icógnitas já resolvidas (depois da diagonal)
    for j in range(i+1, n):
      soma += x[j] * M[i, j]
    # x_i = (b_i - (soma das icógnitas)) / M_i,i
    x[i] = (b[i] - soma) / M[i, i]
  return x

def gauss_pivo(M):
  # n é o número de linhas de M
  n = len(M)
  for c in range(n-1):
    print('\n\nColuna', c)
    l = linha_pivo(M, c, c)
    troca_linha(M, l, c)
    pivo = M[c,c]
    for l in range(c+1, n):
      print('\nL{l} <- L{l} - L{c} * '.format(l=l, c=c) +
            '{b} / {p}'.format(b=M[l,c], p=pivo))
      M[l, :] = M[l, :] - M[c, :] * M[l, c] / pivo
      print(M)
  return resolve_diag_sup(M)

M = le_matriz()
print('Matriz original')
print(M)

x = gauss_pivo(M)

print('\nSolução:')
n = len(x)
for i in range(n):
  print('x{i} = {val}'.format(i=i, val=x[i]))