from Room import Room
from Character import Character
from Item import Item
class Room_Factory:
      def __init__(self):
            self.buffer={}
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
