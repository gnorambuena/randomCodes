# Campos
# commandWord: str
# secondWord: str

class Command:

    # Constructor
    def __init__(self, firstWord, secondWord):
        self.commandWord = firstWord
        self.secondWord = secondWord

    # getCommandWord: None -> str
    # devuelve el texto del comando principal
    def getCommandWord(self):
        return self.commandWord

    # getCommandWord: None -> str
    # devuelve el texto del comando secundario
    def getSecondWord(self):
        return self.secondWord

    # isUnknown: None -> bool
    # devuelve True si no hay comando principal
    def isUnknown(self):
        return self.commandWord == None

    # isUnknown: None -> bool
    # devuelve True si existe comando secundario
    def hasSecondWord(self):
        return self.secondWord != None

