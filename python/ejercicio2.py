import triangulo
a=input("Ingrese el primer lado del triangulo: ")
b=input("Ingrese el segundo lado del triangulo: ")
c=input("Ingrese el tercer lado del triangulo: ")
p=triangulo.perimetro(a,b,c)
area=triangulo.area(a,b,c)
print "Perimetro= ",p
print "Area= ",area
