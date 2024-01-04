import numpy as np

M =np.array([
    [ 10, 1, 1, 2, 2],
    [ 1, -6, -2, 1, -2],
    [0, -1, 6, 0, 2],
    [2, 1, 1, 8, 0],
    [-2, 3, 0, 5, 3]
    ], dtype='double')
b = np.array([2, -2, 2, 0, 6], dtype='double')

x0 = np.array([1, 1, -1, 1, -1], dtype='double')

D = np.diag(np.diag(M))
L = np.tril(M)-D
U=np.triu(M)-D

TJ = -np.linalg.inv(D).dot(L+U)
TG = -np.linalg.inv(L+D).dot(U)

av_TJ, _ = np.linalg.eig(TJ) # Autovalores de TJ , o simbolo _ representa os autovetores de TJ, mas não usaremos os autovetores
raio_espectral_TJ = max(abs(av_TJ))

av_TG, _ = np.linalg.eig(TG) # Autovalores de TG
raio_espectral_TG = max(abs(av_TG))

print(M)

if(raio_espectral_TJ < 1):
    print('\nA solução do sistema converge no método TJ')
else:
    print('\nA solução do sistema NÃO converge no método TJ')

if(raio_espectral_TG < 1):
    print('\nA solução do sistema converge no método TG')
else:
    print('\nA solução do sistema NÃO converge no método TG')
