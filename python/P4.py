from Lpersonas import *
from fecha import *
LP1=CrearLista()
LP2=CrearLista()
f=input("Fecha de hoy: ")
f=agregar(f)
LCumple=fechaPersona(f,LP1)
Ledad=Ledades(LCumple,f)
print "Personas de cumpleanos: ",LCumple
print "Edades:",Ledad
santo=raw_input("Ingrese la persona de santo mañana: ")
Lsanto=strEnLista(santo,LP2)
print "Personas de santo: ",Lsanto
print "Interseccion: ",interseccion(Lnombres(LP1),LP2)
print "union: ",union(LP1,LP2)
