from Conjunto import *
print "ingrese Conjunto A (o . para terminar)"
s=""
L=[]
while(s!="."):
      s=raw_input("elemento?")
      L.append(s)
L.remove(".")
A=Conjunto(L)
print "A=",A, "cardinal=",cardinal(A)
print "ingrese Conjunto B (o . para terminar)"
s=""
L=[]
while(s!="."):
      s=raw_input("elemento?")
      L.append(s)
L.remove(".")
B=Conjunto(L)
print "B=",B, "cardinal=",cardinal(B)
print "\n"
print "A union B =",union(A,B),", cardinal=",cardinal(union(A,B))
print "A interseccion B =",inter(A,B),", cardinal=",cardinal(inter(A,B))
print "A - B =",resta(A,B),", cardinal=",cardinal(resta(A,B))
print "B - A =",resta(B,A),", cardinal=",cardinal(resta(B,A))
print "A ^ B =",restaSimetrica(A,B),", cardinal=",cardinal(restaSimetrica(A,B))
if igual(A,B):
      print "A = B? si"
else:
      print "A = B? no"
if sub(A,B):
      print "A subconjunto de B? si"
else:
      print "A subconjunto de B? no"
if superC(A,B):
      print "A superconjunto de B? si"
else:
      print "A superconjunto de B? no"
