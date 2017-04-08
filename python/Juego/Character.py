#Campos
#name: str
#inventory: list
#HP: int
#maxHP: int
#weapon: Item
class Character:
      #constructor
      def __init__(self,name):
            self.name=name
            self.inventory=[]
            self.HP=100
            self.maxHP=100
            self.weapon=None
      #getHP: None -> int
      #entrega el HP del character
      def getHP(self):
            return self.HP
      #getName: None -> int
      #entrega el nombre del Character
      def getName(self):
            return self.name
      #setHp: int-> None
      #cambia el valor de HP por newHP
      def setHP(self,newHP):
            self.HP=newHP
      #addItem: Item -> None
      #agrega un item al inventario
      def addItem(self,item):
            self.inventory.append(item)
      #setWeapon: Item -> None
      #equipa un arma al Character
      def setWeapon(self,weapon):
            self.weapon=weapon
      #getmaxHP: None -> int
      #entrega el valor maximo para el HP del personaje
      def getmaxHP(self):
            return self.maxHP
      #removeItem: Item -> None
      #remueve un item del inventario
      def removeItem(self,item):
            self.inventory.remove(item)
      #getInventory: None -> list
      #retorna el inventario del Character
      def getInventory(self):
            return self.inventory
      #getWeapon: None -> Item
      #entrega el arma equipada del Character
      def getWeapon(self):
            return self.weapon
