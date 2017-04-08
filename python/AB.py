import estructura
estructura.crear("AB","valor izq der")
#valores: AB -> int
#n° de valores de arbol A
#ej: valores(ab) -> 6

def valores(A):
  assert A==None or type(A)==AB
  if A==None: return 0
  return 1 + valores(A.izq) + valores(A.der)

#altura: AB -> int
#n° de niveles de valores de arbol A
#ej: altura(ab) -> 3

def altura(A):
  assert A==None or type(A)==AB
  if A==None: return 0
  return 1+max(altura(A.izq),altura(A.der))

#hojas: AB -> int
#n° de valores sin "hijos"
#ej: hojas(ab)->3

def hojas(A):
  assert A==None or type(A)==AB
  if A==None: return 0
  if A.izq==None and A.der==None: return 1
  return hojas(A.izq) + hojas(A.der)

#noHojas: AB -> int
#n° de valores con hijos (al menos uno)
#ej: noHojas(ab) -> 3

def noHojas(A):
  assert A==None or type(A)==AB
  return valores(A)-hojas(A)


#insertar: any, AB -> AB
#nuevo ABB insertando x en ABB A
#ej: insertar("A",AB("B",None,None))->
#                 AB("B",AB("A",None,None),None)
def insertar(x,A):
  assert A==None or type(A)==AB
  if A==None: return AB(x,None,None)
  v=A.valor
  assert x!=v
  if x<v: return AB(v, insertar(x,A.izq), A.der)
  if x>v: return AB(v, A.izq, insertar(x,A.der) )

assert insertar("A",AB("B",None,None))== AB("B",AB("A",None,None),None)
