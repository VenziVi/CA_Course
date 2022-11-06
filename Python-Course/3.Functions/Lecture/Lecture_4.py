from functools import wraps


def pre_tag(func):
    @wraps(func)
    def wrapper_func(*args):
        func_result = func(*args)
        return f'<pre>{func_result}</pre>'
    return wrapper_func


def bold(func):
    @wraps(func)
    def wrapper_func(*args):
        func_result = func(*args)
        return f'<b>{func_result}</b>'
    return wrapper_func


@pre_tag
@bold
def print_name(name):
    return name


print(print_name("Alex"))



