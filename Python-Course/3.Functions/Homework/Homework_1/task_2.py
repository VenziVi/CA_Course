from functools import wraps

# 2. Write decorator login_required that would be used to check if a user is logged, and if not,
# it should print out "Login required", and if user is logged, the decorated function should print
# "Welcome"
# For user you can use {'name': 'User name', 'logged': True / False}

users_data = {"Ivan": "123",
              "Alex": "456",
              "Petar": "789"}


def logged_check(func):
    @wraps(func)
    def wrapper_func(*args):
        if func(*args):
            print("Welcome.")
        else:
            print("Incorrect username or password!")
    return wrapper_func


@logged_check
def login_func():
    """
    check if username exists in user_data
    check if password match with username
    input: user_name
    input: password
    return: True/False
    """
    print("Login required!")
    user_name = input("Enter username: ")
    password = input("Enter password: ")
    logged = False

    if user_name in users_data and users_data[user_name] == password:
        logged = True

    return logged


login_func()
