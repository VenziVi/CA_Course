class Person:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name


class Chair:
    def __init__(self):
        self.is_free = True
        self.person = None

    def sit_on(self, name):
        self.person = Person(name)
        self.is_free = False

    def sit_off(self):
        self.person = None
        self.is_free = True


class Table:
    def __init__(self, material, places):
        self.material = material
        self.places = places
        self._seats = {key: Chair() for key in range(1, places + 1)}

    def check_free_space(self, seat_id):
        if self.is_place_valid(seat_id):
            if self._seats[seat_id].is_free:
                return True
            print(f"Chair {seat_id} is not free")
        return False

    def is_table_full(self):
        return all(not seat.is_free for seat in self._seats.values())

    def is_place_valid(self, chair_id):
        return 1 <= chair_id <= len(self._seats)

    def place_person(self, chair_id, client_name):
        if self.is_table_full():
            print("Table is full")
            return

        if self.check_free_space(chair_id):
            self._seats[chair_id].sit_on(client_name)

    def free_place(self, chair_id):
        if self.check_free_space(chair_id):
            print("Place is already free")
            return
        self._seats[chair_id].sit_off()

    def free_places(self):
        return sum(1 for seat in self._seats.values() if seat.is_free)

    def __str__(self):
        return f"Table made of {self.material} has {self.free_places()} places free."


table = Table("wood", 10)

table.place_person(1, "Pesho")
table.place_person(2, "Stamat")
table.place_person(3, "Ivan")
table.place_person(4, "Jane")
table.place_person(6, "nqkoi")

print(table)

# table.free_place(1)
# table.free_place(1)
# print(table)
# table2 = Table("glass", 4)
# table2.place_person(1, "Ivan")
# table2.place_person(2, "Alala")
# table2.place_person(3, "QEQEQ")
# table2.place_person(4, "Ivo")
# print(table2._seats[4].person.name)
