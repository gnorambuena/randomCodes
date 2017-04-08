import turtle
#fractalPeano: int num -> None
#dibuja un fractal de peano de nivel n y lado L
#ej: fractalPeano(0,100)
def fractalPeano(n,L):
      if n==0:
            turtle.forward(L)
      else:
            fractalPeano(n-1,L/3)
            turtle.left(90)
            fractalPeano(n-1,L/3)
            turtle.right(90)
            fractalPeano(n-1,L/3)
            turtle.right(90)
            fractalPeano(n-1,L/3)
            turtle.right(90)
            fractalPeano(n-1,L/3)
            turtle.left(90)
            fractalPeano(n-1,L/3)
            turtle.left(90)
            fractalPeano(n-1,L/3)
            turtle.left(90)
            fractalPeano(n-1,L/3)
            turtle.right(90)
            fractalPeano(n-1,L/3)
