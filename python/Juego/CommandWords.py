# Variable global de comandos validos

validCommands = ["go", "quit", "help", "equip","throw","take","look","inventory","attack","equip","health"]

class CommandWords:

    # Constructor
    def __init__(self):
        pass

    # isCommand: str -> bool
    # devuelve True si aString es un comando valido
    def isCommand(self, aString):
        return aString in validCommands

    # showAll: None -> None
    # muestra en pantalla todos los comandos validos
    def showAll(self):
        for c in validCommands:
            print c

	
