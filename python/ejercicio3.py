import triangulo
print "Tipo, area y perimetro de triangulo de lados a,b,c"
a=input("a?: ")
b=input("b?: ")
c=input("c?: ")
p=triangulo.perimetro(a,b,c)
area=triangulo.area(a,b,c)
tipo=triangulo.tipo(a,b,c)
if triangulo.rectangulo(a,b,c):
      print "tipo= ",tipo+" rectangulo"
else:
      print "tipo= ",tipo
print "Perimetro= ",p
print "Area= ",area
