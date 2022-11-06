class MobilePhone:
    def __init__(self, brand: str, year: int, material: str):
        self.brand = brand
        self.year = year
        self.material = material
        self.__contacts = {}

    def call_number(self, contact_id):
        if contact_id in self.__contacts:
            print(
                f"Calling to {self.__contacts[contact_id].name} - {self.__contacts[contact_id].number}"
            )
            self.__contacts[contact_id].update_times_dialed()
        else:
            print(f"There is no contact_id {contact_id}")

    def add_contact(self, number, name):
        if self.number_exists(number):
            print("Contact already exists")
            return

        contacts_count = len(self.contacts)
        new_contact = Contact(number, name)

        try:
            self.__contacts[contacts_count + 1] = new_contact
        except MemoryError:
            print("Not enough memory")
        else:
            print("Contact Saved")

    def number_exists(self, number):
        return any(number == contact.number for contact in self.__contacts.values())

    @property
    def contacts(self):
        # shallow copy of contacts for user purposes
        return self.__contacts.copy()

    def view_contacts(self):
        for key, contact in self.contacts.items():
            print(key, contact.name, contact.number)

    def __str__(self):
        return f"{self.brand}, {self.year}, {self.material}"


class Contact:
    def __init__(self, number: int, name: str):
        self.number = number
        self.name = name
        self.__times_dialed = 0

    @property
    def times_dialed(self):
        return self.__times_dialed

    def update_times_dialed(self):
        self.__times_dialed += 1

    def __str__(self):
        return f"{self.name} - {self.number}"


phone = MobilePhone("Nokia", 2002, "plastic")
phone.add_contact(12346789, "Pesho")
phone.add_contact(56798123, "Ivan")
phone.add_contact(56798123, "Stoyan")
# print(phone.__contacts[1].times_dialed)
# print(phone.contacts())
phone.contacts[20] = "djsakdsja"

phone.view_contacts()
phone.call_number(1)
phone.call_number(2)
