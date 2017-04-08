#pregunta3
# -*- coding: cp1252 -*-
from persona import *
from fecha import *
#enLista: Lista(any) any -> bool
#entrega un bool si un valor esta en la lista
#ej:enLista(Lista(4,None),4)==True
def enLista(L,x):
    assert esLista(L)
    if L==None:
        return False
    if L.valor==x:
        return True
    return enLista(L.siguiente,x)
assert enLista(Lista(4,None),4)==True
#nombrePersona: str lista(persona)->persona
#recibe un nombre y entrega la persona
#
def nombrePersona(nombre,Lpersona):
    assert esLista(Lpersona)or Lpersona==None
    p=cabeza.Lpersona
    if Lpersona==None: return None
    if nombre==p.nombre:
        return persona 
    return nombrePersona(nombre,cola(Lpersona))


#fechaPersona: Fecha lista(persona)->lista(persona)
#recibe una fecha y entrega lista de personas de cumpleaños
#
def fechaPersona(fecha,Lpersona):
    assert esLista(Lpersona)
    if Lpersona==None: return None
    if fnacimiento(cabeza(Lpersona)).dia==fecha.dia and fnacimiento(cabeza(Lpersona)).mes==fecha.mes:
        return Lista(cabeza(Lpersona),fechaPersona(fecha,cola(Lpersona)))
    return fechaPersona(fecha,cola(Lpersona))


#strEnLista: str lista->lista
#recibe un str y entrega la lista de personas que contienen el str en su nombre
#
def strEnLista(a,L):
    assert esLista(L) and type(a)==str
    if L==None: return None
    P=cabeza(L)
    if a in fnombre(P):
        return Lista(cabeza(L),strEnLista(a,cola(L)))
    return strEnLista(a,cola(L))


#Ledades:lista(personas)->lista(edades)
#entrega una lista con las edades
#
def Ledades(Lpersonas,fecha):
    assert esLista(Lpersonas)
    if Lpersonas==None: return None
    p=cabeza(Lpersonas)
    edad=fedad(fecha,p)
    return Lista(edad,Ledades(cola(Lpersonas),fecha))

#Lnombre: lista(personas)->lista
#entrega una lista con los nombres
#
def Lnombres(Lpersonas):
    assert esLista(Lpersonas)
    if Lpersonas==None: return None
    p=cabeza(Lpersonas)
    nombre=fnombre(p)
    return Lista(nombre, Lnombres(cola(Lpersonas)))

#Lsexo: str->lista
#recibe una letra y entrega la lista de personas
#
def Lsexo(s,Lpersonas):
    assert esLista(Lpersonas)
    if Lpersonas==None: return None
    p=cabeza(Lpersonas)
    if s==fsexo(p):
        return lista(p,Lsexo(s,cola(Lpersonas)))
    return Lsexo(s,cola(Lpersonas))
#interseccion: lista(nombre) lista(personas)-> lista
#recibir una lista de nombres y entregar una lista con las personas que estan en ambas listas
#
def interseccion(Lnombre,Lpersonas):
    assert esLista(Lnombre) and esLista(Lpersonas)
    if Lnombre==None or Lpersonas==None: return None
    if enLista(Lnombre,fnombre(cabeza(Lpersonas))):
        return Lista(Lpersonas.valor,interseccion(Lnombre,cola(Lpersonas)))
    return interseccion(Lnombre,cola(Lpersonas))
#juntar: Lista(any) Lista(any) -> Lista(any)
#junta dos listas
#ej:juntar(Lista(5,none),Lista(4,none))==Lista(5,Lista(4,None))
def juntar(L1,L2):
    assert esLista(L1) and esLista(L2)
    if L1==None and L2!=None:
        return L2
    if L2==None:
        return None
    return Lista(cabeza(L1),juntar(cola(L1),L2))
#borrar: Lista(any) any -> Lista(any)
#borra elemento de una lista
#ej:borrar(Lista(5,Lista(4,None)),5)->Lista(4,None)
def borrar(L,x):
    assert esLista(L)
    if L==None:
        return L
    if cabeza(L)==x:
        return L.siguiente
    return Lista(cabeza(L),borrar(cola(L),x))
assert borrar(Lista(5,Lista(4,Lista(6,None))),6)==Lista(5,Lista(4,None))
#union: lista(nombres) lista(personas)->lista
#recibir otra lista de personas y entregar una lista con las personas que estan al menos en una lista
#
def union(L1,L2,inter=None,L=None):
    assert esLista(L1) and esLista(L2)
    if L==None:
        L=juntar(L1,L2)
        inter=interseccion(Lnombres(L1),L2)
    if inter==None:
        return L
    return union(L1,L2,cola(inter),borrar(L,cabeza(inter)))

    
#menor: Lista(int)->int
#entrega la menor edad de una lista
#ej:menor(Lista(3,Lista(2,None)))->2

def menor(L):
    if L==None:
        return 100000000
    return min(L.valor,menor(L.siguiente))
L=Lista(3,Lista(2,None))
assert menor(L)==2
#pMenor: lista(personas)->persona
#entrega la persona menor
#
def pMenor(Lpersonas,f=Fecha(1,1,1),P=None):
    assert esLista(Lpersonas)
    if Lpersonas==None: return P
    if comp(fnacimiento(cabeza(Lpersonas)),f)==1:
        return pMenor(cola(Lpersonas),fnacimiento(cabeza(Lpersonas)),cabeza(Lpersonas))
    return pMenor(cola(Lpersonas),f,P)
print pMenor(Lista(Persona("Isidora",Fecha(10,02,1996),"M"),Lista(Persona("Gabriel",Fecha(2,11,1995),"H"),None)))
assert pMenor(Lista(Persona("Isidora",Fecha(10,02,1996),"M"),Lista(Persona("Gabriel",Fecha(2,11,1995),"H"),None)))==Persona("Isidora",Fecha(10,02,1996),"M")
#CrearLista
#construir una lista
#ej: CrearLista()
#Sexo(H,M)?'H'
#Nombre?'Raimundo'
#fecha de nacimiento(dmmaaaa)?2931992
#Sexo(H,M)?'.'
#Fin de los datos
#lista(valor=Persona(Nombre='Raimundo', Nacimiento=2931992, Sexo='H'), siguiente=None)
def CrearLista():
    s=raw_input('Sexo(H,M) ?')
    if s=='.':
        print 'Fin de los datos'
        return 
    n=raw_input('Nombre?')
    f=input('fecha de nacimiento(dmmaaaa)?')
    return Lista(Persona(n,fecha.agregar(f),s),CrearLista())

    



    
    
    
    

