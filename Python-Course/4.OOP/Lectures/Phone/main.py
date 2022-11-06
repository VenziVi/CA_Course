from Mobile_phone import MobilePhone
from Contact import Contact

ASK_FOR_NAME_MSG = "Enter contact name: "


def print_menu():
    print("\nPress: ")
    print("    1 -- add contact.")
    print("    2 -- call somebody.")
    print("    3 -- delete contact.")
    print("    4 -- print phone info.")
    print("    5 -- lock the phone.")


def add_new_contact(my_phone):
    """
    Create new contact in the mobile phone if input data is correct
    :param my_phone:
    """
    name = input(ASK_FOR_NAME_MSG)
    number = input("Enter phone number: ")
    new_contact = Contact.create_contact(name, number)

    if isinstance(new_contact, Contact):
        print(my_phone.add_contact(Contact.create_contact(name, number)))
    else:
        print(new_contact)


def calling_contact(my_phone):
    """
    calls the contact with input name from my_phone contacts
    :param my_phone:
    """
    contact_name = input(ASK_FOR_NAME_MSG)
    print(my_phone.call_number(contact_name))


def delete_contact(my_phone):
    """
    delete the contact with input name from my_phone contacts
    :param my_phone:
    """
    contact_name = input(ASK_FOR_NAME_MSG)
    print(my_phone.delete_contact(contact_name))


def print_phone_info(my_phone):
    """
    print phone info and contacts
    :param my_phone:
    """
    my_phone.print_info()


def start_phone():
    my_phone = MobilePhone("IPhone", "XS", 2018)

    while True:
        print_menu()
        command = input()

        if command == "1":
            add_new_contact(my_phone)
        elif command == "2":
            calling_contact(my_phone)
        elif command == "3":
            delete_contact(my_phone)
        elif command == "4":
            print_phone_info(my_phone)
        elif command == "5":
            break
        else:
            print("Invalid command!")

    print("Phone is locked....")


if __name__ == "__main__":
    start_phone()