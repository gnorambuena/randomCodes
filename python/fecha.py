import estructura
# -*- coding: cp1252 -*-
estructura.crear("Fecha","dia mes ano")
estructura.crear("Lista","valor siguiente")
#esLista(L): Lista(any)->bool
#dice si L es una Lista
#ej: esLista(Lista(4,None))==True
def esLista(L):
    if type(L)==Lista or L==None:
        return True
    return False
assert esLista(Lista(4,None))
#cabeza:Lista(any)->any
#entrega el valor de una lista
#ej:cabeza(Lista(4,None))==4
def cabeza(L):
    assert esLista(L)
    return L.valor
assert cabeza(Lista(4,None))==4
#cola:Lista(any)->Lista(any)
#entrega el siguiente valor de una lsita
#ej:cola(Lista(4,None))
def cola(L):
    assert esLista(L)
    return L.siguiente
assert cola(Lista(4,None))==None
#agregar: int -> fecha(int int int)
#recibe un entero dmmaaaa o ddmmaaaa y entrega una fecha
#ej: agregar(10022015)-> Fecha(10,02,2015)
def agregar(f):
    ano=f%10000
    f=f/10000
    mes=f%100
    f=f/100
    return Fecha(f,mes,ano)
assert agregar(10022015)==Fecha(10,02,2015)
#aNum: Fecha(int int int)-> int
#recibe una fecha y entrega un int ddmmaaaa o dmmaaaa
#ej: aNum(Fecha(10,02,2015))-> 10022015
def aNum(f):
    ano=f.ano
    mes=f.mes*10000
    dia=f.dia*1000000
    return ano+mes+dia
assert aNum(Fecha(10,02,2015))==10022015
#esBisiesto:Fecha(int int int)-> bool
#recibe una fecha y entrega un bool si es un año bisiesto
#ej:esBisiesto(Fecha(01,01,2016)) -> True
def esBisiesto(f):
    ano=f.ano
    if ano%4==0:
        if ano%100==0:
            if ano%400==0:
                return True
            return False
        return True
    return False
assert esBisiesto(Fecha(01,01,2016))
assert not esBisiesto(Fecha(01,01,2014))
#esFecha(f): Fecha(int int int)->bool
#recibe una fecha y entrega un bool si es una fecha correcta
#ej:esFecha(Fecha(10,02,2015))-> True
def esFecha(f):
    if (type(f)!=Fecha):
        return False
    if f.dia<1 or f.mes<1 or f.ano<1:
        return False
    if f.mes==2:
        if f.dia<=29 and esBisiesto(f):
            return True
        if f.dia<=28:
            return True
        return False
    if f.mes==4 or f.mes==9 or f.mes==11 or f.mes==6:
        if f.dia<=30:
            return True
        return False
    if f.dia<=31:
        return True
    return False
assert esFecha(Fecha(10,2,2015))
assert not esFecha(Fecha(-1,1,1))
assert not esFecha(Fecha(30,2,2000))
assert esFecha(Fecha(29,2,2000))
assert not esFecha(Fecha(29,2,1999))
assert not esFecha(Fecha(31,4,2000))
#diaSiguiente: Fecha(int int int)-> Fecha(int int int)
#recibe una fecha y entrega el dia siguiente
#ej:diaSiguiente(Fecha(29,2,2016))==Fecha(1,3,2016)
def diaSiguiente(f):
    assert esFecha(f)
    if f.mes==2:
        if esBisiesto(f):
            if f.dia==29:
                return Fecha(1,3,f.ano)
        if f.dia==28:
            return Fecha(1,3,f.ano)
        else:
            return Fecha(f.dia+1,2,f.ano)
    if f.mes==4 or f.mes==9 or f.mes==11 or f.mes==6:
        if f.dia==30:
            return Fecha(1,f.mes+1,f.ano)
        else:
            return Fecha(f.dia+1,f.mes+1,f.ano)
    if f.mes==12 and f.dia==31:
        return Fecha(1,1,f.ano+1)
    if f.dia==31:
        return Fecha(1,f.mes+1,f.ano)
    return Fecha(f.dia+1,f.mes,f.ano)
assert diaSiguiente(Fecha(29,2,2016))==Fecha(1,3,2016)
assert diaSiguiente(Fecha(31,12,2015))==Fecha(1,1,2016)
assert diaSiguiente(Fecha(30,4,2015))==Fecha(1,5,2015)
#formato: Fecha(int int int)-> string
#recibe una fecha y la entrega en formato DD/MM/AAAA
#ej: formato(Fecha(10,02,2015))=="10/02/2015"
def formato(f):
    assert esFecha(f)
    if f.mes<10:
        return  str(f.dia)+"/"+"0"+str(f.mes)+"/"+str(f.ano)
    return str(f.dia)+"/"+str(f.mes)+"/"+str(f.ano)
assert formato(Fecha(10,02,2015))=="10/02/2015"
#comp: Fecha(int int int) Fecha(int int int) -> int
#compara dos fechas (devolviendo -1 si es menor f1, 0 si son iguales o 1 si f1 es mayor)
#ej:comp(Fecha(10,02,2015),Fecha(2,11,2015))==-1
def comp(f1,f2):
    assert esFecha(f1) and esFecha(f2)
    if f1.ano==f2.ano:
        if f1.mes==f2.mes:
            if f1.dia==f2.dia:
                return 0
            if f1.dia>f2.dia:
                return 1
            else:
                return -1
        if f1.mes>f2.mes:
            return 1
        else:
            return -1
    if f1.ano>f2.ano:
            return 1
    return -1
assert comp(Fecha(10,02,2015),Fecha(2,11,2015))==-1
assert comp(Fecha(10,02,2015),Fecha(10,02,2015))==0
assert comp(Fecha(10,02,2015),Fecha(9,11,2014))==1
#dif_anos: Fecha(int int int) Fecha(int int int) -> int
#calcula la diferencia entre dos fechas en anos
#ej:dif_anos(Fecha(2,11,2015),Fecha(2,11,1995))==20
def dif_anos(f1,f2):
    assert esFecha(f1) and esFecha(f2)
    c=comp(f1,f2);
    if c==0:
        return 0
    if c==1:
        anos=f1.ano-f2.ano
        if f1.mes<f2.mes:
            return anos-1
        if f1.mes==f2.mes and f1.dia<f2.dia:
            return anos-1
        return anos
    else:
        return dif_anos(f2,f1)
assert dif_anos(Fecha(2,11,2015),Fecha(2,11,1995))==20
assert dif_anos(Fecha(28,10,2015),Fecha(2,11,1995))==19
assert dif_anos(Fecha(1,11,2015),Fecha(2,11,1995))==19
