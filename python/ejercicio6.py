from coprimos import coprimos
#main: int, int -> None
#esta funcion entrega los coprimos del 1 al 20
#ej: main(2,20)
def main(a,b):
      if(coprimos(a,b)):
            print a,b
            return main(a,b-1)
      else:
            if(a==b):
                  if(a==20):
                        return
                  else:
                        main(a+1,20)
            else:
                  return main(a,b-1)
      
main(2,20)
