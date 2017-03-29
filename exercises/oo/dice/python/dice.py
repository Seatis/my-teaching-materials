import random

class Dice():

    def __init__(self):
        self.dices = [0, 0, 0, 0, 0, 0]
        self.current = None

    def roll(self):
        for i in range(len(self.dices)):
            self.dices[i] = random.randint(1,6)
        return self.dices

    def getCurrent(self, index=None):
        if index != None:
            print('The current state of dice['+str(index)+']: ', self.dices[self.current])
        else:
            print('The current state of dices: ', self.dices)

    def reroll(self, index=None):
        self.current = index
        if index != None:
            self.dices[index-1] = random.randint(1,6)
        else:
            self.roll()
        return self.dices
