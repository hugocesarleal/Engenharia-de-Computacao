import numpy as np
import matplotlib.pyplot as pyplot

def eval_f(fx, x):
    return eval(fx)

def plot(fx, a, b):
    interval = np.linspace(a, b)
    pyplot.plot(interval, eval_f(fx, interval))
    pyplot.grid()
    pyplot.show()

func = input('Informe a função: ')
a = float(input('Informe o início do intervalo: '))
b = float(input('Informe o fim do intervalo: '))

plot(func, a, b)