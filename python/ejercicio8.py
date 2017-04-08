from fraccion import *
#promedio: fraccion -> None
#calcula el promedio de una sumatoria de fracciones, hasta que el num sea 0
#ej: promedio(2,fraccion(3/4)) -> 3/8
def  promedio(contador=0,sumatoria=fraccion(0,1)):
      num=input("numerador? ")
      if num==0:
            div=simplificar(division(sumatoria,fraccion(contador,1)))
            print div.numerador,"/",div.denominador
            return
      s=simplificar(suma(sumatoria,fraccion(num,input("denominador?"))))
      print "cuenta=",contador+1," suma=",s.numerador,"/",s.denominador
      return promedio(contador+1,s)
promedio()
v
