#mcd: int int -> int
#retorna el maximo comun divisor entre dos numeros
#ej: mcd(2,0)=2
def mcd(a,b):
      if b==0:
            return a
      else:
            q=a/b
            r=a%b
            return mcd(b,r)
assert mcd(12,6)==6
assert mcd(2366,273)==91
def coprimos(a,b):
      if mcd(max(a,b),min(a,b))==1:
            return True
      else:
            return False
assert coprimos(9,4)==True
assert coprimos(9,3)==False
