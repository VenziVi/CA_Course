class Contact:

    def __init__(self, name, number):
        self.name = name
        self.number = number
        self.__calls = 0

    def __str__(self):
        return f"{self.name} - {self.number}: {self.__calls} calls."

    def print_short_info(self):
        return f"{self.name} - {self.number}"

    def increase_calls(self):
        self.__calls += 1

class MobilePhone:

    def __init__(self, brand, model, year):
        self.__brand = brand
        self.__year = year
        self.__model = model
        self.contacts = {}

    def __str__(self):
        return f"Phone {self.__brand} model {self.__model} from {self.__year} year."

    def add_contact(self, contact):
        if self.contacts.get(contact.number):
            print(f"Contact: {contact.print_short_info()} already exists!")
        else:
            self.contacts[contact.number] = contact
            print(f"Contact: {contact.print_short_info()} is saved.")

    def delete_contact(self, contact):
        if self.contacts.get(contact.number):
            del(self.contacts[contact.number])
            print(f"Contact: {contact.print_short_info()} was deleted.")
        else:
            print(f"Contact: {contact.print_short_info()} doesn't exists!")

    def call_number(self, contact):
        if not self.contacts.get(contact.number):
            print(f"Contact: {contact.print_short_info()} doesn't exists!")
        else:
            contact.increase_calls()
            print(f"Calling {contact.name}...")

    def print_contacts(self):
        for contact in self.contacts:
            print(f"{self.contacts[contact]}")


contact_1 = Contact("Ivan", "0897 123 548")
contact_2 = Contact("Alex", "0879 256 358")
contact_3 = Contact("Petar", "0888 336 663")

contact_4 = Contact("Unknown", "0877 256 652")

my_phone = MobilePhone("IPhone", "XS", 2018)
my_phone.add_contact(contact_1)
my_phone.add_contact(contact_2)
my_phone.add_contact(contact_3)
my_phone.add_contact(contact_3)

my_phone.print_contacts()

my_phone.call_number(contact_1)
my_phone.call_number(contact_2)
my_phone.call_number(contact_1)
my_phone.call_number(contact_3)
my_phone.call_number(contact_4)

my_phone.print_contacts()

my_phone.delete_contact(contact_2)
my_phone.delete_contact(contact_4)

my_phone.print_contacts()
