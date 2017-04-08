import estructura
import fecha
estructura.crear("Persona","Nombre Nacimiento Sexo")
G=Persona("Gabriel",fecha.Fecha(2,11,1995),"H")
#esPersona(P): Persona(string fecha string)->bool
#entrega si es una persona valida
#ej:esPersona(Persona("Gabriel",Fecha(2,11,1995),"H")=->True
def esPersona(P):
    return type(P)==Persona
assert esPersona(Persona("Gabriel",fecha.Fecha(2,11,1995),"H"))
def fnacimiento(P):
    assert esPersona(P)
    return P.Nacimiento
#fedad: Fecha Persona -> int
#entrega la edad en anos de una persona
#ej: fedad(Fecha(28,10,2015),Persona("Gabriel",Fecha(2,11,1995),"H"))-> 19
def fedad(f,P):
    assert fecha.esFecha(f) and esPersona(P)
    return fecha.dif_anos(f,fnacimiento(P))
assert fedad(fecha.Fecha(1,11,2015),G)==19
#fnombre: Persona-> String
#entrega el nombre de una persona
#ej:fnombre(Persona("Gabriel",Fecha(2,11,1995),"H"))=="Gabriel"
def fnombre(P):
    assert esPersona(P)
    return P.Nombre
assert fnombre(Persona("Gabriel",fecha.Fecha(2,11,1995),"H"))=="Gabriel"
#fsexo: Persona -> String
#entrega el sexo de una persona
#ej:fsexo(Persona("Gabriel",Fecha(2,11,1995),"H"))=="H"
def fsexo(P):
    assert esPersona(P)
    return P.Sexo
assert fsexo(Persona("Gabriel",fecha.Fecha(2,11,1995),"H"))=="H"
#frase: Persona -> string
#entrega el string “S:DD/MM/AAAA:nombre” en que S es H o M
#ej;frase(Persona("Gabriel",Fecha(2,11,1995),"H"))=="H:2/11/1995:Gabriel"
def frase(P):
    assert esPersona(P)
    s1=str(fsexo(P))
    nac=fnacimiento(P)
    s2=fecha.formato(nac);
    s3=str(fnombre(P))
    return s1+":"+s2+":"+s3
assert frase(Persona("Gabriel",fecha.Fecha(2,11,1995),"H"))=="H:2/11/1995:Gabriel"
