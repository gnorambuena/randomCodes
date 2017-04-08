#triangulo: modulo grabado en triangulo.py
#valido: num num num -> bool
#entrega un valor boolean dependiendo si es un triangulo valido
#ej:valido(3,4,5) debe entregar True
def valido(a,b,c):
      return (a+b>c and a>0 and b>0 and c>0)
assert valido(3,4,5)==True
assert valido(3,-2,5)==False
#perimetro: num num num->num o string
#perimetro de un triangulo
#funciona solo si es un triangulo valido
#sino entrega el mensaje de no ser valido
#ej:perimetro(1,1,1) debe ser 3
def perimetro(a,b,c):
      if valido(a,b,c):
            return a+b+c
      else:
            return "Triangulo no es valido, no se puede calcular el Perimetro"
assert perimetro(1,1,1)==3
#area: num num num-> float o string
#area de un triangulo
#funciona solo si es un triangulo valido
#sino entrega el mensaje de no ser valido
#ej: area(3,4,5) debe ser 6.0
def area(a,b,c):
      if valido(a,b,c):
            s=(a+b+c)*0.5
            return (s*(s-a)*(s-b)*(s-c))**0.5
      else:
            return "Triangulo no es valido, no se puede calcular el Area"
assert area(3,4,5)==6.0
#tipo: num num num -> string
#retorna el tipo de triangulo
#ej: tipo(1,1,1) deberia ser Equilatero
def tipo(a,b,c):
      if (a==b and a==c):
            return "Equilatero"
      elif(a==b or b==c or a==c):
            return "Isosceles"
      else:
            return "Escaleno"
assert tipo(1,1,1)=="Equilatero"
assert tipo(1,2,3)=="Escaleno"
assert tipo(1,2,2)=="Isosceles"
#rectangulo: num num num -> bool
#entrega un valor True si es un triangulo rectangulo
#ej:rectangulo(3,4,5) deberia ser True
def rectangulo(a,b,c):
      m=max(a,b,c)
      if(m==a):
            return (a**2==b**2+c**2)
      if(m==b):
            return (b**2==a**2+c**2)
      else:
            return(c**2==a**2+b**2)
assert rectangulo(3,4,5)==True
assert rectangulo(5,4,3)==True
assert rectangulo(1,1,1)==False
