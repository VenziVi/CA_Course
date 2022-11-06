import random
import string
from datetime import date


def print_day_of_week():
    """ Use if elif else construction to print the verbose version of weekday. """
    today = date.today()
    weekday = today.weekday()  # Values from 0 - 6

    # Finish the function here

    if weekday == 0:
        day = "Monday"
    elif weekday == 1:
        day = "Tuesday"
    elif weekday == 2:
        day = "Wednesday"
    elif weekday == 3:
        day = "Thursday"
    elif weekday == 4:
        day = "Friday"
    elif weekday == 5:
        day = "Saturday"
    else:
        day = "Sunday"

    print(day)


def get_products():
    """ Should fill and return the products list """
    products = []

    for number in range(1, random.randint(100, 1000)):
        # add (number ** 2 - 1) to products if number > 5 and is odd
        if number > 5 and number % 2 != 0:
            products.append(number ** 2 - 1)

    return products


def get_random_string():
    string_els = []

    # Using while loop, fill the string_els with 100 random
    # selected letters from the english alphabet
    # Return the string_els as string.

    index = 0
    while index < 100:
        string_els.append(random.choice(string.ascii_letters))
        index += 1

    return "".join(string_els)


def print_even_members():
    range_from = random.randint(1, random.choice([100, 200, 300, 400]))
    range_to = range_from + 100
    range_obj = range(range_from, range_to)

    # Use a for loop to iterate over the range_obj
    # Use if statement to print out only even members
    # Stop printing out if you have printed 50 members

    counter = 0
    for num in range_obj:
        if counter >= 50:  # It's ok, but len of range_obj always is 100, then even numbers is 50? default or not?
            break
        if num % 2 == 0:
            print(num)
            counter += 1


print("------------------1.print_day_of_week--------------------------")

print_day_of_week()

print("------------------2.get_products--------------------------")

print(get_products())

print("------------------3.get_random_string--------------------------")

print(get_random_string())

print("------------------4.print_even_members--------------------------")

print_even_members()
