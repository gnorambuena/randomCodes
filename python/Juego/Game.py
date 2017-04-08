from Room import Room
from Parser import Parser
from Character import Character
from Item import Item
from Command import Command
# Campos
# parser: Parser
# currentRoom: Room

class Game:

    # Constructor:
    def __init__(self):
        self.createRooms()
        self.parser = Parser()
        self.character = None
    # createRooms: None -> None
    # crea todos los lugares en el juego, y
    # crea variable de instancia currentRoom
    # ademas asigna los items y enemigos en cada Room
    def createRooms(self):
        # creating rooms
        home = Room("Home", "inside your home, this is where you live \n go to the House of Inte-Gral")
        firstroad = Room("Village Road", "outside, in the main road of the village")
        magicianhouse = Room("Inte-Gral House", "in the house of the magician Inte-Gral \n you should go to the bethesda cave and take the sword")
        bethesda = Room("Bethesda Cave", "inside the bethesda Cave")
        secondroad = Room("Outside Road", "outside of your village, in the road")
        beauchef = Room("Beauchef City", "in Beauchef City, it's said near here is the Golden Sword")
        catacomb = Room("Beauchef 851 Catacombs", "underground the City, you see the famous Golden Sword")
        candymountain = Room("Candy Mountain", "in the candy mountain, yes a mountain made of candy")
        thirdroad = Room("Candy Road", "outside in the Candy Road")
        littlevillage = Room("Little Village", "in the main road of the Little Village, a village of dwarfs")
        floihouse=Room("Floi's Home","inside the house of Floi, a very brave dwarf,\n who fought several times in the past against the goblins")
        telcharhouse=Room("Telchar's Home","inside the house of Telchar, the greatest smith of the kingdom")
        ironvalley=Room("Iron Valley","in the Iron Valley, this is where the best smiths of the kingdom get \n their iron for making weapons")
        nomansdesert=Room("No man's Desert","lost in the gigantic desert, you hope to find a way out")
        countryside=Room("Countryside","in the beautiful Countryside of the kingdom")
        forest=Room("Southern Forest","surrounded by very large and old trees, you can hear strange noises in the distance")
        fourthroad=Room("Lake Road","in the Lake Road, if you follow the path you will reach the Mysterious Lake")
        lake=Room("Mysterious Lake","in the shore of the Lake, the Lake has red water and very few fishes to catch.\n The entrance to the Volcano is near.")
        volcanoentrance=Room("Chaiten Volcano Entrance"," in the Entrance of the Volcano, the end of your Quest is close")
        volcanotop=Room("Chaiten Volcano Top","in the top of the Volcano, you just have to throw the bracelet")

        #create the items
        potion=Item("potion","A simple potion","item")
        sword=Item("sword","An iron sword","weapon")
        shield=Item("helmet","A metal shield","item")
        bow=Item("bow","A bow made from wood","weapon")
        magicbracelet=Item("MagicBracelet","A magic bracelet, you have to throw it in Chaiten Volcano","item")
        goldensword=Item("GoldenSword","This sword is better than a normal one, it can defeat any dragon","weapon")

        #create enemies
        ogre=Character("ogre")
        goblin=Character("goblin")
        dragon=Character("DragonErre")
        #initialize enemies
        ogre.setHP(20)
        goblin.setHP(40)
        dragon.setHP(100)
        ogre.addItem(potion)
        goblin.addItem(potion)
        dragon.addItem(potion)
        #initialize room items
        home.addItem(potion)
        magicianhouse.addItem(magicbracelet)
        magicianhouse.addItem(potion)
        catacomb.addItem(goldensword)
        candymountain.addItem(bow)
        bethesda.addItem(sword)
        floihouse.addItem(bow)
        floihouse.addItem(potion)
        telcharhouse.addItem(potion)
        telcharhouse.addItem(shield)
        forest.addItem(potion)
        lake.addItem(potion)
        # initialise room exits
        home.setExit("south", firstroad)
        firstroad.setExit("south", secondroad)
        firstroad.setExit("west", bethesda)
        firstroad.setExit("east", magicianhouse)
        firstroad.setExit("north", home)
        bethesda.setExit("east", firstroad)
        magicianhouse.setExit("west", firstroad)
        secondroad.setExit("north", firstroad)
        secondroad.setExit("west",beauchef)
        secondroad.setExit("east",candymountain)
        beauchef.setExit("east",secondroad)
        beauchef.setExit("south",catacomb)
        catacomb.setExit("north",beauchef)
        candymountain.setExit("west",secondroad)
        candymountain.setExit("south",thirdroad)
        thirdroad.setExit("south",littlevillage)
        thirdroad.setExit("north",candymountain)
        littlevillage.setExit("north",thirdroad)
        littlevillage.setExit("east",floihouse)
        littlevillage.setExit("west",telcharhouse)
        littlevillage.setExit("south",ironvalley)
        floihouse.setExit("west",littlevillage)
        telcharhouse.setExit("east",littlevillage)
        ironvalley.setExit("north",littlevillage)
        ironvalley.setExit("east",nomansdesert)
        nomansdesert.setExit("west",ironvalley)
        nomansdesert.setExit("east",countryside)
        nomansdesert.setExit("south",fourthroad)
        countryside.setExit("west",nomansdesert)
        countryside.setExit("east",forest)
        forest.setExit("west",countryside)
        forest.setExit("south",volcanoentrance)
        volcanoentrance.setExit("north",forest)
        volcanoentrance.setExit("east",lake)
        volcanoentrance.setExit("south",volcanotop)
        lake.setExit("west",volcanoentrance)
        lake.setExit("north",fourthroad)
        fourthroad.setExit("south",lake)
        fourthroad.setExit("north",nomansdesert)
        volcanotop.setExit("north",volcanoentrance)
        
        #initialize room enemies
        secondroad.setEnemy(ogre)
        thirdroad.setEnemy(ogre)
        fourthroad.setEnemy(ogre)
        catacomb.setEnemy(goblin)
        countryside.setEnemy(goblin)
        nomansdesert.setEnemy(goblin)
        volcanoentrance.setEnemy(dragon)
        # start game in home
        self.currentRoom =home

    # play: None -> None
    # Rutina principal del juego
    def play(self):
        self.printWelcome()
        finished = False
        name=raw_input()
        self.character=Character(name)
        print self.currentRoom.getLongDescription()
        while not finished:
            command = self.parser.getCommand()
            finished = self.processCommand(command)
        print "Thank you for playing. Good bye."

    # printWelcome: None -> None
    # Muestram en pantalla mensaje de bienvenida y
    # descripcion del lugar de partida
    def printWelcome(self):
        print "Welcome to Lord of the Bracelets!"
        print "LOTB is a new, incredibly awesome adventure game."
        print "Type 'help' if you need help."
        print "First, What's your name?"

    # processCommand: str -> bool
    # procesa accion de command, devuelve valor de variable wantToQuit
    def processCommand(self, command):

        wantToQuit = False

        # command unknown
        if command.isUnknown():
            print "I don't know what you mean"
            return False

        # process command
        commandWord = command.getCommandWord()
        if commandWord == "help":
            self.printHelp()
        elif commandWord == "go":
            self.goRoom(command)
        elif commandWord == "quit":
            wantToQuit = self.quit(command)
        elif commandWord== "look":
            self.look()
        elif commandWord== "take":
            self.take(command)
        elif commandWord== "inventory":
            self.inventory()
        elif commandWord== "attack":
            wantToQuit=self.attack()
        elif commandWord=="equip":
            self.equip(command)
        elif commandWord=="throw":
            wantToQuit=self.throw(command)
        elif commandWord=="health":
            self.health()
        # return value of wantToQuit
        return wantToQuit

    # printHelp: None -> None
    # muestra en pantalla un mensaje de ayuda para el jugador
    def printHelp(self):
        print "You are lost. You are alone. You wander"
        print "around in the kingdom"
        print "Your command words are:"
        self.parser.showCommands();
 
    # goRoom: str -> None
    # efecto: modifica currentRoom de acuerdo al movimiento que
    # realiza el jugador, indicado en command
    # muestra mensaje que no pudo moverse o al lugar donde llego
    # el jugador, ademas aumenta el HP en 10 cada vez que llega a un nuevo Room
    def goRoom(self, command):
        # case: command has no second word
        if not command.hasSecondWord():
            print "Go where?"
        else:
            direction = command.getSecondWord()
            nextRoom = self.currentRoom.getExit(direction)
            if nextRoom == None:
                print "There is no door"
            else:
                self.currentRoom = nextRoom
                print self.currentRoom.getLongDescription()
                if self.character.getmaxHP()<self.character.getHP()+10:
                        self.character.setHP(self.character.getmaxHP())
                else:
                    self.character.setHP(self.character.getHP()+10)
                if self.currentRoom.hasEnemy():
                    print "A dangerous "+self.currentRoom.getEnemy().getName()+" is here!"
    # look : None -> None
    #entrega una descripcion del Room actual, ademas
    # dice que objetos se encuentran en el Room
    def look(self):
        room=self.currentRoom
        print room.description
        s=self.currentRoom.getItems()
        if s!=[]:
            s=str(s)
            s=s[1:-1]
            print "The items here are:",s
        else:
            print "There are none items here"
    #inventory: None -> None
    # imprime los items que se encuentran en el inventario del Character
    def inventory(self):
        s=self.character.getInventory()
        if s==[]:
            print "You have none items in your inventory"
        else:
            print "Your items are:"
            for it in s:
                print it.getName()
    # take: str -> None
    # toma un item del Room, si es un arma lo equipa automaticamente
    def take(self,command):
        if not command.hasSecondWord():
            print "Take what?"
        else:
            it = command.getSecondWord()
            if it == None:
                print "There is no item"
            else:
                items=self.currentRoom.getItems()
                count=0
                for i in items:
                    if i.getName()==it:
                        count+=1
                        self.currentRoom.removeItem(i)
                        self.character.addItem(i)
                        if i.tipo=="weapon":
                            self.equip(Command("equip",i.getName()))
                if count==0:
                    print "There is no item with that name"
                s=self.currentRoom.getItems()
                if s!=[]:
                    s=str(s)
                    s=s[1:-1]
                    print "The items here are:",s
    # health: None -> None
    # imprime en consola cuanta es la vida actual del Character
    def health(self):
        print "Your HP are",self.character.getHP()
    # attack: None -> Bool
    # ataca al enemigo que se encuentra en el Room
    # ademas retorna un bool dependiendo si el jugador
    # perdio o no la partida
    def attack(self):
        if not self.currentRoom.hasEnemy():
            print "There is no enemy to attack!"
        else:
            print "You attacked the enemy",self.currentRoom.getEnemy().getName()
            if self.character.getWeapon()==None:
                print "You have lost all of your HP"
                self.character.setHP(0)
                return True
            elif self.currentRoom.getEnemy().getName()=="DragonErre" and self.character.getWeapon().getName()!="GoldenSword":
                print "You need to equip the GoldenSword first!"
            else:
                print "You lost",self.currentRoom.getEnemy().getHP()/2
                print "You defeated the enemy",self.currentRoom.getEnemy().getName()
                currentHP=self.character.getHP()
                lostHP=self.currentRoom.getEnemy().getHP()
                self.currentRoom.setEnemy(None)
                if currentHP-lostHP/2<0:
                    print "You have lost all of your HP"
                    self.character.setHP(0)
                    return True
                else:
                    self.character.setHP(currentHP-lostHP/2)
        return False
    # equip: str -> None
    # equipa un arma o una potion para el uso del jugador
    def equip(self,command):
         if not command.hasSecondWord():
            print "Equip what?"
         else:
            weapon=command.getSecondWord()
            currentweapon=self.character.getWeapon()
            items=self.character.getInventory()
            if items==[]:
                print "Your inventory is empty"
            else:
                count=0
                for i in items:
                    if i.getName()==weapon:
                            count+=1
                            self.character.removeItem(i)
                            if weapon=="potion":
                                if self.character.getHP()+10>self.character.getmaxHP():
                                    self.character.setHP(self.character.getmaxHP())
                                else:
                                    self.character.setHP(self.character.getHP()+10)
                                print "You used a potion!, your new HP are",self.character.getHP()
                            else:
                                if currentweapon !=None:
                                    self.character.addItem(currentweapon)
                                self.character.setWeapon(i)
                                print weapon,"equipped!"
                if count==0:
                    print "There is no item with that name"
    #throw: str -> bool
    #tira un objeto en el Room actual
    #ademas retorna un bool dependiendo si el objeto
    #es el MagicBracelet para saber si gano el juego
    def throw(self,command):
        if not command.hasSecondWord():
            print "Throw what?"
        else:
            it = command.getSecondWord()
            if it == None:
                print "There is no item"
            else:
                items=self.character.getInventory()
                count=0
                for i in items:
                    if i.getName()==it:
                        count+=1
                        self.character.removeItem(i)
                        if self.currentRoom.getShortDescription()=="Chaiten Volcano Top":
                            if i.getName()=="MagicBracelet":
                                print "Congratulations",self.character.getName(),"you have saved the Kingdom!"
                                return True
                            else:
                                print "You have to throw the MagicBracelet into the Volcano"
                        else:
                            self.currentRoom.addItem(i)
                if count==0:
                    print "There is no item with that name"
        return False
    # quit: str -> bool
    # devuelve True si command indica salirse del juego
    def quit(self, command):
        if command.hasSecondWord():
            print "Quit what?"
            return False
        else:
            return True

# Programa principal
juego = Game()
juego.play()
