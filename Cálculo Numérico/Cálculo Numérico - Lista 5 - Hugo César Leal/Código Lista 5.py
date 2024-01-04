import numpy as np

def eval_f(fx, x):
    return eval(fx)

def ponto_fixo(f, g, a, b, tol, n):
    xant = float("nan")
    x = (a + b) / 2
    for k in range(n):
        xant = x
        x = eval_f(g, x)
        error = abs((x-xant)/max(x, 1))
        print("Iteração {k:3d}: x={x:+.6f}, ".format(k=k, x=xant) +
              "g(x)={gx:+.6f}, error={e:+.6f} ".format(gx=x, e=error))
        if (x == xant) or (error < tol):
            print('')
            print("Raiz aproximada encontrada: {r:+5.6f}".format(r=x))
            break


f = 'x-3-x**(-x)'
g = 'x-0.05*(x-3-x**(-x))'
gl = '1-0.05*(x-3-x**(-x))*(x+1)'
a = 2
b = 4
t = 0.00001
n = 20

ponto_fixo(f, g, a, b, t, n)