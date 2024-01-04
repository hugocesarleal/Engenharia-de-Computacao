import numpy as np

A = np.array([
    [ 10, 1, 1, 2],
    [ 1, -6, -2, 1],
    [0, -1, 6, 0],
    [2, 1, 1, 8]
    ], dtype='double')

print(A) # A matriz A é formada  em sua coluna por vetores

print(np.linalg.norm(A, 1))
print(np.linalg.norm(A, 2))
print(np.linalg.norm(A, np.inf))