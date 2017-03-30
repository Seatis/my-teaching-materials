import random

class Dice():

    def __init__(self):
        self.dice = [0, 0, 0, 0, 0, 0]

    def roll(self):
        for i in range(len(self.dice)):
            self.dice[i] = random.randint(1,6)
        return self.dice

    def getCurrent(self, index=None):
        if index != None:
            print('The current state of dice['+str(index)+']: ', self.dice[index])
        else:
            print('The current state of dice: ', self.dice)

    def reroll(self, index=None):
        if index != None:
            self.dice[index] = random.randint(1,6)
        else:
            self.roll()
        return self.dice
