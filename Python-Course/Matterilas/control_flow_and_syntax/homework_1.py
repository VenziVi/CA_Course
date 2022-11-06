import random
from datetime import date


def print_day_of_week():
    """ Use if elif else construction to print the verbose version of weekday. """
    today = date.today()
    weekday = today.weekday()  # Values from 0 - 6

    # Finish the function here


def get_products():
    """ Should fill and return the products list """
    products = []

    for number in range(1, random.randint(100, 1000)):
        # add (number ** 2 - 1) to products if number > 5 and is odd
        pass


def get_random_string():
    string_els = []

    # Using while loop, fill the string_els with 100 random
    # selected letters from the english alphabet
    # Return the string_els as string.
    pass


def print_even_members():
    range_from = random.randint(1, random.choice([100, 200, 300, 400]))
    range_to = range_from + 100
    range_obj = range(range_from, range_to)

    # Use a for loop to iterate over the range_obj
    # Use if statement to print out only even members
    # Stop printing out if you have printed 50 members
