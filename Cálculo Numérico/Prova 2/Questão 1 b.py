import numpy as np

A = np.array([
    [ 10, 1, 1, 2, 2, 2],
    [ 1, -6, -2, 1, -2, -2],
    [0, -1, 6, 0, 2, 2],
    [2, 1, 1, 8, 0, 0],
    [-2, 3, 0, 5, 3, 6]
    ], dtype='double')

print(A) # A matriz A é formada  em sua coluna por vetores

print("Norma 1: ", np.linalg.norm(A, 1))
print("Norma 2: ", np.linalg.norm(A, 2))
print("Norma infinito: ",np.linalg.norm(A, np.inf))