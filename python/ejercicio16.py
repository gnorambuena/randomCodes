import estructura
estructura.mutable("registro","nombre fono")
agenda=[registro("a",2),registro("c",1),registro("d",4)]
#buscar: str list -> int
#buscar nombre en agenda y devolver fono
#(None si no esta)
#ej: buscar("c",agenda)->1
def buscar(nombre,agenda):
      for i in range(len(agenda)):
            if agenda[i].nombre==nombre:
                  return i
      return None
assert buscar("c",agenda)==1
