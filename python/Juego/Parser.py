from CommandWords import CommandWords
from Command import Command

# Campos:
# commands: CommandWords

class Parser:

    # Constructor
    def __init__(self):
        self.commands = CommandWords()

    # getCommand: None -> Command
    # devuelve el comando ingresado por el usuario
    def getCommand(self):
        print ">",
        inputLine = raw_input()
        words = inputLine.split()
        words = words + [None, None]
        w1 = words[0]
        w2 = words[1]
        if self.commands.isCommand(w1):
            return Command(w1, w2)
        else:
            return Command(None, w2)

    # showCommands: None -> None
    # muestra en pantalla todos los comandos validos
    def showCommands(self):
        self.commands.showAll()
