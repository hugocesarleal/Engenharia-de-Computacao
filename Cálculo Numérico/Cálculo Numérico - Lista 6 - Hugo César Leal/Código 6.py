import numpy as np
from sympy import symbols, diff

def eval_f(fx, x):
    return eval(fx)

def newton_raphson(f, fl, a, b, tol, n):
    xant = float("nan")
    x = (a + b) / 2
    for k in range(n):
        fx = eval_f(f, x)
        flx = eval_f(fl, x)
        gx = x - fx/flx
        error = abs((x-xant)/max(x, 1))
        print("Iteração {k:3d}: xant={xant:+.5f}, ".format(k=k, xant=xant) +
              "x={x:+.5f}, f(x)={fx:+.5f}, ".format(x=x, fx=fx) +
              "error={err:+.5f}, ".format(err=error))
        if (fx == 0) or (error < tol):
            print('')
            print("Raiz aproximada encontrada: {r:+5.5f}".format(r=x))
            break
        xant = x
        x = gx

x = symbols('x')

f = 'x-3-x**(-x)'
fl = '1 + (1+(np.log(x) / np.log(np.e) / x**x ))'

a = 2
b = 4
t = 0.00001
n = 20

newton_raphson(f, fl, a, b, t, n)