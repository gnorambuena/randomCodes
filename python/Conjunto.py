#Campos
# L: list
class Conjunto:
      def __init__(self,elements=[]):
            #inicializacion de campos
            self.L=elements
            return
      
      #__add__: Conjunto -> Conjunto
      #devuelve un nuevo conjunto uniendo los dos primeros
      def __add__(self,x):
            L=list(self.L)
            for item in x.L:
                  if item not in self.L:
                        L.append(item)
            return Conjunto(L)
      
      #__inter__: Conjunto -> Conjunto
      #devuelve la interseccion con el conjunto x
      def __inter__(self,x):
            L=list(self.L)
            for item in self.L:
                  if item not in x.L:
                        L.remove(item)
            return Conjunto(L)
      
      #__sub__: Conjunto -> Conjunto
      #devuelve un Conjunto que no contiene los elementos de x
      def __sub__(self,x):
            L=list(self.L)
            for item in x.L:
                  if item in self.L:
                        L.remove(item)
            return Conjunto(L)
      
     #__eq__: Conjunto -> Bool
     #devuelve True si ambos Conjunto son iguales 
      def __eq__(self,x):
            if len(x.L)!=len(self.L):
                  return False
            for item in x.L:
                  if item not in self.L:
                        return False
            return True
      
     #__subc__: Conjunto -> Bool
     # devuelve true si el conjunto es subconjunto de x
      def __subc__(self,x):
            for item in self.L:
                  if item not in x.L:
                        return False
            return True
      
     #__card__: None -> int
     #entrega la cardinalidad de un Conjunto 
      def __card__(self):
            return len(self.L)
      
      #__pert__: any -> Bool
      #devuelve true si x pertenece al Conjunto
      def __pert__(self,x):
            if x in self.L:
                  return True
            return False
      
      #__esCon__: None -> Bool
      #devuelve True si es un conjunto valido
      def __esCon__(self):
            for item in self.L:
                  if self.L.count(item)>1:
                        return False
            return True
      
     #__super__: Conjunto -> Bool
     # devuelve true si el conjunto es superconjunto de x
      def __super__(self,x):
            return x.__subc__(self)
      
      #__str__: None -> String
      #entrega la representacion en string del Conjunto
      def __str__(self):
            s="{"
            for item in self.L:
                  s+=item+","
            if len(s)>1:
                  s=s[:-1]
            s+="}"
            return s
      
      #__xor__: Conjunto -> Conjunto
      #realiza la operacion de resta simetrica entre los dos conjuntos
      def __xor__(self,x):
            L=list(self.L)
            for item in x.L:
                  if item in self.L:
                        L.remove(item)
                  else:
                        L.append(item)
            return Conjunto(L)
      
      #__repr__: None -> String
      #entrega la representacion en string del Conjunto (Para ser llamado en el Shell)
      def __repr__(self):
            s="{"
            for item in self.L:
                  s+=item+","
            if len(s)>1:
                  s=s[:-1]
            s+="}"
            return s
A=Conjunto(["a","b","c","f"])
B=Conjunto(["b","c","d"])

#esConjunto: any -> Bool
#retorna un bool dependiendo si es un Conjunto valido
#ej: esConjunto(Conjunto(["a","b","c","f"]))->True
def esConjunto(x):
      return isinstance(x,Conjunto) and x.__esCon__()
assert  esConjunto(Conjunto(["a","b","c","f"]))==True

#union: conjunto conjunto -> conjunto
#entrega la union de dos conjuntos
#ej:union(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))->Conjunto(['a', 'b', 'c', 'f', 'd'])
def union(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x+y
assert union(A,B)==Conjunto(["a","b","c","f","d"])

#inter: conjunto conjunto -> conjunto
#entrga la interseccion de dos conjuntos
#ej:inter(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))-> Conjunto(["b","c"])
def inter(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x.__inter__(y)
assert inter(A,B)==Conjunto(["b","c"])

#resta: conjunto conjunto -> conjunto
#entrega la resta de dos conjuntos
#ej:resta(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))->Conjunto(["a","f"])
def resta(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x-y
assert resta(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))==Conjunto(["a","f"])
A=Conjunto(["a","b","c","f"])
B=Conjunto(["b","c","d"])

#restaSimetrica: Conjunto Conjunto->Conjunto
#retorna la resta simetrica de los dos conjuntos
#ej: restaSimetrica(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))->Conjunto(["a","f","d"])
def restaSimetrica(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x^y
assert restaSimetrica(A,B)==Conjunto(["a","f","d"])

#igual: Conjunto Conjunto -> Bool
#compara si dos conjuntos son iguales
#ej:igual(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))-> False
def igual(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x==y
assert igual(A,B)==False

#sub: Conjunto Conjunto -> Bool
#dice si x es subconjunto de y
#ej:sub(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))->False
def sub(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x.__subc__(y)
assert sub(A,B)==False

#sub: Conjunto Conjunto -> Bool
#dice si x es superconjunto de y
#ej:superC(Conjunto(["a","b","c","f"]),Conjunto(["b","c","d"]))->False
def superC(x,y):
      assert esConjunto(x) and esConjunto(y)
      return x.__super__(y)
assert superC(A,B)==False

#string: Conjunto -> string
#convierte un conjunto en string
#ej:string(Conjunto(["a","b","c","f"]))->'{a,b,c,f}'
def string(x):
      assert esConjunto(x)
      return str(x)
assert string(A)=='{a,b,c,f}'

#cardinal: Conjunto -> int
#entrega la cardinalidad del conjunto
#ej:cardinal(Conjunto(["a","b","c","f"]))->4
def cardinal(x):
      assert esConjunto(x)
      return x.__card__()
assert cardinal(A)==4

#string: any Conjunto -> bool
#convierte un conjunto en string
#ej:pertenece("a",Conjunto(["a","b","c","f"]))->True
def pertenece(a,x):
      assert esConjunto(x) and type(a)==int or type(a)==str or type(a)==float
      return x.__pert__(a)
assert pertenece("a",A)==True
