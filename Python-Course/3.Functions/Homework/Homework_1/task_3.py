from functools import wraps

# 3. Write a decorator that prints out "Mary Spring" whenever the decorated function is called.


def mary_decorator(func):
    @wraps(func)
    def wrapper_func(*args):
        print(func(*args))
    return wrapper_func


@mary_decorator
def decorated_func():
    return "Mary Spring"


decorated_func()
