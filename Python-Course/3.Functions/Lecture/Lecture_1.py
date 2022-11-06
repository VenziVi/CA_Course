print("---------------------------------------")

def find_product(x, y):
    return x * y

def minus(x, y):
    return x - y

def plus(x, y):
    return x + y

names_len = []
def check_name_length(name, names_len):
    if len(name) > 5:
        names_len.append("long name")
    else:
        names_len.append("short name")

    return names_len

def power(number, pow):
    number_1 = number
    num = 1

    while num < pow:
        number *= number_1
        num += 1

    return number

print(power(4, 3))

print("---------------------------------------")

def greeting(language):
    if language == "eng":
        return "Hello world"
    elif language == "fr":
        return "Bonjour"
    return "not supported"

def callf(f):
    lang = "eng"
    return f(lang)

print(callf(greeting))

print("---------------------------------------")

lst = [1, 2, 3, 4]
print(list(map(lambda x: x ** 3, lst)))

print(list(filter(lambda x: x < 3, lst)))

print("---------------------------------------")

def map_fn(item):
    return item ** 3

def filter_fn(numbers, map_num):
    result_list = []
    for num in numbers:
        if num < map_num:
            result_list.append(num)

    return result_list

print(filter_fn(lst, 3))

print("---------------------------------------")

words = str.split("The longest word in this sentence")

print(words)

print(sorted(words, key=len))

print("---------------------------------------")

def add_two(x):
    x += 2
    return x

variable_add = add_two
print(variable_add(5))

print("---------------------------------------")

def power_fn(x, y=2):
    number = x
    num = 1

    while num < y:
        number *= x
        num += 1

    return number

print(power_fn(3, y=4))
#print(power_fn(y=4, 3))
print(power_fn(y=3, x=4))

print("---------------------------------------")

def users_lst(main_user, *users):
    print(main_user)

    for user in users:
        print(user)

users_lst("ivan", "Stef", "Pesho", "Gosho")

print("---------------------------------------")

age = 31
passed_ages = [num for num  in range(1, 31)]
future = [32, 33, 42]

def update_ages(age, passed, future):
    age += 1
    passed.append(age)
    future = ([age + x for x in range(1, 4)])
    print(future)

update_ages(age, passed_ages, future)
print(age)
print(passed_ages)
print(future)

print("---------------------------------------")
