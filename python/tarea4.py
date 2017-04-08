from Tkinter import *
import time
from Cola import *
global start,c1,c2
start=time.time()
c1=Cola(5)
c2=Cola(10)
print start
window=Tk()
def add1():
      end=time.time()
      tiempo=int(end-start)
      c1.poner(tiempo)
      Lb2.config(text=str(c1))
      Lb5.config(text=len(c1))
def add2():
      end=time.time()
      tiempo=int(end-start)
      c2.poner(tiempo)
      Lb3.config(text=str(c2))
      Lb6.config(text=len(c2))
def caja():
      if len(c1)!=0:
            cliente=c1.sacar()
            Lb2.config(text=str(c1))
            Lb5.config(text=len(c1))
      elif len(c2)!=0:
            cliente=c2.sacar()
            Lb3.config(text=str(c2))
            Lb6.config(text=len(c2))
      else:
            cliente=""
      s="Atendiendo \n al cliente "+str(cliente)
      Lb1.config(text=s)
      
f1=Frame(window)
f1.pack(side=LEFT)
f2=Frame(window)
f2.pack(side=LEFT)
f3=Frame(window)
f3.pack(side=RIGHT)
Lb1=Label(f2,text="Atendiendo \n al cliente")
Lb2=Label(f2)
Lb3=Label(f2)
Lb4=Label(f3,text="Largo de \n Cola de espera")
Lb5=Label(f3)
Lb6=Label(f3)
Bt1=Button(f1,text="Caja",command=caja)
Bt2=Button(f1,text="Cola 1",command=add1)
Bt3=Button(f1,text="Cola 2",command=add2)
Bt1.pack(side=TOP);Bt2.pack(side=TOP);Bt3.pack(side=BOTTOM);
Lb1.pack(side=TOP);Lb2.pack(side=TOP);Lb3.pack(side=BOTTOM);
Lb4.pack(side=TOP);Lb5.pack(side=TOP);Lb6.pack(side=BOTTOM);
window.mainloop()
