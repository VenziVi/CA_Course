class Contact:
    """
    represent mobile phone contact

    attributes:
    name: str
        name of contact
    number: str
        phone number
    calls: int
        the number of times this contact has been called
    """
    def __init__(self, name: str, number: str):
        self.name = name
        self.number = number
        self.__calls = 0

    def __str__(self):
        return f"{self.name} - {self.number}: {self.__calls} calls."

    def print_short_info(self):
        return f"{self.name} - {self.number}"

    def increase_calls(self):
        """
        increase self.__calls with 1 when called
        """
        self.__calls += 1

    def __eq__(self, other):
        """
        compare two strings to lower case
        :param other:
        :return Bool:
        """
        return self.name.lower() == other.lower()

    @classmethod
    def create_contact(cls, name, number):
        """
        Creates and returns instance of class Contact
        if number contains only digits and name is min 3 characters long.
        :param name:
        :param number:
        :return Contact:
        """
        if not number.isdigit():
            return "Number must contains only digits!"
        if len(name) < 3:
            return "Contact name must be min 3 characters long!"

        return cls(name, number)
