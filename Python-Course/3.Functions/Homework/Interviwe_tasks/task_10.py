# 10. Write a decorator that would be used on a function that print a random number
# from 1 to 100 and decorators should be repeated n times function.

# Input: print_random_int --> While repeat_decorator(times=5)
# Output: 15, 20, 18, 13, 92

from random import randint


def repeat_decorator(times=5):
    def decorator(func):
        def wrapper_func(*args):
            for _ in range(1, times+1):
                func(*args)
        return wrapper_func
    return decorator


@repeat_decorator()
def print_random_number(a, b):
    print(randint(a, b+1))


print_random_number(1, 100)
