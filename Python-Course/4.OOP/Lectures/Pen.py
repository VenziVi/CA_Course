class Pen:

    def __init__(self, brand, capacity: int, color):
        self.brand = brand
        self.capacity = capacity
        self.color = color

    def __str__(self):
        return f"Pen {self.brand}, {self.color} color and {self.capacity} capacity."

    def write(self):
        if self.capacity == 0:
            return "empty"
        self.capacity -= 1
        return "Something is writen...."


class Person:

    def __init__(self, name):
        self.name = name
        self.pen = Pen
        self.pens = []

    def __str__(self):
        return f"{self.name} has {len(self.pens)} pens."

    def add_pen(self, pen):
        self.pens.append(pen)

    def take_pen(self):
        if self.pens:
            self.pen = self.pens.pop(0)
        else:
            print("There are no pens left!")

    def write_something(self, pen):
        write = pen.write()
        if write == "empty":
            self.take_pen()
        else:
            print(write)


ivan = Person("Ivan")
pen_1 = Pen("Big", "hello", "blue")
pen_2 = Pen("Ast", 4, "black")
pen_3 = Pen("Mvf", 3, "red")

ivan.add_pen(pen_1)
ivan.add_pen(pen_2)
ivan.add_pen(pen_3)

print(ivan)
ivan.take_pen()
print(ivan)
print(ivan.pen)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
print(ivan.pen)
print(ivan)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
print(ivan.pen)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
print(ivan.pen)
ivan.write_something(ivan.pen)
print(ivan.pen)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
ivan.write_something(ivan.pen)
