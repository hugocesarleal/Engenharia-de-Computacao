A = float(input("Digite o coeficiente A: "))
B = float(input("Digite o coeficiente B: "))
C = float(input("Digite o coeficiente C: "))

if A == 0:
    print("Isso não é uma equação de segundo grau.")
else:

    delta = B**2 - 4*A*C

    # Verificar o valor do discriminante para determinar as raízes
    if delta < 0:
        print("A equação não possui raízes reais.")
    elif delta == 0:
        raiz = -B / (2*A)
        print('A equação possui uma raiz real: x = ',raiz)
    else:
        raiz1 = (-B + delta**0.5) / (2*A)
        raiz2 = (-B - delta**0.5) / (2*A)
        print('A equação possui duas raízes reais: x1 = ',raiz1,' e x2 = ',raiz2)