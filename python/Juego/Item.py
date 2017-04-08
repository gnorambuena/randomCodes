#Campos
#name: str
#description: str
#tipo: str
class Item:
      #Constructor
      def __init__(self,name,description,tipo):
            self.name=name
            self.description=description
            self.tipo=tipo
      #__str__: None -> str
      #entrega el string con el nombre del item
      def __str__(self):
            return self.name
      #__repr__: None -> str
      #entrega la representacion en un string para el uso en consola
      def __repr__(self):
            return self.name
      #getName: None -> str
      #entrega el nombre del item
      def getName(self):
            return self.name
      #getDescription: None -> str
      #retorna la descripcion del item
      def getDescription(self):
            return self.description
      #isValidType: None -> Bool
      #entrega si es un valor valido (weapon o item)
      def isValidType(self):
            if self.tipo=="weapon" or self.tipo=="item":
                  return True
            else:
                  return False
