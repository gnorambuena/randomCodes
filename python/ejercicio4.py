import division
a=input("Ingrese el numerador: ")
b=input("Ingrese el denominador: ")
r=division.mcd(max(a,b),min(a,b))
c=a/r
d=b/r
print "La fraccion simplicada es: ",c,"/",d
