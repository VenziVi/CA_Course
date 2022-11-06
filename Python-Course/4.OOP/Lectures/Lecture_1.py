import math


class Person:
    def __init__(self, age, height, weight, name):
        self.age = age
        self.height = height
        self.weight = weight
        self.name = name

    def __str__(self):
        return f"{self.name} {self.age} {self.is_in_legal_age}"

    @property
    def is_in_legal_age(self):
        return self.age >= 18

    def breathing(self):
        print("still breathing.....")


venci = Person(35, 176, 74, "Venci")

print(venci.age)

print(venci)

venci.breathing()

print("--------------------------------------------")

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"{self.x} {self.y}"

    def move(self, x, y):
        self.x = x
        self.y = y

    def reset(self):
        self.move(0, 0)

    def calc_distance(self, z):
        return math.hypot(self.x, self.y, z.x, z.y)


a = Point(4, 2)
b = Point(7, 6)

print(a)
print(a.calc_distance(b))

a.move(33, 55)
print(a)

a.reset()
print(a)
