from random import randrange
from datetime import date
from functools import wraps

# 1. Write a decorator that would be used on a function that return a number. If today is wednesday,
# friday, or sunday, the function should return the number decreased byt 1.5.


def decrease_number(func):
    @wraps(func)
    def wrapper_func(*args):
        number = func(*args)
        if date.today().weekday() in [2, 4, 6]:
            return number - 1.5
        return number
    return wrapper_func


@decrease_number
def return_number():
    return randrange(0, 100)


print(return_number())
