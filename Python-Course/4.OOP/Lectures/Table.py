class Person:

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"{self.name}"


class Table:

    def __init__(self, material, places):
        self.material = material
        self.__places = places
        self.__seats = {}

    def set_table(self):
        for seat in range(1, self.__places + 1):
            self.__seats[seat] = "empty"

    def validate_seat(self, seat):
        if seat > self.__places:
            return False
        return True

    def place_person(self, person, seat):
        if not self.validate_seat(seat):
            return f"Table have only {self.__places} places!"
        if self.__seats[seat] != "empty":
            return f"Seat number {seat} is taken!"
        else:
            self.__seats[seat] = person
            return f"{person} sit on a seat {seat}"

    def free_place(self, seat):
        if not self.validate_seat(seat):
            return f"Table have only {self.__places} places!"
        if self.__seats[seat] != "empty":
            self.__seats[seat] = "empty"
            return f"Seat {seat} is empty again."
        else:
            return f"Seat {seat} is already empty."

    def free_places_list(self):
        free_seats = []
        for seat in self.__seats:
            if self.__seats[seat] == "empty":
                free_seats.append(seat)
        return free_seats

'''
Ivan = Person("Ivan")
Alex = Person("Alex")
table_1 = Table("wood", 6)
table_1.set_table()
print(table_1.free_places_list())
print(table_1.place_person(Ivan, 4))
print(table_1.free_places_list())
print(table_1.place_person(Alex, 5))
print(table_1.free_places_list())
print(table_1.free_place(4))
print(table_1.free_places_list())
print(table_1.free_place(2))
print(table_1.free_place(9))
print(Ivan)
'''