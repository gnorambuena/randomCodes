from AB import *
import estructura
estructura.crear("registro","nombre fono")

#agregar: str int AB -> AB
#agrega registro con nombre y fono a agenda
#ej: agregar("b",3,agenda)->
#    AB(registro("c",1), \
#    AB(registro("a",2),None,AB(registro("b",3),None,None)) \
#    AB(registro("d",4),None,None))
def esArbol(A):
      return A==None or type(A)==AB

def agregar(nombre,fono,agenda):
      assert esArbol(agenda)
      if agenda==None: 
            return AB(registro(nombre,fono),None,None)
      reg=agenda.valor
      if reg.nombre==nombre: return agenda
      if reg.nombre>nombre:
            return AB(reg,agregar(nombre,fono,agenda.izq),agenda.der)
      return AB(reg,agenda.izq,agregar(nombre,fono,agenda.der))
#borrar: str AB -> AB
#borra de agenda registro con nombre (si existe)
#ej: borrar("c",agenda)->
#    AB(registro("a",2),None,AB(registro("d",4),None,None))

def borrar(nombre,agenda):
      assert esArbol(agenda)
      if agenda==None: return None
      reg=agenda.valor
      if reg.nombre>nombre:
            return AB(reg,borrar(nombre,agenda.izq),agenda.der)
      if reg.nombre<nombre:
            return Ab(reg,agenda.izq,borrar(nombre,agenda.der))
        #reg.nombre==nombre
      if agenda.izq==None: return agenda.der
      if agenda.der==None: return agenda.izq
     #”subir”(promover) mayor del arbol izquierdo
      reg=mayorABB(agenda.izq)
      return AB(reg,borrar(reg.nombre,agenda.izq),agenda.der)

#buscar: str AB -> int
#buscar nombre en agenda y devolver fono 
#(None si no esta)
#ej: buscar("c",agenda)->1

def buscar(nombre,agenda):
      assert esArbol(agenda)
      if agenda==None: return None
      reg=agenda.valor
      if reg.nombre==nombre: return reg.fono
      if reg.nombre>nombre:
            return buscar(nombre,agenda.izq)
      else:
            return buscar(nombre,agenda.der)
#mayorABB: AB -> any
#mayor valor de ABB A
#ej: mayorABB(abb)->"C“

def mayorABB(A):
      assert esArbol(A)
      if A==None: return None
      if A.der==None: return A.valor
      return mayorABB(A.der)
#cambiar: str int AB -> AB
#cambia fono de un nombre en la agenda
#ej:cambiar("c",5,agenda)->agenda(registro("c",5),None,None)
def cambiar(nombre,fono,agenda):
      assert esArbol(agenda)
      if buscar(nombre,agenda)==None: return agenda
      return agregar(nombre,fono,borrar(nombre,agenda))
agenda=AB(registro("c",1),None,None)
agenda=agregar("b",3,agenda)
agenda=agregar("a",4,agenda)
agenda=cambiar("c",5,agenda)
print agenda
