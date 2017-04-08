Python 2.7.10 (v2.7.10:15c95b7d81dc, May 23 2015, 09:33:12) 
[GCC 4.2.1 (Apple Inc. build 5666) (dot 3)] on darwin
Type "copyright", "credits" or "license()" for more information.
>>> WARNING: The version of Tcl/Tk (8.5.9) in use may be unstable.
Visit http://www.python.org/download/mac/tcltk/ for current information.

>>> 3+5
8
>>> 3+2*5
13
>>> (3+2)*5
25
>>> 2**3
8
>>> 4**0.5
2.0
>>> 10%3
1
>>> 'abra'+'cadabra'
'abracadabra'
>>> 'ja'*3
'jajaja'
>>> 'jajaja'
'jajaja'
>>> 1/2
0
>>> 1.0/2.0
0.5
>>> 1/2.0
0.5
>>> 1.0/2
0.5
>>> 'En el curso hay ' + str(100)+' alumnos'
'En el curso hay 100 alumnos'
>>> '100'+'1'
'1001'
>>> int('100')+1
101
>>> a=8
>>> b=12
>>> a
8
>>> a+b
20
>>> c=a+2*b
>>> c
32
>>> a=10
>>> a+b
22
>>> c
32
>>> a=8
>>> b=12
>>> c=a*b
>>> ancho=8
>>> largo=12
>>> area=ancho*largo
>>> area
96
>>> dia= 13
>>> mes='agosto'
>>> 'Hoy es '+dia+' de ' + mes

Traceback (most recent call last):
  File "<pyshell#35>", line 1, in <module>
    'Hoy es '+dia+' de ' + mes
TypeError: cannot concatenate 'str' and 'int' objects
>>> dia= 13
>>> mes='agosto'
>>> 'hoy es '+ str(dia)+' de '+ mes
'hoy es 13 de agosto'
>>> numero=15
>>> antecesor=(numero-1))
SyntaxError: invalid syntax
>>> lado1=15
>>> area=lado1*lado2

Traceback (most recent call last):
  File "<pyshell#42>", line 1, in <module>
    area=lado1*lado2
NameError: name 'lado2' is not defined
>>> dia=13
>>> mes='agosto'
>>> 'hoy es '+dia+' de '+mes

Traceback (most recent call last):
  File "<pyshell#45>", line 1, in <module>
    'hoy es '+dia+' de '+mes
TypeError: cannot concatenate 'str' and 'int' objects
>>> nombre='Juan Soto'
>>> int(nombre)

Traceback (most recent call last):
  File "<pyshell#47>", line 1, in <module>
    int(nombre)
ValueError: invalid literal for int() with base 10: 'Juan Soto'
>>> x=3
>>> x
3
>>> x=3
>>> 	x
	
  File "<pyshell#51>", line 1
    x
    ^
IndentationError: unexpected indent
>>> numero=15
>>> doble=3*numero
>>> doble
45
>>> 
