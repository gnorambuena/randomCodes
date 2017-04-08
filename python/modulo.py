import estructura
estructura.mutable("Nodo","elemento izq der")
L=[]
def valido(arbol):
      #no existe un arbol valido con none, en caso de que sea un int
      #se retorna true
      if arbol==None:
            return False
      if type(arbol)!=Nodo:
            return False
      s=arbol.elemento
      #chequear si ambos hijos no son none
      if s=="+" or s=="-" or s=="/" or s=="*":
            if arbol.izq==None or arbol.der==None:
                  return False
            return valido(arbol.izq) and valido(arbol.der)
      #si es un int retornar true
      if type(s)==int:
            return True
      #si no para ningun test retornar false
      return False
def build():
      global L
      #aqui prueba si es una expresion valida
      if len(L)==0:
            return
      s=L.pop(0)
      #se comprueba de que clase es el elemento
      if s=="+" or s=="-" or s=="/" or s=="*" or s==None:
            return Nodo(s,build(),build())
      else:
            return Nodo(int(s),None,None)
def construir(expresion):
      assert type(expresion)==str or expresion==None
      global L
     #sacar elemento de la expresion
      L=expresion.split(" ")
      #construir arbol
      arbol=build()
      if not valido(arbol):
            arbol=None
            return
      return arbol
def evaluar(arbol):
      if valido(arbol) and arbol!=None:
            element=arbol.elemento
            if type(element)==int:
                  return element
            #caso 1 es suma
            if element=="+":
                  return evaluar(arbol.izq)+evaluar(arbol.der)
            #caso 2 es resta
            if element=="-":
                  return evaluar(arbol.izq)-evaluar(arbol.der)
            #caso 3 es division
            if element=="/":
                  return evaluar(arbol.izq)/evaluar(arbol.der)
            #caso 4 es multiplicacion
            if element=="*":
                  return evaluar(arbol.izq)*evaluar(arbol.der)
      return
def aux_str(raiz):
      assert type(raiz)==Nodo or raiz==None
      #esta funcion es la que hace el trabajo de armar la lista
      if raiz==None:
            return
      else:
            global L
            s=raiz.elemento
            L.append(str(s))
            return nodo2str(raiz.izq),nodo2str(raiz.der)
def nodo2str(raiz):
      assert type(raiz)==Nodo or raiz==None
      global L
      s=" "
      #llamar a una funcion auxiliar que llena la lista L con los elementos de "raiz"
      aux_str(raiz)
      #luego se devuelve un string de la lista L
      return s.join(L)
      
