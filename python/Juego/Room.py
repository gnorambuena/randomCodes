# Campos
# short: str
# description: str
# exits: dict
#Litems: list
#enemy: None
class Room:
    # Constructor
    def __init__(self, short, description):
        self.short = short
        self.description = description
        self.exits = {}
        self.Litems=[]
        self.enemy= None
    #addItem: Item -> None
    #agrega un item al room
    def addItem(self,item):
        self.Litems.append(item)
    #removeItem: Item -> None
    #quita un Item del room
    def removeItem(self,item):
        self.Litems.remove(item)
    #getItems: None -> list
    #retorna una lista con los items en el room
    def getItems(self):
        return self.Litems
    #setEnemy: Character -> None
    #pone un enemigo en el room
    def setEnemy(self,enemy):
        self.enemy=enemy
    #getEnemy: None -> Character
    #retorna el enemigo que esta en el room
    def getEnemy(self):
        return self.enemy
    #hasEnemy: None -> Bool
    #retorna si existe un enemigo en el room
    def hasEnemy(self):
        return self.enemy!=None
    # setExit: str Room -> None
    # efecto: agrega direction al diccionario de salidas
    # con salida en direccion a neighbor
    def setExit(self, direction, neighbor):
        self.exits[direction] = neighbor

    # getShortDescription: None -> str
    # devuelve la descripcion corta del lugar
    def getShortDescription(self):
        return self.short

    # getShortDescription: None -> str
    # devuelve la descripcion larga del lugar
    def getLongDescription(self):
        return "You are " + self.description + "\n" + self.getExitString()

    # getExitString: None -> str
    # devuelve un String con las distintas salidas que tiene el lugar
    def getExitString(self):
        returnString = "Exits:"
        for pair in self.exits.items():
            returnString += "   " + pair[0] + ": " + pair[1].getShortDescription()
        return returnString 

    # getExit: str -> Room
    # devuelve el objeto asociado al lugar indicado por direction
    # si direction no existe, devuelve None
    def getExit(self, direction):
        if direction not in self.exits:
            return None
        else:
            return self.exits[direction]
