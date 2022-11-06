from colorama import Fore, Style


class Pen:
    def __init__(self, brand: str, capacity: int, color: str):
        self.brand = brand
        self.capacity = capacity
        self.color = color.upper()

    def write(self, string):
        if len(string) > self.capacity:
            print("Not enough ink")
            return

        self.capacity -= len(string)
        self.color_printer(self.color, string)

    @staticmethod
    def color_printer(color, text):
        try:
            r, g, b = COLORS[color]
            print(f"\033[38;2;{r};{g};{b}m{text} \033[38;2;255;255;255m")
        except KeyError:
            print(text)

    def __str__(self):
        return f"I am {self.color} color pen. I have ink for {self.capacity} more chars"


class Person:
    def __init__(self, name):
        self.name = name
        self.pens = []
        self.selected_pen = None

    def add_pen(self, *pen_objects: Pen):
        for pen in pen_objects:
            self.pens.append(pen)

    def take_pen(self, pen_id):
        try:
            self.selected_pen = self.pens[pen_id]
        except IndexError:
            print(f"{Fore.RED}Invalid pen_id or no pens added{Style.RESET_ALL}")

    def write_something(self, string):
        if self.selected_pen is None:
            print(f"Select pen first. {len(self.pens)} pens available")
            return

        self.selected_pen.write(string)

    def __str__(self):
        string = f"I am {self.name}. I have {len(self.pens)} pens."
        return string


if __name__ == "__main__":
    PEN_MAKES = ["Mont Blanc", "Cross", "Parker", "Reynolds", "NoName"]
    COLORS = {
        "YELLOW": (255, 255, 0),
        "RED": (255, 0, 0),
        "GREEN": (0, 255, 0),
        "BLUE": (0, 0, 255),
    }

    person = Person("Jack")
    pen1 = Pen(PEN_MAKES[0], 77, "yellow")
    pen2 = Pen(PEN_MAKES[1], 55, "Blue")
    pen3 = Pen(PEN_MAKES[2], 65, "green")
    person.add_pen(pen1, pen2, pen3)

    person.take_pen(0)
    person.write_something(
        "I've been to hell and back, and back to hell, and back, and now back again"
    )
    person.take_pen(1)
    person.write_something("There's more of me, but less to see.")
    person.take_pen(2)
    person.write_something("Taz'dingo")

    for penn in person.pens:
        print(penn)
