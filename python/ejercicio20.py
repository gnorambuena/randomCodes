from Fraccion import *
#solve: Fraccion Fraccion String -> Fraccion
#devuelve la solucion a la operacion pedida
#ej: solve(Fraccion(1,2),Fraccion(3,4),"+")==Fraccion(5,4)
def solve(f1,f2,op):
      if op=="+":
            return f1+f2
      if op=="-":
            return f1-f2
      if op=="*":
            return f1*f2
      if op=="/":
            return f1/f2
assert solve(Fraccion(1,2),Fraccion(3,4),"+")==Fraccion(5,4)
print "Calculadora de Fracciones"
while(True):
      s1=raw_input("Fraccion 1(nº/nº)?")
      s2=raw_input("Fraccion 2(nº/nº)?")
      op=raw_input("Operacion (+ - * /)?")
      s1=Fraccion(s1)
      s2=Fraccion(s2)
      respuesta=solve(s1,s2,op)
      print "Resultado=", respuesta
