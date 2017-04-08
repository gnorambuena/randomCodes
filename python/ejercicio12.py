import estructura
import random
#Arbol Binario
#AB: valor(any), izq(AB), der(AB)
estructura.crear("AB","valor izq der")
estructura.crear("Lista","valor siguiente")
def rand_list(contador=0):
      if contador==15:
            return None
      return Lista(random.randint(1,100),rand_list(contador+1))
def insertar(x,A):
      assert A==None or type(A)==AB
      if A==None:
            return AB(x,None,None)
      v=A.valor
      if x==v:
            return A
      if x<v:
            return AB(v,insertar(x,A.izq),A.der)
      if x>v:
            return AB(v,A.izq,insertar(x,A.der))
      return
def list_to_abb(L,ab):
      if L==None:
            return ab
      ab=insertar(L.valor,ab)
      return list_to_abb(L.siguiente,ab)
def add_to_list(x,L):
      if L==None:
            return Lista(x,None)
      return Lista(L.valor,add_to_list(x,L.siguiente))
def lista_asc(ab,L):
      if ab==None:
            return
      lista_asc(ab.izq,L)
      L=add_to_list(ab.valor,L)
      lista_asc(ab.der,L)
      return L
def ordenar(L):
      ab=AB(L.valor,None,None)
      ab=list_to_abb(L.siguiente,ab)
      L=Lista(0,None)
      return lista_asc(ab,L)
      
L=rand_list()
print L
print ordenar(L)
