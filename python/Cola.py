#Campos
#__largo: int
#__L: list(any
class Cola:
      #__init__: int -> none
      #constructor de la clase cola
      #crea una cola de largo m
      def __init__(self,m=1):
            self.__largo=m
            self.__L=[]
      #poner: any -> none
      #pone el x en la cola
      #si el largo de la cola es mayor que el largo maximo
      #tira ColaLlena como excepcion
      #debido a que no queda mas espacio
      def poner(self,x):
            if len(self.__L)<self.__largo:
                  self.__L.insert(len(self.__L),x)
                  return
            raise ColaLlena()
      #sacar: none -> any
      #se retorna el primer elemento de la cola
      #tambien se quita de la cola
      #si la cola tiene largo 0
      #tira excepcion ColaVacia
      def sacar(self):
            if len(self.__L)>0:
                  x=self.__L[0]
                  self.__L.remove(x)
                  return x
            raise ColaVacia()
      #__str__: none -> str
      #entrega un string de la cola,
      #para el uso en el programa
      #se quito los []
      def __str__(self):
            s=str(self.__L)
            s=s[1:-1]
            return s
      #__repr__:none -> str
      #representacion en consola
      #de la cola, especial para usarlo
      #como debug
      def __repr__(self):
            s=str(self.__L)
            s=s[1:-1]
            return s
      #__len__: none -> int
      #se retorna la cantidad de elementos en la cola
      def __len__(self):
            return len(self.__L)
#Sin campos
#Excepcion para una cola que esta llena
class ColaLlena(Exception):
      pass
#Sin campos
#Excepcion para una cola que esta vacia
class ColaVacia(Exception):
      pass
