import math
#valido: int int -> bool
#devuelve True si un número está correctamente expresado en una base (entre 2 y 10)
#ej:valido(3,102) devuelve True y valido(2,102) devuelve False
def valido(base,numero):
      assert type(base)==int 
      assert type(numero)==int
      if 10<base or base<2:
            return False
      if numero<base:
            return True
      else:
            potencia=10**int(math.floor(math.log10(numero)))
            testing=numero/potencia
            if(testing>=base):
                  return False
            else:
                  return valido(base,numero-testing*potencia)
assert valido(2,213)== False
assert valido(3,3334)==False
assert valido(4,33333)==True
assert valido(2,102)==False
assert valido(1,0)==False
#decimal: int int -> int
#convierte a decimal un n° expresado en una base (entre 2 y 10)
#ej: decimal(8,215)=141. decimal(2,10001101)=141
def decimal(base,numero):
      if(numero<10):
            return numero
      else:
            potencia=int(math.floor(math.log10(numero)))
            testing=numero/10**potencia
            contador=base**potencia*testing+decimal(base,numero-testing*10**potencia)
      return contador
assert decimal(8,215)==141
assert decimal(2,10001101)==141
#numero: int int -> int
#convierte un número decimal a otra base (entre 2 y 10)
#ej: numero(2,141)=10001101, numero(8,141)=215
def numero(base,decimal):
      if decimal/base==0:
            return decimal%base
      else:
            resto=decimal%base
            contador=resto+10*numero(base,decimal/base)
      return contador
assert numero(2,141)==10001101
assert numero(8,141)==215
#convertir: None -> None
#convierte un numero de una base a otra
#ej: 215 en base 8 se convierte en 10001101 en base 2
def convertir():
      print "Convertir nº desde base1 a base2"
      base1=input("base1 ?")
      if base1!=0:
            n=input("nº ?")
            base2=input("base2 ?")
            if(valido(base1,n) and base2<=10 and base2>=2):
                  dec=decimal(base1,n)
                  num=numero(base2,dec)
                  print "nº= ",num
            else:
                  print "No es un numero valido"
            convertir()
      else:
            return
convertir()
