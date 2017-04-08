class Fraccion:
      def __init__(self,x=0,y=1):
            if type(x)==str:
                  i=x.find("/")
                  m=mcd(max(int(x[0:i]),int(x[i+1:])),min(int(x[0:i]),int(x[i+1:])))
                  self.numerador=int(x[0:i])/m
                  self.denominador=int(x[i+1:])/m                 
            else:
                  m=mcd(max(x,y),min(x,y))
                  self.numerador=x/m
                  self.denominador=y/m
            assert self.denominador!=0
      def __repr__(self):
            return str(self.numerador)+"/"+str(self.denominador)
      def __add__(self,x):
            return Fraccion(((self.numerador*x.denominador)+(self.denominador*x.numerador)),(self.denominador*x.denominador))
      def __str__(self):
            return str(self.numerador)+"/"+str(self.denominador)
      def __sub__(self,x):
            return self+Fraccion(-1*x.numerador,x.denominador)
      def __mul__(self,x):
            return Fraccion((self.numerador*x.numerador),(self.denominador*x.denominador))
      def __div__(self,x):
            return self*Fraccion(x.denominador,x.numerador)
      def __eq__(self,x):
            return self.denominador*x.numerador==self.numerador*x.denominador
      def simplificar(self):
            m=mcd(max(self.numerador,self.denominador),min(self.numerador,self.denominador))
            return Fraccion(self.numerador/m,self.denominador/m)
def mcd(a,b):
      if b==0:
            return a
      else:
            return mcd(b,a%b)
f1=Fraccion(1,2)
f2=Fraccion(3,4)
assert f1+f2==Fraccion(5,4)
assert f1*f2==Fraccion(3,8)
assert f1/f2==Fraccion(2,3)
assert f1-f2==Fraccion(-1,4)
