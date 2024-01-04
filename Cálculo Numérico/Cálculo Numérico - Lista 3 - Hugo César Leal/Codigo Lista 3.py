import numpy as np

def f(x):
  return x-3-(x**(-x))

def bissecao(a, b, tol, n):
  
  xant = float('nan')
  
  for i in range(n):
    
    x = (a + b) / 2
    fx = f(x)
    
    sinal = f(a) * fx
    
    error=abs((x-xant)/max(x, 1))
    
    xant = x
    
    print('It. {i:3d}:'.format(i=i), 'a={a:+.6f},'.format(a=a), 'b={b:+.6f},'.format(b=b), 'error={e:+.6f},'.format(e=error), 'x={x:+.6f},'.format(x=x), 'f(x)={fx:+.6f},'.format(fx=fx), 'sinal={s:+.6f}'.format(s=sinal))
    
    if (fx == 0) or (error < tol):
      
      print('Raiz aproximada encontrada: {r:+.6f}'.format(r=x))
      
      break
    
    if sinal > 0:
      a = x
    else:
      b = x
  if i == n:
    print('Raiz aproximada encontrada: {r:+.6f}'.format(r=x))

bissecao(2, 4, 0.00001, 20)