from lista import *
#is_value: int lista-> bool
#entrega un boolean dependiendo si un valor esta en una lista
#ej: is_value(5,lista(5,lista(4,None)))==True
def is_value(value,l):
      if cabeza(l)==value:
            return True
      elif cola(l)!=None:
            return is_value(value,cola(l))
      else:
            return False
assert is_value(5,lista(5,lista(4,None)))
assert not is_value(1,lista(5,lista(4,None)))
