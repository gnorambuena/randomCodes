from lista import *
from fraccion import *
#menorQue: fraccion(int,int) fraccion(int,int)  -> bool
#True si fraccion1 < fraccion2
#ej: menorQue(fraccion(1,2),fraccion(3,4))-> True
def menorQue(fraccion1,fraccion2):
      assert type(fraccion1)==fraccion and type(fraccion2)==fraccion
      return fraccion1.numerador*fraccion2.denominador<fraccion2.numerador*fraccion1.denominador
assert menorQue(fraccion(1,2),fraccion(3,4))
assert not menorQue(fraccion(1,3),fraccion(1,4))
#filtro: lista(fraccion(int int)) (fraccion(int int) fraccion(int int)->bool) fraccion(int int) -> lista(fraccion(int int) None)
#lista con valores de L que cumplen comparacion con x
#ej:filtro(lista(fraccion(1,2),lista(fraccion(3,4),None)),menorQue,fraccion(5,8))->lista(fraccion(1,2),None)

def filtro(L,comparacion,x):
      assert esLista(L)
      if L==None: 
            return None

      if comparacion(cabeza(L),x):
            return lista(cabeza(L),filtro(cola(L),comparacion,x))

      return filtro(cola(L),comparacion,x)
assert filtro(lista(fraccion(1,2),lista(fraccion(3,4),None)),menorQue,fraccion(5,8))==lista(fraccion(1,2),None)
#invertirfraccion fraccion(int int) -> fraccion(int int)
#invierte una fraccion siempre y cuando el numerador no sea 0
#ej:invertirfraccion(fraccion(4,5))->fraccion(5,4)
def invertirfraccion(f):
      if f.numerador==0:
            return None
      else:
            return fraccion(f.denominador,f.numerador)
assert invertirfraccion(fraccion(4,5))==fraccion(5,4)
assert invertirfraccion(fraccion(0,1))==None
#mapa: (any->any) lista(any) -> lista(any)
#lista aplicando funcion a valores de L
#ej: mapa(f,lista(5,lista(4,None))) ->
#    lista(f(5),lista(f(4),None))

def mapa(funcion,L):
    assert esLista(L)
    if L==None: return None
    y=funcion(cabeza(L))
    return lista(y,mapa(funcion,cola(L)))
L=lista(fraccion(4,5),lista(fraccion(1,5),lista(fraccion(1,10),None)))
print "Lista Original:",L
print "Filtro(fraccion(2,5)):",filtro(L,menorQue,fraccion(2,5))
print "Fraccion invertida:",mapa(invertirfraccion,L)
