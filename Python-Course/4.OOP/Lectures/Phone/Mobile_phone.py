class MobilePhone:
    """
    A class to represent mobile phone.

    Attributes:
        brand: str
        year: str
        model: str
        contacts: dict
            key - contact number
            value - contact
    """

    def __init__(self, brand, model, year):
        self.__brand = brand
        self.__year = year
        self.__model = model
        self.__contacts = {}

    def __str__(self):
        return f"Phone {self.__brand} model {self.__model} from {self.__year} year."

    def add_contact(self, contact):
        """
        Check if the given contact number exists in contacts
        if not add the contact in contacts dict
        :param contact:
        :return str:
        """
        if self.__contacts.get(contact.number):
            return f"Contact with number: {contact.number} already exists!"
        else:
            self.__contacts[contact.number] = contact
            return f"Contact: {contact.print_short_info()} is saved."

    def delete_contact(self, contact_name):
        """
        delete contact with current name
        if contact_name exists in contacts dict values
        :param contact_name:
        :return str:
        """
        for contact in self.__contacts.values():
            if contact.__eq__(contact_name):
                name = contact.name
                del(self.__contacts[contact.number])
                return f"Contact: {name} was deleted."
        return f"Contact: {contact_name} doesn't exists!"

    def call_number(self, contact_name):
        """
        Checks if contact with contact_name exists in contacts dict
        If exists increase current contact calls
        :param contact_name:
        :return str:
        """
        for contact in self.__contacts.values():
            if contact.__eq__(contact_name):
                contact.increase_calls()
                return f"Calling {contact.name}: {contact.number}..."
        return f"Contact: {contact_name} doesn't exists!"

    def print_info(self):
        """
        Print phone information and contacts
        """
        print(self.__str__())
        if self.__contacts:
            for contact in self.__contacts:
                print(f"{self.__contacts[contact]}")
        else:
            print("Contact list is empty!")
