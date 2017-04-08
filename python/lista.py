import estructura
#lista: valor(any) siguiente(lista)
estructura.crear("Lista","valor siguiente")
#cabeza: lista -> any
#primer valor de una lista
#ej: cabeza(lista("a",lista("b",None)))->"a"

def cabeza(L):
    assert type(L)==Lista
    return L.valor

assert cabeza(Lista("a",Lista("b",None)))=="a"
#cola: lista -> lista
#devuelve lista sin primera componente
#ej: cola(lista("a",lista("b",None)))->lista("b",None)

def cola(L):
    assert type(L)==Lista
    return L.siguiente

assert cola(Lista("a",Lista("b",None))) ==   Lista("b",None)
#esLista: lista -> bool
#True si L es una lista
#ej: esLista(lista(1,None))->True

def esLista(L):
  return type(L)==Lista or L==None

assert esLista(Lista(1,None))

#largo: lista -> int
#número de componentes de una lista L
#ej: largo(lista(5,lista(4,None)))->2

def largo(L):
    assert esLista(L)
    if L==None:
        return 0
    else:
        return 1 + largo(cola(L))

assert largo(Lista(5,Lista(4,None)))==2
assert largo(None)==0
#suma: lista -> num
#suma de una lista de numeros
#ejs: suma(lista(5,lista(4,None)))->9

def suma(L):
    assert esLista(L)
    if L==None:
        return 0
    else:
        return cabeza(L) + suma(cola(L))

assert suma(Lista(5,Lista(4,None)))==9
assert suma(None)==0

